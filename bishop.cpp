#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

#include "piece.h"
#include "bishop.h"

/**************************** Definitions for Bishop class ******************************/

/* Constructs the Bishop object */
Bishop::Bishop(Colour _pieceColour) : Piece(_pieceColour, "Bishop"){}

/* Destructs the Bishop object */
Bishop::~Bishop(){}

/* Returns true if moving diagonally but not leaping over other pieces*/
bool Bishop::legalPieceMove(int rankStart, int fileStart, int rankEnd, int fileEnd, 
                            Piece* const board[8][8]){

    // determine in which direction the bishop is moving
    int rankDirec = (rankEnd > rankStart) ? 1 : -1;
    int fileDirec = (fileEnd > fileStart) ? 1 : -1;

    // to move diagonally, the difference between the destination and source must be 
    // the same for the rank and file
    if((abs(rankEnd-rankStart))==(abs(fileEnd-fileStart))){

        // iterate through the diagonal in which the bishop is moving to 
        // check if it is leaping over other pieces
        for(int row = rankStart+rankDirec, column = fileStart+fileDirec; row != rankEnd ; 
            row=row+rankDirec, column=column+fileDirec){
            // return false if encountering a piece before the destination square
            if (board[row][column]!=NULL){
                return false;
            }
           
        }
        return true;
    }
    // if bishop not moving diagonally, return false
    return false;
}