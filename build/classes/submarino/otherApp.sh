#!/bin/bash

cd /home/mfeijo/Documents/UCS/Sistemas_operacionais/trabalho_final/Submarino/src/submarino/driver
export LD_LIBRARY_PATH=.
javac Escritor.java
javah -jni Escritor
java Escritor
