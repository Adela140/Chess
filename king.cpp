#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

#include "piece.h"
#include "king.h"

King::King(Colour _pieceColour) : Piece(_pieceColour, "King"){}
King::~King(){}
bool King::isMoveValid(const char _sourceSquare[], const char _destinationSquare[], Piece* board[8][8]){
    // convert positions to integer indeces
    int fileSource= _sourceSquare[0]-'A';
    int fileDestination = _destinationSquare[0]-'A';
    int rankSource = _sourceSquare[1]-'1';
    int rankDestination = _destinationSquare[1]-'1';

    int rankDifference = rankDestination - rankSource;
    int fileDifference = fileDestination - fileSource;

    // return true if the destination position is within one 
    // square of the source position
    return(abs(rankDifference)<=1 && abs(fileDifference)<=1);
    
}

bool King::inCheck(Piece* board[8][8], Piece* _chessPiece[2][6]){

//cout<<"Checking if " << pieceColour<<" in check"<<endl;
    // chessPieces[0][0]; // white king
    // chessPieces[1][0]; // black king
    
    char kingPosition[3];
    // find position of the king
    for(int row=0; row<8; row++){
        for (int column=0; column<8; column++){
            if(board[row][column] == this){
                kingPosition[0]= column + 'A';
                kingPosition[1] = row + '1';
                kingPosition[2] ='\0';
            }
        }
    }

    //cout<<"Found "<<pieceColour<<" king's position at:"<<kingPosition<<endl;
    
    // king in check if its position is a valid move for any of the opposite Player's pieces
    for (int row=0; row<8; row++){
        for(int column=0; column<8; column++){
            char sourceSquare[3]={column + 'A', row + '1', '\0'};
            if(board[row][column]!=NULL){
                if((board[row][column]->get_colour()!=this->get_colour())
                && (board[row][column]->canMove(sourceSquare, kingPosition, board, _chessPiece))){
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
