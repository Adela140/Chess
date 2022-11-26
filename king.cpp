#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

#include "piece.h"
#include "king.h"

King::King(Colour _pieceColour) : Piece(_pieceColour, "King"){}
King::~King(){}
bool King::isMoveValid(int rankStart, int fileStart, int rankEnd, int fileEnd, Piece* const board[8][8]){
    
    int rankDifference = rankEnd - rankStart;
    int fileDifference = fileEnd - fileStart;

    // return true if the destination position is within one 
    // square of the source position
    return(abs(rankDifference)<=1 && abs(fileDifference)<=1);
    
}

bool King::inCheck(Piece* board[8][8], Piece* const _chessPiece[2][6]){

//cout<<"Checking if " << pieceColour<<" in check"<<endl;
    // chessPieces[0][0]; // white king
    // chessPieces[1][0]; // black king
    
    int kingRow;
    int kingColumn;

    // find position of the king
    for(int row=0; row<8; row++){
        for (int column=0; column<8; column++){
            if(board[row][column] == this){
                kingColumn= column;
                kingRow = row;
            }
        }
    }

    //cout<<"Found "<<pieceColour<<" king's position at:"<<kingPosition<<endl;
    
    // king in check if its position is a valid move for any of the opposite Player's pieces
    for (int row=0; row<8; row++){
        for(int column=0; column<8; column++){
            if(board[row][column]!=NULL){
                if((board[row][column]->get_colour()!=this->get_colour())
                && (board[row][column]->canMove(row, column, kingRow, kingColumn, board, _chessPiece))){
                //cout<< this->pieceColour<<" is in check"<<endl;
                //cout<< "by row: "<< row <<" and column:"<<column<<endl;
                //cout<<" position: "<<sourceSquare<<endl;
                //cout<<" with "<<board[row][column]->pieceColour<<" "<<board[row][column]->name<<endl;
                return true;
                }
            }
        }
    }
    //cout<<"King is not in check"<<endl;
    return false;


}
