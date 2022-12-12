#include<iostream>
using std::cout;

#include "ChessBoard.h"

int main() {

/**************************** TESTING WRONG INPUTS ***************************/
	cout<<endl;
	cout << "========================\n";
	cout << "Testing inputs & player \n";
	cout << "========================\n\n";
	ChessBoard chess;
	
	// inputs out of range
	// move refused
	chess.submitMove("B9", "A1");
	chess.submitMove("K2", "A1");
	chess.submitMove("B2", "A9");
	chess.submitMove("B2", "L1");
	chess.submitMove("a2", "A3");
	chess.submitMove("A2", "a3");
	chess.submitMove("!9", "A3");

	// inputs are invalid length
	// move refused
	chess.submitMove("A", "C1");
	chess.submitMove("A1", "C10");

	// inputs are the same
	// move refused
	chess.submitMove("C3", "C3");

	// wrong colour playing
	// move refused
	chess.submitMove("A7", "A6");

	cout<<endl;

/*********************** TESTING THE CHESS PIECE CLASSES *********************/

	cout << "========================\n";
	cout << "     Testing pieces     \n";
	cout << "========================\n\n";

	chess.resetBoard();

	/**************************** Testing Pawn ****************************/

	// moving white pawn diagonally without eating another piece
	// move refused
	chess.submitMove("B2", "C1");

	// moving white pawn two squares forward
	// move approved 
	chess.submitMove("F2", "F4");

	// moving black pawn diagonally without eating another piece
	// move refused
	chess.submitMove("D7", "E6");

	// moving black pawn two squares forward
	// move approved
	chess.submitMove("C7", "C5");

	// moving white pawn back one square
	// move refused
	chess.submitMove("F4", "F3");

	// moving white pawn horizontally
	// move refused
	chess.submitMove("F4", "G4");

	// moving white pawn two pieces when not first move
	// move refused
	chess.submitMove("F4", "F6");

	// moving white pawn one square when not first move
	// move approved
	chess.submitMove("F4", "F5");

	// moving black pawn back one square
	// move refused
	chess.submitMove("C5", "C6");

	// moving black pawn horizontally
	// move refused
	chess.submitMove("C5", "B5");

	// moving black pawn two pieces when not first move
	// move refused
	chess.submitMove("C5", "C3");

	// moving black pawn one square when not first move
	// move approved
	chess.submitMove("C5", "C4");

	// moving white pawn one square when first move
	// move approved
	chess.submitMove("C2", "C3");

	// black pawn trying to eat a white piece right at front
	// move refused
	chess.submitMove("C4", "C3");
	
	// moving black pawn one square when first move
	// move approved
	chess.submitMove("F7", "F6");

	// white pawn trying to eat own piece
	// move refused
	chess.submitMove("B2", "C3");

	chess.submitMove("D2", "D3");

	// black pawn eating white pawn
	// move approved
	chess.submitMove("C4", "D3");

	chess.submitMove("C3", "C4");

	// black pawn trying to eat white piece by moving diagonally backwards
	// move refused
	chess.submitMove("D3", "C4");

	chess.submitMove("E7", "E6");
	
	// white pawn trying to eat black piece by moving diagonally backwards
	// move refused
	chess.submitMove("C4", "D3");

	// white pawn trying to eat black piece by moving diagonally forwards
	// move approved
	chess.submitMove("E2", "D3");

	/**************************** Testing Bishop ****************************/
	
	// black bishop trying to move not diagonally
	// move refused
	chess.submitMove("C8", "B6");

	// black bishop trying to jump over a piece
	// move refused
	chess.submitMove("C8", "A6");

	// black bishop trying to move along a file
	// move refused
	chess.submitMove("C8", "C6");

	// black bishop moving diagonally 
	// move approved
	chess.submitMove("F8", "C5");

	// white bishop trying to move along a file
	// move refused
	chess.submitMove("C1", "C2");

	// white bishop trying to move not diagonally
	// move refused
	chess.submitMove("F1", "E3");

	// white bishop moving diagonally
	// move approved
	chess.submitMove("C1", "G5");

	// black bishop moving backwards diagonally
	// move approved
	chess.submitMove("C5", "B6");

	// white bishop trying to eat white piece
	// move refused
	chess.submitMove("F1", "D3");

	// white bishop trying to move along a rank
	// move refused
	chess.submitMove("G5", "H5");

	// white bishop trying to eat black piece
	// move approved
	chess.submitMove("G5", "F6");

	/**************************** Testing Knight ****************************/

	// black knight jumping over pieces
	// move approved
	chess.submitMove("B8", "C6");

	// white knight jumping over pieces
	// move approved
	chess.submitMove("G1", "E2");

	// black knight not moving in an L
	// move refused
	chess.submitMove("G8", "F7");

	// black knight eating white bishop
	// move approved
	chess.submitMove("G8", "F6");

	// white knight not moving in an L
	// move refused
	chess.submitMove("B1", "E3");

	/**************************** Testing Rook ****************************/

	// making space
	chess.submitMove("A2", "A4");
	chess.submitMove("A7", "A5");
	chess.submitMove("H2", "H4");
	chess.submitMove("H7", "H5");

	// white rook moving along a file
	// move approved
	chess.submitMove("A1", "A3");

	// black rook moving along a file
	// move approved
	chess.submitMove("H8", "H6");

	// white rook moving along a rank
	// move approved
	chess.submitMove("H1", "G1");

	// black rook moving along a rank
	// move approved
	chess.submitMove("H6", "G6");

	// white rook moving diagonally
	// move refused
	chess.submitMove("A3", "C4");

	// white moving in an L shape
	// move refused
	chess.submitMove("A3", "B5");

	chess.submitMove("A3", "B3");

	// black rook moving diagonally
	// move refused
	chess.submitMove("G6", "F7");

	// black rook eating white piese
	// move approved
	chess.submitMove("G6", "G2");

	/**************************** Testing Queen ****************************/

	// white queen not moving diagonally or along a file or rank
	// move refused
	chess.submitMove("D1", "C3");
	
	// white queen moving along a file
	// move approved
	chess.submitMove("D1", "D2");

	// black queen not moving diagonally or along a file or rank
	// move refused
	chess.submitMove("D8", "F7");

	// black queen jumping over a piece
	// move refused
	chess.submitMove("D8", "G5");

	// black queen moving diagonally
	// move approved
	chess.submitMove("D8", "E7");

	// white queen trying to eat a white piece
	// move refused
	chess.submitMove("D2", "B2");

	// white queen eating a black piece
	// move approved
	chess.submitMove("D2", "A5");

	// black queen moving along a file
	// move approved
	chess.submitMove("E7", "F7");

	// white queen jumping over black piece
	// move refused
	chess.submitMove("A5", "C7");

	// white queen moving along a rank
	// move approved
	chess.submitMove("A5", "B5");

	// black queen moving along a rank
	// move approved
	chess.submitMove("F7", "E7");

	/**************************** Testing King ****************************/
	
	// white king moving two places
	// move refused
	chess.submitMove("E1", "C1");

	// white king moving to occupied space
	// move refused
	chess.submitMove("E1", "E2");

	// white king moving and putting itself in check
	// move refused
	chess.submitMove("E1", "F2");

	// white king moving diagonally
	// move approved
	chess.submitMove("E1", "D2");

	// black king not moving one place
	// move refused
	chess.submitMove("E8", "C7");

	// black king moving diagonally
	// move approved
	chess.submitMove("E8", "F7");

	// white king moving along a file
	// move approved
	chess.submitMove("D2", "D1");

	// black king moving and putting itself in check
	// move refused
	chess.submitMove("F7", "G6");

	// black king moving along a file
	// move approved
	chess.submitMove("F7", "F8");

	// white king moving along a rank
	// move approved
	chess.submitMove("D1", "C1");

	// black king moving along a rank
	// move approved
	chess.submitMove("F8", "G8");	

	chess.printBoard();
	cout<<endl;

/****************************** TESTING CASTLING *****************************/
	cout << "========================\n";
	cout << "     Testing castling   \n";
	cout << "========================\n\n";
	// preparing the board
	chess.resetBoard();
	chess.submitMove("E2", "E4");
	chess.submitMove("E7", "E6");
	chess.submitMove("D2", "D4");
	chess.submitMove("D7", "D5");
	chess.submitMove("B1", "C3");
	chess.submitMove("F8", "B4");
	chess.submitMove("F1", "D3");
	chess.submitMove("B4", "C3");
	chess.submitMove("B2", "C3");
	chess.submitMove("H7", "H6");
	chess.submitMove("C1", "A3");
	chess.submitMove("B8", "D7");
	chess.submitMove("D1", "E2");
	chess.submitMove("D5", "E4");
	chess.submitMove("D3", "E4");
	chess.submitMove("G8", "F6");
	chess.submitMove("E4", "D3");
	chess.submitMove("B7", "B6");
	cout << '\n';

	// white king trying to castle with rook when piece in between
	// move rejected
	chess.submitMove("E1", "G1");

	// white king and rook at A1 castling
	// move accepted
	chess.submitMove("E1", "C1");

	// black king and rook at H8 castling
	// move rejected since white bishop attacks F8
	chess.submitMove("E8", "G8");

	// filler move
	chess.submitMove("C7", "C5");

	// white king wanting to catle again
	// move rejected
	chess.submitMove("C1", "E1");

	// filler moves
	chess.submitMove("D1", "D2");
	chess.submitMove("F6", "G4");
	chess.submitMove("D3", "H7");

	// black king and rook at H8 castling when bishop attacks G8
	// move refused
	chess.submitMove("E8", "G8");

	// filler moves
	chess.submitMove("C8", "B7");
	chess.submitMove("H7", "G6");

	// black king and rook at H8 castling when not blocked
	// move approved
	chess.submitMove("E8", "G8");

	// filler moves
	chess.submitMove("G1", "F3");
	chess.submitMove("F8", "E8");

	// white king trying to do castling again
	// move refused
	chess.submitMove("C1", "E1");

	chess.printBoard();
	cout<<endl;

/****************************** STALEMATE TEST *******************************/
	cout << "========================\n";
	cout << "    Testing stalemate   \n";
	cout << "========================\n\n";
	chess.resetBoard();
	chess.submitMove("E2", "E3");
	chess.submitMove("A7", "A5");
	chess.submitMove("D1", "H5");
	chess.submitMove("A8", "A6");
	chess.submitMove("H5", "A5");
	chess.submitMove("H7", "H5");
	chess.submitMove("H2", "H4");
	chess.submitMove("A6", "H6");
	chess.submitMove("A5", "C7");
	chess.submitMove("F7", "F6");
	chess.submitMove("C7", "D7");
	chess.submitMove("E8", "F7");
	chess.submitMove("D7", "B7");
	chess.submitMove("D8", "D3");
	chess.submitMove("B7", "B8");
	chess.submitMove("D3", "H7");
	chess.submitMove("B8", "C8");
	chess.submitMove("F7", "G6");
	chess.submitMove("C8", "E6");
	cout<<endl;

/******************************* CHECKMATE TEST ******************************/
	cout << "========================\n";
	cout << "    Testing checkmate   \n";
	cout << "========================\n\n";
	chess.resetBoard();
	chess.submitMove("F2", "F3");
	chess.submitMove("E7", "E5");
	chess.submitMove("G2", "G4");
	chess.submitMove("D8", "H4");
	cout<<endl;

/******************************** EXTRA TEST *********************************/
	cout << "========================\n";
	cout << "     Game over tests    \n";
	cout << "========================\n\n";
	// loser making another move after game has ended
	// move refused
	chess.submitMove("C2", "C3");

	// the winner making another move
	// move refused
	chess.submitMove("A7", "A6");

	cout<<endl;
	
/******************************** FINAL TEST *********************************/

	cout << "========================\n";
	cout << "Testing the Chess Engine\n";
	cout << "========================\n\n";

	ChessBoard cb;
	cout << '\n';

	cb.submitMove("D7", "D6");
	cout << '\n';

	cb.submitMove("D4", "H6");
	cout << '\n';

	cb.submitMove("D2", "D4");
	cout << '\n';

	cb.submitMove("F8", "B4");
	cout << '\n';

	cout << "=========================\n";
	cout << "Alekhine vs. Vasic (1931)\n";
	cout << "=========================\n\n";

	cb.resetBoard();
	cout << '\n';

	cb.submitMove("E2", "E4");
	cb.submitMove("E7", "E6");
	cout << '\n';

	cb.submitMove("D2", "D4");
	cb.submitMove("D7", "D5");
	cout << '\n';

	cb.submitMove("B1", "C3");
	cb.submitMove("F8", "B4");
	cout << '\n';

	cb.submitMove("F1", "D3");
	cb.submitMove("B4", "C3");
	cout << '\n';

	cb.submitMove("B2", "C3");
	cb.submitMove("H7", "H6");
	cout << '\n';

	cb.submitMove("C1", "A3");
	cb.submitMove("B8", "D7");
	cout << '\n';

	cb.submitMove("D1", "E2");
	cb.submitMove("D5", "E4");
	cout << '\n';

	cb.submitMove("D3", "E4");
	cb.submitMove("G8", "F6");
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
