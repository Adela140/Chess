#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

#include "knight.h"

/*********************** Definitions for Knight class ************************/

/* Constructs the Knight object */
Knight::Knight(Colour _pieceColour) : Piece("Knight", _pieceColour){}

/* Destructs the Knight object */
Knight::~Knight(){}

/* Returns true if moving two squares vertically and one square horizontally, 
   or two squares horizontally and one square vertically */ 
bool Knight::legalPieceMove(int rankStart, int fileStart, int rankEnd, 
                            int fileEnd, const ChessBoard* const _cb){

    // return true if moving two squares vertically and one horizontally 
    if((abs(rankEnd-rankStart))==1 && (abs(fileEnd-fileStart))==2){
        return true;
    }
    
    // OR return true if moving two squares horizontally and one vertically
    if((abs(rankEnd-rankStart))==2 && (abs(fileEnd-fileStart))==1){
        return true;
    }

    return false;
}