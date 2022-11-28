#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

#include "piece.h"

/***************************** Definitions for Colour type ******************************/

/* Prints out the colour to either White or Black */
std::ostream& operator <<(std::ostream& out, Colour _pieceColour){
    switch (_pieceColour) {
    case white:
        out << "White"; break;
    case black:
        out << "Black"; break;
    default:
        out << "invalid colour"; break;
    }
    return out;
}

/* Changes colour to the opposite colour */
Colour operator!(Colour _colour){
    _colour = static_cast<Colour>((static_cast<int>(_colour) + 1) % 2);
    return _colour;
}

/***************************** Definitions for Piece class ******************************/

/* Constructs Piece object */
Piece::Piece(Colour _pieceColour, string _name): pieceColour(_pieceColour), name(_name){}

/* Destructs the Piece object */
Piece::~Piece(){}

/* Returns false if Piece is not King */
bool Piece::inCheck(Piece* board[8][8], Piece* const _chessPiece[2][6]){return false;}

/* Returns true if the move of the piece is valid */
bool Piece::isMoveValid(int rankStart, int fileStart, int rankEnd, int fileEnd, 
                        Piece* board[8][8]){

    // make sure that the destination does not contain a piece of the same colour 
    // and that the piece is moving according to its rules
    if(isDestinationLegal(rankEnd, fileEnd, board)
        && legalPieceMove(rankStart, fileStart, rankEnd, fileEnd, board)){
        
      /*  // check if the move would put your own king in check:

        // keep track of the contents of the destination square
        Piece* destination_piece = board[rankEnd][fileEnd];
        // move the piece to the destination square and remove it from source square
        board[rankEnd][fileEnd]=board[rankStart][fileStart];
        board[rankStart][fileStart]=NULL;

        // based on the updated board, 
        // if your own king is in check reset the pointers to original squares
        // and the move is invalid
        if (((pieceColour == white) && (_chessPiece[0][0]->inCheck(board, _chessPiece))) || 
            ((pieceColour==black) && (_chessPiece[1][0]->inCheck(board, _chessPiece)))){
            board[rankStart][fileStart]=board[rankEnd][fileEnd];
            board[rankEnd][fileEnd]=destination_piece;
                return false;
            }

        // reset the board to state before the move
        // this is done because the 'isMoveValid' method is also used in the 'inCheck' 
        // method, so it cannot change the board if we only check for if a king is in check 
        board[rankStart][fileStart]=board[rankEnd][fileEnd];
        board[rankEnd][fileEnd]=destination_piece;
        */
        return true;
    }
    return false;
}
    
/* Returns true if the destination square does not contain a piece of the same colour */
bool Piece::isDestinationLegal(int rankEnd, int fileEnd, Piece* const board[8][8]){

    //if the destination is not NULL, it cannot contain the same colour as the player
    if(board[rankEnd][fileEnd]!=NULL){
        if (board[rankEnd][fileEnd]->pieceColour == this->pieceColour){
            return false;
        }
    }
    return true;
}

/* Returns the colour of the piece */
const Colour Piece::get_colour() const {
    return pieceColour;
}


    


