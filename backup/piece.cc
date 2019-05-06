/*
implementation file for piece class
Taylor Bruening
*/
#include<iostream>
#include<cstdlib>
#include<string>
#include"piece.h"

using namespace std;

const string piece::type() const{
if(pawn==true)
	{return "pawn";}
if(rook==true)
	{return "rook";}
if(bishop==true)
	{return "bishop";}
if(queen==true)
	{return "queen";}
if(king==true)
	{return "king";}
if(knight==true)
	{return "knight";}
}


/* 
Pawn - 1 point
Knight - 3 point
Bishop - 3 point
Rook - 5 point
Queen 9 point
*/
const string piece::holder(const string& piece_type) const{
  string x = "   ";
  string holder;
if(piece_type == "pawn")
	holder = " \u265F "; //Pawn
if(piece_type == "knight")
	holder = " \u265E "; //Knight
if(piece_type == "bishop")
	holder = " \u265D "; //Bishop
if(piece_type == "rook")
	holder = " \u265C "; //Rook
if(piece_type == "queen")
	holder = " \u265B "; //Queen
if(piece_type == "king")
	holder = " \u265A "; //King
if(empty==true)
	{return x;}

else
	{return holder;}
}

const bool piece::emptiness() const{
  if(empty == true)
	{return true;}
  else
	{return false;}
}

const string piece::has_piece_color() const{
  if((empty == false)&&(color == true))
	{return "black";}
  if((empty == false)&&(color == false))
	{return "white";}
  else
	{return "empty";}
}

