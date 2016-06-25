#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#define DEVICE_NAME "/dev/submarino"      
#define BUF_LEN 10

int main(void) {
	char value;
	char wrt[BUF_LEN];

	while (1) {
		printf("Próximo movimento: "); 
		scanf("%s", wrt);

		int file = open(DEVICE_NAME, O_RDWR);

		if (file < 0) {
		      printf("Erro ao abrir o device!!!\n");
		      exit(-1);
		}

		write(file, wrt, BUF_LEN);
		close(file);
	}
  
  	return 0;  
}