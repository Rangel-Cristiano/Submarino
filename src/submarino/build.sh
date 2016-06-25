#!/bin/bash

javac Submarino.java
cd ..
javah -jni submarino.Submarino
cd submarino
gcc -fPIC -I/usr/lib/jvm/java-7-openjdk-amd64/include -I/usr/lib/jvm/java-7-openjdk-amd64/include/linux -shared -o libleitor.so Leitor.c

sudo rmmod driver.ko
sudo rm /dev/submarino

cd driver
make
sudo mknod /dev/submarino c 60 0
sudo chmod 666 /dev/submarino
sudo insmod driver.ko