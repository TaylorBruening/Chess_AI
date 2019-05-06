#makefile for Chess game

all: Chess clean

Chess: piece.o Chess.o game.o main.o
	g++ -o Chess piece.o Chess.o game.o main.o

game.o: game.h game.cc
	g++ -c game.cc

piece.o: piece.h piece.cc
	g++ -c piece.cc

Chess.o: Chess.h Chess.cc
	g++ -c Chess.cc

main.o: main.cc
	g++ -c main.cc

doc:
	doxygen Doxyfile
	rm -r latex/
clean :
	rm -f *.o a.out
