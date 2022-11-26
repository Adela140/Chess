#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

#include "piece.h"
#include "queen.h"

Queen::Queen(Colour _pieceColour) : Piece(_pieceColour, "Queen"){}
Queen::~Queen(){}
bool Queen::isMoveValid(const char _sourceSquare[], const char _destinationSquare[], Piece* board[8][8]){
    // convert positions to integer indeces
    int fileSource= _sourceSquare[0]-'A';
    int fileDestination = _destinationSquare[0]-'A';
    int rankSource = _sourceSquare[1]-'1';
    int rankDestination = _destinationSquare[1]-'1';

    // determine in which direction the queen is moving
    int rankDirec;
    int fileDirec;
    if(rankDestination>rankSource){
        rankDirec=1;
    }
    else if(rankDestination==rankSource){
        rankDirec=0;
    }
    else
        rankDirec=-1;

    if(fileDestination>fileSource){
        fileDirec=1;
    }
    else if(fileDestination==fileSource){
        fileDirec=0;
    }
    else
        fileDirec=-1;

    // check that the queen is either moving diagonally or along a file or rank
    if((rankDestination==rankSource)||(fileDestination==fileSource)||
        ((abs(rankDestination-rankSource))==(abs(fileDestination-fileSource)))){
        
        // check if the queen is leaping over some pieces
        for(int row=rankSource+rankDirec, column=fileSource+fileDirec; row!=rankDestination
            || column!=fileDestination; row=row+rankDirec, column=column+fileDirec){
                if(board[row][column]!=NULL){
                    return false;
                }
        }
        return true;
    }
    // return false if not moving either diagonally or along a file or rank
    return false;
}