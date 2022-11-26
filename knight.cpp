#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

#include "piece.h"
#include "knight.h"

Knight::Knight(Colour _pieceColour) : Piece(_pieceColour, "Knight"){}
Knight::~Knight(){}
bool Knight::isMoveValid(const char _sourceSquare[], const char _destinationSquare[], Piece* board[8][8]){
    // convert positions to integer indeces
    int fileSource= _sourceSquare[0]-'A';
    int fileDestination = _destinationSquare[0]-'A';
    int rankSource = _sourceSquare[1]-'1';
    int rankDestination = _destinationSquare[1]-'1';

    // knight can move two squares vertically and one horizontally 
    if((abs(rankDestination-rankSource))==1 && (abs(fileDestination-fileSource))==2){
        return true;
    }
    
    // OR knight can move two squares horizontally and one vertically
    if((abs(rankDestination-rankSource))==2 && (abs(fileDestination-fileSource))==1){
        return true;
    }

    return false;
}