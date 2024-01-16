# simple makefile

CFLAGS = -g -Wall

all: program1 program2 program3

program1: char.c
	gcc $(CFLAGS) -o char char.c

program2: count.c
	gcc $(CFLAGS) -o count count.c

program3: digits.c
	gcc $(CFLAGS) -o digits digits.c

clean:
	rm char count digits
