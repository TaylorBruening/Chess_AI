#makefile for Chess game

all: Chess clean

Chess: Chess.o main.o
	g++ -std=c++11 -o Chess Chess.o main.o -lncursesw

Chess.o: Chess.h Chess.cc
	g++ -std=c++11 -c Chess.cc -lncursesw

main.o: main.cc
	g++ -std=c++11 -c main.cc

clean :
	rm -f *.o a.out
