parallelCSVsorter: file_finder.o multiProcCSVsorter.o mergesort.o file_handler.o main.o
	gcc file_finder.o file_handler.o mergesort.o multiProcCSVsorter.o main.o -o parallelCSVsorter
file_finder.o: file_finder.h file_finder.c
	gcc -c file_finder.c
multiProcCSVsorter.o: multiProcCSVsorter.h multiProcCSVsorter.c
	gcc -c multiProcCSVsorter.c
mergesort.o: mergesort.h mergesort.c
	gcc -c mergesort.c
file_handler.o: file_handler.h file_handler.c
	gcc -c file_handler.c
main.o: main.c
	gcc -c main.c
clean:
	rm *.o parallelCSVsorter
