/*
implementation file for Chess class
Taylor Bruening
*/

#include<iostream>
#include<cstdlib>
#include"Chess.h"
#include"game.h"
#include"colors.h"
#include"piece.h"
#include<string>
using namespace std;

/*COMPUTE MOVES - Checks every possible move with every piece */
void Chess::compute_moves(std::queue<std::string>& moves) const
{
int move_counter=0;
string tmp = "     ";
for(int j=0;j<8;j++)
	{
	for(int i=0;i<8;i++)
		{
		for(int c=0;c<8;c++)
			{		
			for(int q=0;q<8;q++)
				{
				tmp[0]=char('A' + i);
				tmp[1]=char('1'+ j);
				tmp[3]=char('A' + c);
				tmp[4]=char('1' +q);
				if(is_legal(tmp))		
					{moves.push(tmp);}
				move_counter++;
				}
			}
		}
	}


if(moves.empty()==true)
	{moves.push("xx");}

}

/*CLONE - Creates a copy of the board to make theoretical moves on */
main_savitch_14::game * Chess:: clone() const
{
	return new Chess(*this);
}



/*EVALUATE - Evaluates who is currently winning */
int Chess::evaluate() const
{
int black_counter=0;int white_counter=0;

for(int i=0;i<8;i++)
{
	for(int j=0;j<8;j++)
	{
		if(board[i][j].has_piece_color()=="black")
			{black_counter += board[i][j].piece_value();}
		else if(board[i][j].has_piece_color()=="white")
			{white_counter += board[i][j].piece_value();}
	}
}

int x = -1;
int y = 1;
int z = 0;

if((moves_completed()%2 == 0)&&(black_counter>white_counter))
	{return y;}
else if(black_counter==white_counter)
	{return z;}
else 
	{return x;}

}



/*IS_GAME_OVER - Checks if there are any more available moves */
bool Chess::is_game_over() const
{
int empty_counter=0;
int white_counter=0;
int black_counter=0;
for(int i=0;i<8;i++)
{
	for(int j=0;j<8;j++)
	{
	if(board[i][j].has_piece_color()=="empty")
		{empty_counter++;}
	if(board[i][j].has_piece_color()=="black")
		{black_counter++;}
	else if(board[i][j].has_piece_color()=="white")
		{white_counter++;}
	}
}
if((empty_counter!=0)&&(white_counter!=0)&&(black_counter!=0))
	{return false;}
else
	{return true;}
}



/*DISPLAY STATUS - Prints the board to the terminal */
void Chess::display_status() const
{
int i=0; int j=0;
cout<<"  A  B  C  D  E  F  G  H"<<endl;
while(j<8)
{
cout<<j+1;
	if(j%2==0)
	{while(i<8)
		{
	if((board[i][j].has_piece_color())=="black")
		{cout<<B_GREEN<<BLACK<<board[i][j].holder(board[i][j].type());
		i++;}
	else if((board[i][j].has_piece_color())=="white")
		{cout<<B_GREEN<<WHITE<<board[i][j].holder(board[i][j].type());
		i++;}
	else			
		{cout<<B_GREEN<<board[i][j].holder(board[i][j].type());
		i++;}
	if((board[i][j].has_piece_color())=="black")
		{cout<<B_YELLOW<<BLACK<<board[i][j].holder(board[i][j].type());
		i++;}
	else if((board[i][j].has_piece_color())=="white")
		{cout<<B_YELLOW<<WHITE<<board[i][j].holder(board[i][j].type());
		i++;}
	else			
		{cout<<B_YELLOW<<board[i][j].holder(board[i][j].type());
		i++;}
		}
	}

	if(j%2!=0)
	{while(i<8)
		{
	if((board[i][j].has_piece_color())=="black")
		{cout<<B_YELLOW<<BLACK<<board[i][j].holder(board[i][j].type());
		i++;}
	else if((board[i][j].has_piece_color())=="white")
		{cout<<B_YELLOW<<WHITE<<board[i][j].holder(board[i][j].type());
		i++;}
	else			
		{cout<<B_YELLOW<<board[i][j].holder(board[i][j].type());
		i++;}
	if((board[i][j].has_piece_color())=="black")
		{cout<<B_GREEN<<BLACK<<board[i][j].holder(board[i][j].type());
		i++;}
	else if((board[i][j].has_piece_color())=="white")
		{cout<<B_GREEN<<WHITE<<board[i][j].holder(board[i][j].type());
		i++;}
	else			
		{cout<<B_GREEN<<board[i][j].holder(board[i][j].type());
		i++;}
		}
	}
cout<<RESET<<endl;
i=0;
j++;
}

cout<<RESET<<endl;
}



