all: main

main: main.o distance.o east.o newagent.o north.o south.o west.o
	clang -o main *.o -lm

main.o: main.c
	clang -c main.c

distance.o: distance.c
	clang -c distance.c

east.o: east.c
	clang -c east.c

newagent.o: newagent.c
	clang -c newagent.c
	
north.o: north.c
	clang -c north.c

south.o: south.c 
	clang -c south.c

west.o: west.c
	clang -c west.c

clean:
	rm -f *.o main