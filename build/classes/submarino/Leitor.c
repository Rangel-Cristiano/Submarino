#include <stdlib.h>
#include <fcntl.h>
#include <jni.h>
#include "Leitor.h"
#include <stdio.h>

#define DEVICE_NAME "/dev/submarino"      
#define BUF_LEN 10

JNIEXPORT jstring JNICALL
Java_Submarino_getChar(JNIEnv *env, jobject obj) {
    char rd[BUF_LEN];

    int file = open(DEVICE_NAME, O_RDWR);

    if (file < 0) {
          printf("Erro ao abrir o device!!!\n");
          exit(-1);
    }

    read(file, rd, BUF_LEN);          
    close(file);

    return (*env)->NewStringUTF(env,rd);;
}
