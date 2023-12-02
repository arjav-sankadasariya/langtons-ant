#This is a make file 

CC = gcc
CFLAGS = -Wall
OBJ = ant

all:
	$(CC)  $(CFLAGS) random.c color.c newsleep.c main.c -o $(OBJ)
