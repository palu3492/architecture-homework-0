CC=gcc

all: mycat.o
	$(CC) mycat.o -o mycat -lm
	
mycat: mycat.c
	$(CC) -c mycat.c
	
clean:
	rm mycat.o mycat