/*MAKE_MOVE - Executes the move */
void Chess::make_move(const std::string& move)
{
int irow, icol, frow, fcol;
frow = int(move[4]-'1');
fcol = int(toupper(move[3])-'A');
irow = int(move[1]-'1');
icol = int(toupper(move[0])-'A');

if(move!="xx")
{

	if(board[icol][irow].type()=="pawn" && current_color()=="white")
		{board[icol][irow].set_as_empty();
		board[fcol][frow].set_white_pawn();}
	else if(board[icol][irow].type()=="pawn" && current_color()=="black")
		{board[icol][irow].set_as_empty();
		board[fcol][frow].set_black_pawn();}
	else if(board[icol][irow].type()=="rook" && current_color()=="black")
		{board[icol][irow].set_as_empty();
		board[fcol][frow].set_black_rook();}
	else if(board[icol][irow].type()=="rook" && current_color()=="white")
		{board[icol][irow].set_as_empty();
		board[fcol][frow].set_white_rook();}
	else if(board[icol][irow].type()=="knight" && current_color()=="black")
		{board[icol][irow].set_as_empty();
		board[fcol][frow].set_black_knight();}
	else if(board[icol][irow].type()=="knight" && current_color()=="white")
		{board[icol][irow].set_as_empty();
		board[fcol][frow].set_white_knight();}
	else if(board[icol][irow].type()=="bishop" && current_color()=="white")
		{board[icol][irow].set_as_empty();
		board[fcol][frow].set_white_bishop();}
	else if(board[icol][irow].type()=="bishop" && current_color()=="black")
		{board[icol][irow].set_as_empty();
		board[fcol][frow].set_black_bishop();}
	else if(board[icol][irow].type()=="queen" && current_color()=="black")
		{board[icol][irow].set_as_empty();
		board[fcol][frow].set_black_queen();}
	else if(board[icol][irow].type()=="queen" && current_color()=="white")
		{board[icol][irow].set_as_empty();
		board[fcol][frow].set_white_queen();}
	else if(board[icol][irow].type()=="king" && current_color()=="black")
		{board[icol][irow].set_as_empty();
		board[fcol][frow].set_black_king();}
	else if(board[icol][irow].type()=="king" && current_color()=="white")
		{board[icol][irow].set_as_empty();
		board[fcol][frow].set_white_king();}
}


game::make_move(move);
}



/*IS_LEGAL - Returns the legality of a move */
bool Chess::is_legal(const std::string& move) const
{
	if(move=="xx")
		{return true;}
	if(checker(move)==true)
		{return true;}
	else
		{return false;}
}



/*RESTART - Clears the board, and sets the initial pieces */
void Chess::restart()
{
for(int j=0;j<8;j++) 
	{
	for(int i=0;i<8;i++)
		{board[i][j].set_as_empty();}
	}

board[0][7].set_white_rook();
board[1][7].set_white_knight();
board[2][7].set_white_bishop();
board[3][7].set_white_queen();
board[4][7].set_white_king();
board[5][7].set_white_bishop();
board[6][7].set_white_knight();
board[7][7].set_white_rook();

	for(int c = 0;c<8;c++)
	{
board[c][6].set_white_pawn();
	}


board[0][0].set_black_rook();
board[1][0].set_black_knight();
board[2][0].set_black_bishop();
board[3][0].set_black_queen();
board[4][0].set_black_king();
board[5][0].set_black_bishop();
board[6][0].set_black_knight();
board[7][0].set_black_rook();
	for(int c = 0;c<8;c++)
	{
board[c][1].set_black_pawn();
	}
}



/*CURRENT_COLOR - Returns the color of the current entity */
string Chess::current_color() const
{
int x = moves_completed();
if ((x % 2) == 0)
	{return "white";}
else
	{return "black";}
}



