/*
implementation file for Chess class
Taylor Bruening

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

*/

#include<iostream>
#include<cstdlib>
#include"Chess.h"
#include<string>
#include <ncurses.h>
#include <vector>
#include <locale.h>
using namespace std;

#define WHITE_PAWN "\u2659" //10
#define WHITE_KNIGHT "\u2658" //11
#define WHITE_BISHOP "\u2657" //12
#define WHITE_ROOK "\u2656" //13
#define WHITE_QUEEN "\u2655" //14
#define WHITE_KING "\u2654" //15

#define BLACK_PAWN "\u265F" //20
#define BLACK_KNIGHT "\u265E" //21
#define BLACK_BISHOP "\u265D" //22
#define BLACK_ROOK "\u265C" //23
#define BLACK_QUEEN "\u265B" //24
#define BLACK_KING "\u265A" //25

//***************************************************************
// Function:  draw_top_matrix
// Parameters: board, self_board, cur_row, cur_col, attacking
// Purpose:  deals with dynamic screen printing during board setup and attacking
//****************************************************************
void Chess::draw_top_matrix(vector<vector<int> > &board, 
		     int cur_row,
		     int cur_col) {

//This section will print the "enemy board" or your board if it is during board setup func
/*
  for (int j=0;j<8;j++) {
      move(0,2*j);
      printw("+-");
    }
    move(0,2*8);
    printw("+");
*/
  for (int i=0;i<8;i++) {
    for (int j=0;j<8;j++) {
      //move(2*i+1,2*j);
      //printw("|");
      move(2*i+1,2*j+1);
	if((i%2 == 0 && j%2 != 0) || (i%2 == 1 && j%2 == 0))
		{attron(COLOR_PAIR(1));}
	if((i % 2 == 1 && j%2 != 0)|| (i%2 == 0 && j%2 == 0))
		{attron(COLOR_PAIR(2));}

      if (board[i][j] == 0) {
		printw(" ");
      	}
	  else if(board[j][i] == 10) {
		printw(WHITE_PAWN);
	  	}
	  else if(board[j][i] == 11) {
		printw(WHITE_KNIGHT);
	  	}
	  else if(board[j][i] == 12) {
		printw(WHITE_BISHOP);
	  	}
	  else if(board[j][i] == 13) {
		printw(WHITE_ROOK);
	  	}
	  else if(board[j][i] == 14) {
		printw(WHITE_QUEEN);
	  	}
	  else if(board[j][i] == 15) {
		printw(WHITE_KING);
	  	}

	  else if(board[j][i] == 20) {
		printw(BLACK_PAWN);
	  	}
	  else if(board[j][i] == 21) {
		printw(BLACK_KNIGHT);
	  	}
	  else if(board[j][i] == 22) {
	printw(BLACK_BISHOP);
	  }
	  else if(board[j][i] == 23) {
		printw(BLACK_ROOK);
	  	}
	  else if(board[j][i] == 24) {
		printw(BLACK_QUEEN);
	  	}
	  else if(board[j][i] == 25) {
		printw(BLACK_KING);
	  	}
	 else {
	//attron(COLOR_PAIR(1));
		printw(" ");
	//attroff(COLOR_PAIR(1));
      	}
	attroff(COLOR_PAIR(1));
	attroff(COLOR_PAIR(2));
    }
	/*
    move(2*i+1,2*8);
    printw("|");
    for (int j=0;j<8;j++) {
      move(2*i+2,2*j);
      printw("+-");
    }
    move(2*i+2,2*8);
    printw("+");
	*/
  }

  move(2*cur_row+1,2*cur_col+1);
}


vector<vector<int> > Chess::board_setup() {
  vector<vector<int> > board;

  //initialize the board to all 1's
  for (int i=0;i<8;i++) {
    vector<int> t;
    for (int j=0;j<8;j++) {
      t.push_back(1);
    }
    board.push_back(t);
  }

board[0][7] = 13; //set white rook
board[1][7] = 11; //set white knight
board[2][7] = 12; //set white bishop
board[3][7] = 14; //set white queen
board[4][7] = 15; //set white king
board[5][7] = 12; //set white bishop
board[6][7] = 11; //set white knight
board[7][7] = 13; //set white rook

//set white pawns
for(int c = 0;c<8;c++)
	{board[c][6] = 10;}


board[0][0] = 23; //set black rook
board[1][0] = 21; //set black knight
board[2][0] = 22; //set black bishop
board[3][0] = 24; //set black queen
board[4][0] = 25; //set black king
board[5][0] = 22; //set black bishop
board[6][0] = 21; //set black knight
board[7][0] = 23; //set black rook
	//set black pawns
for(int c = 0;c<8;c++)
	{board[c][1] = 20;}



board = setup(board);
return board;
}
//***************************************************************
// Function:  board_setup
// Returns: board
// Purpose:  set up/position your battleship
//****************************************************************
void move_piece(vector<vector<int> >& board) {

}

//***************************************************************
// Function:  board_setup
// Returns: board
// Purpose:  set up/position your battleship
//****************************************************************
vector<vector<int> > Chess::setup(vector<vector<int> >& board) {
  int rows;
  int cols;
  int cur_row=4;
  int cur_col=3;
  int ch;
  string angle = "horizontal";
  int selected_row = 0;
  int selected_col = 0;

  setlocale(LC_ALL, "");
  initscr();
  clear();
  getmaxyx(stdscr,rows,cols);
  cbreak();
  keypad(stdscr, TRUE);

 
    start_color();
   	init_pair(1, COLOR_BLACK, COLOR_RED);
   	init_pair(2, COLOR_BLACK, COLOR_CYAN);
    //attron(COLOR_PAIR(1));


  refresh();
  draw_top_matrix(board, cur_row, cur_col);

  
  while ((ch = getch())!='\n') {
    switch (ch) {
	case ' ':
		selected_row = cur_row;
		selected_col = cur_col;
      draw_top_matrix(board,cur_row,cur_col);
      refresh();

      break;

    case KEY_RIGHT:
	  //if((cur_col+1 < 3) || ((cur_col < 3) && angle == "vertical"))
	 	 //{move_piece(board, "right", cur_col);}
      cur_col++;
      cur_col%=8;
      draw_top_matrix(board,cur_row,cur_col);
      // Redraw the screen.
      refresh();
      break;
    case KEY_LEFT:
      cur_col--;
      cur_col = (8+cur_col)%8;
      draw_top_matrix(board,cur_row,cur_col);
      // Redraw the screen.
      refresh();
      break;
    case KEY_UP:
      cur_row--;
      cur_row=(8+cur_row) % 8;
      draw_top_matrix(board,cur_row,cur_col);
      
      //      paint_markers(rows,cols,10,cur_row,cur_col);
      // Redraw the screen.
      refresh();
      break;
    case KEY_DOWN:
      cur_row++;
      cur_row%=8;
      draw_top_matrix(board,cur_row,cur_col);
            //paint_markers(rows,cols,10,cur_row,cur_col);
      // Redraw the screen.
      refresh();
      break;
    }

  }
endwin();
return board;

}

