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
   //board1.getElement("D8");


   cout << "========================\n";
	cout << "Testing the Chess Engine\n";
	cout << "========================\n\n";

	ChessBoard cb;
	cout << '\n';

   cb.printBoard(cb.board);

   cout<<"Test:"<<endl;
	cb.submitMove("D7", "D6");
	cout << '\n';

   cout<<"Test:"<<endl;
	cb.submitMove("D4", "H6");
	cout << '\n';

   cout<<"Test:"<<endl;
	cb.submitMove("D2", "D4");
	cout << '\n';

   cout<<"Test:"<<endl;
	cb.submitMove("F8", "B4");
	cout << '\n';

   cout << "=========================\n";
	cout << "Alekhine vs. Vasic (1931)\n";
	cout << "=========================\n\n";

	cb.resetBoard();
	cout << '\n';

	cb.submitMove("E2", "E4");
   //cb.printBoard(cb.board);
	cb.submitMove("E7", "E6");
   //cb.printBoard(cb.board);
	cout << '\n';

	cb.submitMove("D2", "D4");
   //cb.printBoard(cb.board);
	cb.submitMove("D7", "D5");
   //cb.printBoard(cb.board);
	cout << '\n';

	cb.submitMove("B1", "C3");
   //cb.printBoard(cb.board);
	cb.submitMove("F8", "B4");
   //cb.printBoard(cb.board);
	cout << '\n';

	cb.submitMove("F1", "D3");
   //cb.printBoard(cb.board);
	cb.submitMove("B4", "C3");
	cout << '\n';

	cb.submitMove("B2", "C3");
   //cb.printBoard(cb.board);
	cb.submitMove("H7", "H6");
   //cb.printBoard(cb.board);
	cout << '\n';

	cb.submitMove("C1", "A3");
   //cb.printBoard(cb.board);
	cb.submitMove("B8", "D7");
   //cb.printBoard(cb.board);
	cout << '\n';

	cb.submitMove("D1", "E2");
   //cb.printBoard(cb.board);
	cb.submitMove("D5", "E4");
   cb.printBoard(cb.board);
	cout << '\n';

	cb.submitMove("D3", "E4");
   cb.printBoard(cb.board);
	cb.submitMove("G8", "F6");
   cb.printBoard(cb.board);
	cout << '\n';

	cb.submitMove("E4", "D3");
   
	cb.submitMove("B7", "B6");
	cout << '\n';

	cb.submitMove("E2", "E6");
	cb.submitMove("F7", "E6");
	cout << '\n';

	cb.submitMove("D3", "G6");
	cout << '\n';

   

return 0;
}