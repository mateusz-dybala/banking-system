all: bank

bank: main.o bank.o menus.o validity.o
	gcc -g $^ -o $@

.c.o:
	gcc -g -Wall -pedantic -c $<

main.o: main.c

bank.o: bank.c

menus.o: menus.c menus.h

validity.o: validity.c

clean:
	-rm main.o bank.o menus.o validity.o bank
