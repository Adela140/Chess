#include <iostream>
using namespace std;

#include "ChessBoard.h"
#include "piece.h"


int main(){
    
   /* int row1[2]={1,2};
    int row2[2]={3,4};
    int board[2][2]={{*row1}, {*row2}};
    cout<< board[1][0]<<endl;
    */

   ChessBoard board1;
   Pawn pawn1(white);
   pawn1.printType();

   if(board1.submitMove("A10", "A2")){
      cout<<"Move is valid"<<endl;
   }
   else{
      cout<<"Move is not valid"<<endl;
   }

   // piece on position B2
   board1.getElement("D8");

   cout<<"HELLO"<<endl;


   cout << "========================\n";
	cout << "Testing the Chess Engine\n";
	cout << "========================\n\n";

	ChessBoard cb;
	cout << '\n';

	cb.submitMove("D7", "D6");
	cout << '\n';

	cb.submitMove("D4", "H6");
	cout << '\n';

   //cb.board[1][1]->isMoveValid("B2" , "B3", cb.board);
   //cb.board[1][1]->canMove("B2" , "B3", cb.board);

   //board1.getElement("D2");
   
   cb.getElement("D2");
   cout<<cb.board[3][3]<<endl;
   cout<<cb.board[1][3]<<endl;
	cb.submitMove("D2", "D4");
	cout << '\n';
   
   cout<<cb.board[3][3]<<endl;
   cout<<cb.board[1][3]<<endl;
   cout<<cb.board[0][0]<<endl;
   //cb.getElement("A1");
   cb.getElement("D4");
   //cb.getElement("D2");
   //board1.getElement("D4");
   //board1.getElement("D2");

   cb.submitMove("F8", "B4");
	cout << '\n';



return 0;
}