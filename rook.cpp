#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

#include "piece.h"
#include "rook.h"

Rook::Rook(Colour _pieceColour) : Piece(_pieceColour, "Rook"){}
Rook::~Rook(){}
bool Rook::isMoveValid(int rankStart, int fileStart, int rankEnd, int fileEnd, Piece* const board[8][8]){

    // if moving along a rank
    if (rankStart==rankEnd){
        // determine in which direction the rook is moving
        int fileDirec = (fileEnd > fileStart) ? 1 : -1;
        // check that the rook is not leaping over other pieces 
        for(int column =fileStart+fileDirec; column<fileEnd; column=column+fileDirec){
            // return false if encountering a piece before the destination square
            if(board[rankStart][column]!=NULL){
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
        for(int row =rankStart+rankDirec; row<rankStart; row=row+rankDirec){
            // return false if encountering a piece before the destination square
            if(board[row][fileStart]!=NULL){
                return false;
            }
        }
        return true;
    }

    // return false if the move is not along a rank or file
    return false;
}