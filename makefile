#makefile for Chess game

all: Chess clean

Chess: Chess.o main.o
	g++ -o Chess Chess.o main.o -lncursesw

Chess.o: Chess.h Chess.cc
	g++ -c Chess.cc -lncursesw

main.o: main.cc
	g++ -c main.cc

clean :
	rm -f *.o a.out
