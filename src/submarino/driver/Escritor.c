#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "driver.c"

#define DEVICE_NAME "/dev/submarino"
#define BUF_LEN 1

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

		int ret = ioctl(file, IOCTL_SET_CHAR, wrt);

		if (ret < 0) {
                    printf ("Erro de comunicação\n");
                    exit(-1);
                }

		close(file);
	}

  	return 0;
}
