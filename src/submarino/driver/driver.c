#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <asm/uaccess.h>
#include "driver.h"

#define DEVICE_NAME "submarino"

//Prototipo das funcoes

//funcao que e executada ao inserir o modulo
int init_module(void);

//funcao que e executada ao remover o modulo
int device_init(void);
void device_exit(void);
static int device_open(struct inode *, struct file *);
static int device_release(struct inode *, struct file *);
static ssize_t device_read(struct file *, char *, size_t, loff_t *);
static ssize_t device_write(struct file *, const char *, size_t, loff_t *);
long device_ioctl(struct file *, unsigned int, unsigned long);

module_init(device_init);
module_exit(device_exit);

//Define qual funcao vai realizar qual atividade
static struct file_operations fops = {
	.read = device_read,
	.write = device_write,
	.open = device_open,
	.release = device_release,
	.unlocked_ioctl = device_ioctl,
};

//Variaveis globais sao declaras como estaticas
static int device = 60 ;
static int open = 0 ;
static char buffer[BUF_LEN];
static char *rptr ;
static char *wptr ;

//Funcao chamado quando o modulo e carregado

int device_init(){
	//cria o dispositivo
	int ret = register_chrdev(device, DEVICE_NAME, &fops);
	if (ret < 0){
		printk("Nao foi possivel abrir o dispositivo %d.\n", device);
		return ret;
	}
	memset(buffer, 0 , BUF_LEN);
	printk("Dispositivo carrregado.\n");
	return 0;
}

//Remove o dispositivo

void device_exit(){
	unregister_chrdev(device, DEVICE_NAME);
	printk("Dispositivo descarregado.\n");
}

//Chamada quando o processo tenta abir o dispositivo
static int device_open(struct inode *nd, struct file *fd){
	//verifica se ja tem alguem acessando o dispositivo
	if (open) {
		return -EBUSY;
	}
	open++;
	rptr = wptr = buffer;
	try_module_get(THIS_MODULE);
	return 0;
}

//Chamada quando um proceso fecha o arquivo
static int device_release(struct inode *nd, struct file *fp){
	//libera o acesso ao dispositivo
	if (open) {
		open--;
	}
	module_put(THIS_MODULE);
	return 0;
}

//Chamada quando um processo tenta ler o arquivo aberto
static ssize_t device_read(struct file *fp, char *buff, size_t lenght, loff_t *offset){
	int nbytes = strlen(rptr);
	if (nbytes > lenght) {
		nbytes = lenght;
	}
	copy_to_user(buff, rptr, nbytes);
	rptr += nbytes;
	return nbytes;
}

//Chamada quando um processo tenta escrever no arquivo

static ssize_t device_write(struct file *fp, const char *buff, size_t lenght, loff_t *offset){
	int nbytes = BUF_LEN - (wptr - buffer);
	if (nbytes > lenght) {
		nbytes = lenght;
	}
	copy_from_user(wptr, buff, nbytes);
	wptr += nbytes;
	return nbytes;
}

long device_ioctl(struct file *file, unsigned int ioctl_num, unsigned long ioctl_param){
	switch (ioctl_num) {
		case IOCTL_SET_CHAR:
			device_write(file, (char * ) ioctl_param, BUF_LEN, 0);
			break;
		case IOCTL_GET_CHAR:
			device_read(file, (char *) ioctl_param, BUF_LEN, 0);
			break;
		default: return FAILURE;
	}
	return SUCCESS;
}
