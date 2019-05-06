/*
Header file for piece class
Taylor Bruening
*/
#include<iostream>
#include<cstdlib>
#include<string>
#include"colors.h"


#ifndef CHESS_PIECE
#define CHESS_PIECE


class piece{
public:

//CONSTRUCTOR
piece()
{empty = true;
color = true;
pawn = false;
queen = false;
king = false;
rook = false;
bishop = false;
knight = false;
value = 0;}

//ACCESSORS
const std::string holder(const std::string& piece_type) const;

const bool emptiness() const;

const std::string has_piece_color() const;

const std::string type() const;

const int piece_value() const
	{return value;}	

//MUTATORS
	//Set black pieces
void set_black_pawn()
	{color = true; empty = false; rook = false; pawn = true; queen = false; king = false; bishop = false; knight = false; value = 1;}
void set_black_queen()
	{color = true; empty = false; rook = false; pawn = false; queen = true; king = false; bishop = false; knight = false;; value = 9;}
void set_black_king()
	{color = true; empty = false; rook = false; pawn = false; queen = false; king = true; bishop = false; knight = false;; value = 10;}
void set_black_bishop()
	{color = true; empty = false; rook = false; pawn = false; queen = false; king = false; bishop = true; knight = false; value = 3;}
void set_black_knight()
	{color = true; empty = false; rook = false; pawn = false; queen = false; king = false; bishop = false; knight = true; value = 3;}
void set_black_rook()
	{color = true; empty = false; rook = true; pawn = false; queen = false; king = false; bishop = false; knight = false; value = 5;}

	//Set white pieces
void set_white_rook()
	{color = false; empty = false; rook = true; pawn = false; queen = false; king = false; bishop = false; knight = false; value = 5;}
void set_white_knight()
	{color = false; empty = false; rook = false; pawn = false; queen = false; king = false; bishop = false; knight = true; value = 3;}
void set_white_pawn()
	{color = false; empty = false; rook = false; pawn = true; queen = false; king = false; bishop = false; knight = false; value = 1;}
void set_white_queen()
	{color = false; empty = false; rook = false; pawn = false; queen = true; king = false; bishop = false; knight = false; value = 9;}
void set_white_king()
	{color = false; empty = false; rook = false; pawn = false; queen = false; king = true; bishop = false; knight = false; value = 10;}
void set_white_bishop()
	{color = false; empty = false; rook = false; pawn = false; queen = false; king = false; bishop = true; knight = false; value = 3;}
	//Clear piece
void set_as_empty()
{empty = true;
pawn = false;
queen = false;
king = false;
rook = false;
bishop = false;
knight = false;
value = 0;}

private:
bool empty;
bool color;
bool pawn;
bool rook;
bool knight;
bool bishop;
bool queen;
bool king;
int value;
};

#endif
