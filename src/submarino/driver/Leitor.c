#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <jni.h>
#include "Leitor.h"
#include "driver.h"
#include <sys/ioctl.h>
#include <string.h>

#define DEVICE_NAME "/dev/submarino"
#define BUF_LEN_SUB 2

JNIEXPORT jstring JNICALL
Java_submarino_GameView_getChar(JNIEnv *env, jobject obj) {
    char rd[BUF_LEN_SUB];

    int file = open(DEVICE_NAME, O_RDWR);

    if (file < 0){
        printf("Erro ao abrir device\n");
        exit(-1);
    }

    ioctl(file, IOCTL_GET_CHAR, rd);
    if (strlen(rd) > 0) { 
        const char *clean = "\0";
        ioctl(file, IOCTL_SET_CHAR, clean);
    }
    close(file);

    return (*env)->NewStringUTF(env,rd);
}

JNIEXPORT void JNICALL
Java_Escritor_setChar(JNIEnv *env, jobject obj, jstring text) {
    const char *nativeString = (*env)->GetStringUTFChars(env, text, 0);

    int file = open(DEVICE_NAME, O_RDWR);

    if (file < 0){
        printf("Erro ao abrir device\n");
        exit(-1);
    }

    ioctl(file, IOCTL_SET_CHAR, nativeString);
    close(file);
    (*env)->ReleaseStringUTFChars(env, text, nativeString);
}
