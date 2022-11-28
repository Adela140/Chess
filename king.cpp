#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

#include "piece.h"
#include "king.h"
//#include "ChessBoard.h"

/**************************** Definitions for King class ********************************/

/* Constructs the King object */
King::King(Colour _pieceColour) : Piece(_pieceColour, "King"){}

/* Destructs the King object */
King::~King(){}

/* Returns true if moving one square in any direction */
bool King::legalPieceMove(int rankStart, int fileStart, int rankEnd, int fileEnd, 
                          const ChessBoard* const _cb){
    
    int rankDifference = rankEnd - rankStart;
    int fileDifference = fileEnd - fileStart;

    // return true if the destination position is within one 
    // square of the source position
    return(abs(rankDifference)<=1 && abs(fileDifference)<=1);
    
}

/* Returns true if King is in check */
/*
bool King::inCheck(Piece* board[8][8], Piece* const _chessPiece[2][6]){
    
    // find position of the king
    int kingRow;
    int kingColumn;

    for(int row=0; row<8; row++){
        for (int column=0; column<8; column++){
            if(board[row][column] == this){
                kingColumn= column;
                kingRow = row;
            }
        }
    }
    
    // king in check if its position is a valid move for any of the opposite player's pieces
    for (int row=0; row<8; row++){
        for(int column=0; column<8; column++){
            if(board[row][column]!=NULL){
                // check if the piece is opposite player's
                if((board[row][column]->get_colour()!=this->get_colour())
                && (board[row][column]->isMoveValid(row, column, kingRow, kingColumn, 
                                                    board, _chessPiece))){
            
                return true;
                }
            }
        }
    }

    return false;

}
*/