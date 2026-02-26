# CFLAGS will be the options passed to the compiler.
CFLAGS= -c -Wall -Wextra -pedantic

# both "make" and "make all" will build both programs
all: NFL Temp
NFL: NFL-score.o
	gcc NFL-score.o -o NFL

NFL-score.o: NFL-score.c
	gcc $(CFLAGS) NFL-score.c

Temp: temerature-conversion.o
	gcc temerature-conversion.o -o Temp

temerature-conversion.o: temerature-conversion.c
	gcc $(CFLAGS) temerature-conversion.c

# auxiliary functions

runNFL: NFL
	./NFL

runTemp: Temp
	./Temp

# removes any ".o" files
clean:
	rm -rf *.o