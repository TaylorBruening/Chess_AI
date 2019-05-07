/*

Taylor Bruening
*/
#include <iostream>
#include <cstdlib>
#include <string>
#include <ncurses.h>
#include <vector>
using namespace std;

#ifndef CHESS_GAME
#define CHESS_GAME
class Chess{
	public:
		vector<vector<int> > board_setup();  //Set up board
		vector<vector<int> > setup(vector<vector<int> > &board);
		void draw_top_matrix(vector<vector<int> > &board, int cur_row, int cur_col); //for printing

};




#endif
