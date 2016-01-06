CFLAGS = -Wall
CLIBS = -lglut -lGL -lGLU  -lm

all: main

main: main.o  mes_fonctions.o
	gcc $(CFLAGS) main.o  mes_fonctions.o  libisentlib.a -o main  $(CLIBS)

mes_fonctions.o:	mes_fonctions.c mes_fonctions.h
	gcc $(CFLAGS) -c mes_fonctions.c

main.o:	main.c mes_fonctions.h
	gcc $(CFLAGS) -c main.c
clean:
	rm -f main
	rm -f *.o
