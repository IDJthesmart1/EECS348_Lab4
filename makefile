# CFLAGS will be the options passed to the compiler.
CFLAGS= -c -Wall -Wextra -pedantic

# either "make", "make all", or "make prog" will build the program
all: prog
prog: main.o
	gcc main.o -o prog
	./prog

main.o: main.c
	gcc $(CFLAGS) main.c

# auxiliary functions

run: prog
	./prog

# removes any ".o" files
clean:
	rm -rf *.o