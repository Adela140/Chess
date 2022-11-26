#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

#include "piece.h"
#include "queen.h"

Queen::Queen(Colour _pieceColour) : Piece(_pieceColour, "Queen"){}
Queen::~Queen(){}
bool Queen::isMoveValid(int rankStart, int fileStart, int rankEnd, int fileEnd, Piece* const board[8][8]){

    // determine in which direction the queen is moving
    int rankDirec;
    int fileDirec;
    if(rankEnd>rankStart){
        rankDirec=1;
    }
    else if(rankEnd==rankStart){
        rankDirec=0;
    }
    else
        rankDirec=-1;

    if(fileEnd>fileStart){
        fileDirec=1;
    }
    else if(fileEnd==fileStart){
        fileDirec=0;
    }
    else
        fileDirec=-1;

    // check that the queen is either moving diagonally or along a file or rank
    if((rankEnd==rankStart)||(fileEnd==fileStart)||
        ((abs(rankEnd-rankStart))==(abs(fileEnd-fileStart)))){
        
        // check if the queen is leaping over some pieces
        for(int row=rankStart+rankDirec, column=fileStart+fileDirec; row!=rankEnd
            || column!=fileEnd; row=row+rankDirec, column=column+fileDirec){
                if(board[row][column]!=NULL){
                    return false;
                }
        }
        return true;
    }
    // return false if not moving either diagonally or along a file or rank
    return false;
}