CC = clang
CFLAGS = -Ofast -pg

all: a.out

a.out: main.o fib.o long_fib.o big_number.o
	$(CC) $(CFLAGS)  main.o fib.o long_fib.o big_number.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

fib.o: fib.c fib.h
	$(CC) $(CFLAGS) -c fib.c

long_fib.o: long_fib.c long_fib.h
	$(CC) $(CFLAGS) -c long_fib.c

big_number.o: big_number.c big_number.h
	$(CC) $(CFLAGS) -c big_number.c

clean:
	rm -rf gmon.out a.out *.o

format:
	clang-format -i -style=file *.c *.h