/*CHECKER - Checks if the move is legal */
bool Chess::checker(const string& move) const 
{
int irow, icol, frow, fcol;
	frow = int(move[4]-'1');
	fcol = int(toupper(move[3])-'A');
	irow = int(move[1]-'1');
	icol = int(toupper(move[0])-'A');
bool pawn_legality=0, rook_legality=0, bishop_legality=0, knight_legality=0, queen_legality=0, king_legality=0; 


//If there is already a piece in that  spot you cant go there
if(board[icol][irow].has_piece_color() == board[fcol][frow].has_piece_color()) 
	{return false;}

//If its not your color you can't move that piece
if(board[icol][irow].has_piece_color()!=current_color())
	{return false;}
rook_legality = check_rook_legality(move);
knight_legality = check_knight_legality(move);
bishop_legality = check_bishop_legality(move);
queen_legality = check_queen_legality(move);
king_legality = check_king_legality(move);
pawn_legality  = check_pawn_legality(move);
if((board[icol][irow].type()=="pawn")&& pawn_legality == true )
	{return true;}
else if((board[icol][irow].type()=="rook")&& rook_legality == true )
	{return true;}
else if((board[icol][irow].type()=="knight")&& knight_legality == true )
	{return true;}
else if((board[icol][irow].type()=="bishop")&& bishop_legality == true )
	{return true;}
else if((board[icol][irow].type()=="queen")&& queen_legality == true )
	{return true;}
else if((board[icol][irow].type()=="king")&& king_legality == true )
	{return true;}
else //Else return that it wasn't valid
	{return false;}
}



/*CHECK_PAWN_LEGALITY - RETURNS THE LEGALITY OF A PAWN'S MOVE */
bool Chess::check_pawn_legality(const string& move)const
{
int irow, icol, frow, fcol;	
	frow = int(move[4]-'1');
	fcol = int(toupper(move[3])-'A');
	irow = int(move[1]-'1');
	icol = int(toupper(move[0])-'A');
bool obstruction = true;
obstruction = pawn_obstruction(move);	

if((board[icol][irow].has_piece_color()) == "white")
	{
	if((frow == irow - 1)&&(board[fcol][frow].emptiness() == true)&&(obstruction == true))
		{return true;}
	else
		{return false;}	
	}
else
	{
	if((frow == irow + 1)&&(board[fcol][frow].emptiness() == true)&&(obstruction == true))
		{return true;}
	else
		{return false;}
	}
}
bool Chess::pawn_obstruction(const string& move)const
{
int irow, icol, frow, fcol;	
	frow = int(move[4]-'1');
	fcol = int(toupper(move[3])-'A');
	irow = int(move[1]-'1');
	icol = int(toupper(move[0])-'A');
if(irow>frow)
{
	for(int i = irow;i>frow;i--)
	{
		if(board[fcol][i-1].has_piece_color()!="empty")
			{return false;}
	}
}
if(frow>irow)
{
	for(int i = irow;i<frow;i++)
	{
		if(board[fcol][i+1].has_piece_color()!="empty")
			{return false;}
	}
}
}



/*CHECK_ROOK_LEGALITY - Returns the legality of a rook's move */
bool Chess::check_rook_legality(const string& move)const
{
int irow, icol, frow, fcol;
frow = int(move[4]-'1');
fcol = int(toupper(move[3])-'A');
irow = int(move[1]-'1');
icol = int(toupper(move[0])-'A');

bool obstruction = true;
obstruction = rook_obstruction(move);
if((frow == irow)||(fcol == icol)&&(obstruction == true))
	{return true;}
else
	{return false;}	
	
}
bool Chess::rook_obstruction(const string& move)const
{
int irow, icol, frow, fcol;
frow = int(move[4]-'1');
fcol = int(toupper(move[3])-'A');
irow = int(move[1]-'1');
icol = int(toupper(move[0])-'A');
if(irow>frow) //if something is obstructing the up
{
	for(int i = irow;i>frow+1;--i)
	{
		if(board[fcol][i-1].has_piece_color()!="empty")
			{return false;}
	}
}
if(frow>irow) //if something is obstructing the down
{
	for(int i = irow;i<frow;i++)
	{
		if(board[fcol][i+1].has_piece_color()!="empty")
			{return false;}
	}
}
if(icol>fcol) //if something is obstructing the left
{
	for(int i = icol-1;i>fcol;i--)
	{
		if(board[i][irow].has_piece_color()!="empty")
			{return false;}
	}
}
if(icol<fcol) //if something is obstructing the right
{
	for(int i = icol+1;i<fcol;i++)
	{
		if(board[i][irow].has_piece_color()!="empty")
			{return false;}
	}
}
}



