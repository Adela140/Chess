#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

#include "piece.h"
#include "knight.h"

Knight::Knight(Colour _pieceColour) : Piece(_pieceColour, "Knight"){}
Knight::~Knight(){}
bool Knight::isMoveValid(int rankStart, int fileStart, int rankEnd, int fileEnd, Piece* const board[8][8]){


    // knight can move two squares vertically and one horizontally 
    if((abs(rankEnd-rankStart))==1 && (abs(fileEnd-fileStart))==2){
        return true;
    }
    
    // OR knight can move two squares horizontally and one vertically
    if((abs(rankEnd-rankStart))==2 && (abs(fileEnd-fileStart))==1){
        return true;
    }

    return false;
}