#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

#include "rook.h"

/************************ Definitions for Rook class ************************/

/* Constructs the Rook object */
Rook::Rook(Colour _pieceColour) : Piece("Rook", _pieceColour){}

/* Destructs the Rook object */
Rook::~Rook(){}

/* Returns true if moving along a rank or file but not leaping over other pieces */
bool Rook::legalPieceMove(int rankStart, int fileStart, int rankEnd, 
                          int fileEnd, const ChessBoard* const _cb){

    // if moving along a rank
    if (rankStart==rankEnd){
        // determine in which direction the rook is moving
        int fileDirec = (fileEnd > fileStart) ? 1 : -1;
        // check that the rook is not leaping over other pieces 
        for(int column =fileStart+fileDirec; column!=fileEnd; column=column+fileDirec){
            // return false if encountering a piece before the destination square
            if(_cb->get_piece(rankStart,column)!=NULL){
                return false;
            }
        }
        return true;
    }
    // if moving along a file
    if(fileStart==fileEnd){
        // determine in which direction the rook is moving
        int rankDirec = (rankEnd > rankStart) ? 1 : -1;
        // check that the rook is not leaping over other pieces 
        for(int row =rankStart+rankDirec; row!=rankEnd; row=row+rankDirec){
            // return false if encountering a piece before the destination square
            if(_cb->get_piece(row,fileStart)!=NULL){
                return false;
            }
        }
        return true;
    }

    // return false if the move is not along a rank or file
    return false;
}