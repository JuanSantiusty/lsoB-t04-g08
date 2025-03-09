##Variables
CFLAGS=-Wall -g
CC=gcc
TARGET=listar

##Directiva principal
all: $(TARGET)

$(TARGET): principal.o listar.o
	$(CC) $(CFLAGS) -o $(TARGET) principal.o listar.o

##Actividades
principal.o:principal.c listar.h
	$(CC) $(CFLAGS) -c principal.o principal.c

listar.o:principal.c listar.h
	$(CC) $(CFLAGS) -c listar.c

##Directivas phony
clear:
	rm -f principal.o listar.o $(TARGET)
