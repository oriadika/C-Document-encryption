

all: clean compilation linkFile

compilation : bin/main.o bin/numbers.o bin/add.o 

linkFile: gcc -g -m32 -Wall bin/main.o bin/numbers.o bin/add.o -o bin/encoder

bin/main.o: src/main.c
	gcc -m32 -g -Wall -c  src/main.c -o bin/main.o


bin/numbers.o: src/numbers.c
	gcc -m32 -g -Wall -c src/numbers.c -o bin/numbers.o


bin/add.o: src/add.s
	nasm -g -f elf32 -w+all  src/add.s  -o bin/add.o

clean:
	rm -f bin/*
