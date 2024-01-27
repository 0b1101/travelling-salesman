CFLAGS = -std=c99 -pedantic-errors -Wall -lm

all: functions.o item.o list.o main.o 
	gcc functions.o item.o list.o main.o -o execute $(CFLAGS);./execute

functions.o:
	gcc -c ./functions/functions.c -I/functions -o functions.o

list.o:
	gcc -c ./linked-list/linked-list.c $(CFLAGS) -I/linked-list -o list.o

main.o:
	gcc -c main.c $(CFLAGS) -I/ -o main.o

item.o:
	gcc -c ./linked-list/item/item.c $(CFLAGS) -I./linked-list/item/ -o item.o

run:
	./execute

clean:
	rm *.o *.zip execute
