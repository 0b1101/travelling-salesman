CFLAGS = -std=c99 -pedantic-errors -Wall -lm

all: functions.o info-list.o info-it.o mov-list.o mov-it.o main.o
	gcc functions.o info-list.o info-it.o mov-list.o mov-it.o main.o -o run $(CFLAGS);./run

functions.o:
	gcc -c ./functions/functions.c $(CFLAGS) -I/functions -o functions.o

main.o:
	gcc -c main.c $(CFLAGS) -o main.o

info-list.o:
	gcc -c ./info-list/info-list.c $(CFLAGS) -I/info-list -o info-list.o

info-it.o:
	gcc -c ./info-list/info-it/info-it.c $(CFLAGS) -I/info-list/info-it -o info-it.o

mov-list.o:
	gcc -c ./mov-list/mov-list.c $(CFLAGS) -I/mov-list -o mov-list.o

mov-it.o:
	gcc -c ./mov-list/mov-it/mov-it.c $(CFLAGS) -I/mov-list/mov-it -o mov-it.o

run:
	./run

clean:
	rm *.o *.zip run
