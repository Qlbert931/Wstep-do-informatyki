all: main

main: main.o wczytaj.o phi.o
	clang -o main *.o -lm

main.o: main.c
	clang -c main.c

wczytaj.o: wczytaj.c
	clang -c wczytaj.c

phi.o: phi.c
	clang -c phi.c

clean:
	rm -f *.o main