simpleCSVsorter: simpleCSVsorter.o file_handler.o mergesort.o unitest.o main.o
	gcc simpleCSVsorter.o file_handler.o mergesort.o unitest.o main.o -o simpleCSVsorter
simpleCSVsorter.o: simpleCSVsorter.h simpleCSVsorter.c
	@gcc -c simpleCSVsorter.c
unitest.o: unitest.h unitest.c
		@gcc -c unitest.c
mergesort.o: mergesort.h mergesort.c
	@gcc -c mergesort.c
file_handler.o: file_handler.h file_handler.c
	@gcc -c file_handler.c
main.o: main.c
	@gcc -c main.c
clean:
	@rm *.o simpleCSVsorter
info:
	@cat readme.txt
