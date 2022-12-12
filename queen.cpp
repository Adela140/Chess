#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

#include "queen.h"

/************************ Definitions for Queen class ************************/

/* Constructs the Queen object */
Queen::Queen(Colour _pieceColour) : Piece("Queen", _pieceColour){}

/* Destructs the Queen object */
Queen::~Queen(){}

/* Returns true if moving along a rank, file or diagonally, but not leaping over others */
bool Queen::legalPieceMove(int rankStart, int fileStart, int rankEnd, 
                           int fileEnd, const ChessBoard* const _cb){

    // determine in which direction the queen is moving 
    int rankDirec;
    int fileDirec;
    if(rankEnd>rankStart){rankDirec=1;}
    else if(rankEnd==rankStart){rankDirec=0;}
    else {rankDirec=-1;}

    if(fileEnd>fileStart){fileDirec=1;}
    else if(fileEnd==fileStart){fileDirec=0;}
    else {fileDirec=-1;}

    // check that the queen is either moving diagonally or along a file or rank
    // to move diagonally, the difference between the destination and source 
    // must be the for the rank and the file
    if((rankEnd==rankStart)||(fileEnd==fileStart)||
        ((abs(rankEnd-rankStart))==(abs(fileEnd-fileStart)))){
        
        // check if the queen is leaping over some pieces by iterating through 
        // the path of its move
        for(int row=rankStart+rankDirec, column=fileStart+fileDirec; row!=rankEnd
            || column!=fileEnd; row=row+rankDirec, column=column+fileDirec){
                // return false if encountering a piece before the destination square
                if(_cb->get_piece(row,column)!=NULL){
                    return false;
                }
        }
        return true;
    }
    // return false if not moving either diagonally or along a file or rank
    return false;
}