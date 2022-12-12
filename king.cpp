#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

#include "king.h"

/************************ Definitions for King class *************************/

/* Constructs the King object */
King::King(Colour _pieceColour) : Piece("King", _pieceColour){}

/* Destructs the King object */
King::~King(){}

/* Returns true if moving one square in any direction */
bool King::legalPieceMove(int rankStart, int fileStart, int rankEnd, 
                          int fileEnd, const ChessBoard* const _cb){
    
    int rankDifference = rankEnd - rankStart;
    int fileDifference = fileEnd - fileStart;

    // return true if the destination position is within one 
    // square of the source position
    return(abs(rankDifference)<=1 && abs(fileDifference)<=1);
    
}