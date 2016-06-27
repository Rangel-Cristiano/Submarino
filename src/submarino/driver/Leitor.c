#include <stdlib.h>
#include <stdio.h>  
#include <fcntl.h>
#include <jni.h>
#include "Leitor.h"
#include "driver.h"
#include <sys/ioctl.h>

#define DEVICE_NAME "/dev/submarino"      
#define BUF_LEN_SUB 1

JNIEXPORT jstring JNICALL
Java_submarino_Game_getChar(JNIEnv *env, jobject obj) {
    char rd[BUF_LEN_SUB];

    int file = open(DEVICE_NAME, O_RDWR);

    if (file < 0){
        printf("Erro ao abrir device\n");
        exit(-1);
    }

    ioctl(file, IOCTL_GET_CHAR, rd);
    close(file);

    return (*env)->NewStringUTF(env,rd);
}
