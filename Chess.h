/*
Header file for Othello class
Taylor Bruening
*/
#include<iostream>
#include<cstdlib>
#include<string>
#include<queue>
#include"piece.h"
#include"game.h"
#include"colors.h"

#ifndef OTHELLO_GAME
#define OTHELLO_GAME


class Chess: public main_savitch_14::game{
public:

//PHASE1-2 FUNCTIONS
void display_status() const;

void make_move(const std::string& move);

bool is_legal(const std::string& move) const;

bool is_game_over() const;

void restart();

void victory() const;

//PHASE 3 FUNCTIONS
int evaluate() const;

void compute_moves(std::queue<std::string>& moves) const;

game* clone( ) const;

//FUNCTIONS USED TO TRAVERSE BOARD
bool checker(const string& move) const;

std::string current_color() const;
bool check_pawn_legality(const string& move)const;
bool check_rook_legality(const string& move)const;
bool check_bishop_legality(const string& move)const;
bool check_knight_legality(const string& move)const;
bool check_queen_legality(const string& move)const;
bool check_king_legality(const string& move)const;
//Obstruction functions check if there is a piece in the way
bool pawn_obstruction(const string& move) const;
bool rook_obstruction(const string& move) const;
bool bishop_obstruction(const string& move) const;
bool queen_obstruction(const string& move) const;
bool king_obstruction(const string& move) const;

private:
piece board[8][8];
};

#endif
