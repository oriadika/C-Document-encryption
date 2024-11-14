.PHONY: all

all : clean encoder 

run: encoder
	./encoder

encoder: encoder.c
	gcc -m32 -g -Wall -o encoder encoder.c

# Rule for cleaning up the compiled files
clean:
	rm -f encoder