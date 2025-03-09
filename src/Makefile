##Variables
CFLAGS=-Wall -g
CC=gcc
TARGET=listar

##Directiva principal
all:principal.o
	$(CC) $(CFLAGS)  -o listar principal.o

##Actividades
principal.o:principal.c
	$(CC) -c -o principal.o principal.c

##Directivas phony
clear:
	rm -f principal.o $(TARGET)
