/*
main for chess game
Taylor Bruening
*/
#include<iostream>
#include<cstdlib>
#include<string>
#include"Chess.h"

using namespace std;

int main(){
Chess myg;

cout<<BOLD<<"\nCHESS\n"<<RESET;
cout<<"Enter lower case "<<RED<<"xx"<<RESET<<" to skip a turn\n";
cout<<"Example move:A1 A3\n";
myg.play();
myg.victory();

return 0;
}
