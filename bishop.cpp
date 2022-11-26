#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

#include "piece.h"
#include "bishop.h"

Bishop::Bishop(Colour _pieceColour) : Piece(_pieceColour, "Bishop"){}
Bishop::~Bishop(){}
bool Bishop::isMoveValid(const char _sourceSquare[], const char _destinationSquare[], Piece* board[8][8]){
    // convert positions to integer indeces
    int fileSource= _sourceSquare[0]-'A';
    int fileDestination = _destinationSquare[0]-'A';
    int rankSource = _sourceSquare[1]-'1';
    int rankDestination = _destinationSquare[1]-'1';

    // determine in which direction the bishop is moving
    int rankDirec = (rankDestination > rankSource) ? 1 : -1;
    int fileDirec = (fileDestination > fileSource) ? 1 : -1;

    // to move diagonally, the difference between the destination and source must be 
    // the same for the rank and file
    if((abs(rankDestination-rankSource))==(abs(fileDestination-fileSource))){
        // iterate through the diagonal in which the bishop is moving to check if it is leaping
        // over other pieces
        //cout<<"Bishop moving diagonally"<<endl;
        //cout<<"rankDir: "<<rankDirec<<" and fileDirec:"<<fileDirec<<endl;
        for(int row = rankSource+rankDirec, column = fileSource+fileDirec; row != rankDestination ; 
            row=row+rankDirec, column=column+fileDirec){
            if (board[row][column]!=NULL){
                return false;
            }
            //cout<<"Bishop moving freely"<<endl;
        }
        return true;
    }
    // if bishop not moving diagonally, return false
    return false;
}