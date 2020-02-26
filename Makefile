CC=gcc

all: myarr.o
	$(CC) myarr.o -o myarr
	
hello: myarr.c
	$(CC) -c myarr.c
	
clean:
	rm myarr.o myarr
