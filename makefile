all: program

program: main.o lista_encad_header.o
	gcc main.o lista_encad_header.o -lm -o program

lista_encad_header.o: lista_encad_header.c lista_encad_header.h
	gcc -c lista_encad_header.c

main.o: main.c lista_encad_header.h
	gcc -c main.c

clear:
	rm -rf *.o program