/*CHECK_BISHOP_LEGALITY - Returns the legality of a bishop's move */	
bool Chess::check_bishop_legality(const string& move)const
{
int irow, icol, frow, fcol;
frow = int(move[4]-'1');
fcol = int(toupper(move[3])-'A');
irow = int(move[1]-'1');
icol = int(toupper(move[0])-'A');
bool legal=0, obstruction = 0;
obstruction = bishop_obstruction(move);

for(int i=0;i<8;i++)
{
	if((irow)==(frow-i)&&(icol)==(fcol-i)) //Checking up-left
		{legal = 1;}
	if((irow)==(frow+i)&&(icol)==(fcol-i)) //Checking down-left
		{legal = 1;}
	if((irow)==(frow-i)&&(icol)==(fcol+i)) //Checking up-right
		{legal = 1;}
	if((irow)==(frow+i)&&(icol)==(fcol+i)) //Checking down-right
		{legal = 1;}
}
if( legal == 1 && obstruction == 1)
	{return true;}

return false;
}
bool Chess::bishop_obstruction(const string& move)const
{
int irow, icol, frow, fcol, c, r;
frow = int(move[4]-'1');
fcol = int(toupper(move[3])-'A');
irow = int(move[1]-'1');
icol = int(toupper(move[0])-'A');


if(frow>irow)
{
	if(fcol>icol) //to down-right
	{
		for(c=icol+1, r = irow+1; c<fcol; c++, r++)
		{
		if(board[c][r].emptiness() == false)
			{return false;}
		}
	}
	else //to down-left
	{
		for(c=icol-1, r = irow+1; r<frow; c--, r++)
		{
		if(board[c][r].emptiness() == false)
			{return false;}
		}
	}
}
else //frow<irow
{
	if(fcol>icol) //to up-right
	{
		for(c=icol+1, r = irow-1; c<fcol; c++, r--)
		{
		if(board[c][r].emptiness() == false)
			{return false;}
		}
	}
	else //to up-left
	{
		for(c=icol-1, r = irow-1; c>fcol; c--, r--)
		{
		if(board[c][r].emptiness() == false)
			{return false;}
		}
	}
}
return true;
}



/*CHECK_KNIGHT_LEGALITY - Returns the legality of a knight's move */
bool Chess::check_knight_legality(const string& move)const
{
int irow, icol, frow, fcol;
frow = int(move[4]-'1');
fcol = int(toupper(move[3])-'A');
irow = int(move[1]-'1');
icol = int(toupper(move[0])-'A');
bool ld=0,lu=0,ul=0,ur=0,rd=0,ru=0,dl=0,dr=0;

if(frow-2==irow && fcol-1==icol)
	{ul=1;}
if(frow-2==irow && fcol+1 ==icol)
	{ur=1;}
if(frow+2==irow && fcol+1 ==icol)
	{dr=1;}
if(frow+2==irow && fcol-1 ==icol)
	{dl=1;}
if(frow-1==irow && fcol-2 ==icol)
	{lu=1;}
if(frow+1==irow && fcol-2 ==icol)
	{ld=1;}
if(frow-1==irow && fcol+2 ==icol)
	{ru=1;}
if(frow+1==irow && fcol+2 ==icol)
	{rd=1;}

if( ld+lu+ul+ur+rd+ru+dl+dr == 1)
	{return true;}
else
	{return false;}
}



/*CHECK_QUEEN_LEGALITY - Returns the legality of a queen's move */
bool Chess::check_queen_legality(const string& move)const
{
int irow, icol, frow, fcol;
frow = int(move[4]-'1');
fcol = int(toupper(move[3])-'A');
irow = int(move[1]-'1');
icol = int(toupper(move[0])-'A');

if((check_rook_legality(move)==true)||check_bishop_legality(move)==true)
	{return true;}
else
	{return false;}
}



/*CHECK_KING_LEGALITY - Returns the legality of a king's move */
bool Chess::check_king_legality(const string& move)const
{
int irow, icol, frow, fcol;
frow = int(move[4]-'1');
fcol = int(toupper(move[3])-'A');
irow = int(move[1]-'1');
icol = int(toupper(move[0])-'A');

if((irow == (frow+1||frow-1||frow))&&(icol==(fcol-1||fcol||fcol+1)))
	{return true;}
else
	{return false;}
}




/*VICTORY - Returns the victor */
void Chess::victory() const
{
			cout<<"Game Over\n";
}

