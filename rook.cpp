#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

#include "piece.h"
#include "rook.h"

Rook::Rook(Colour _pieceColour) : Piece(_pieceColour, "Rook"){}
Rook::~Rook(){}
bool Rook::isMoveValid(const char _sourceSquare[], const char _destinationSquare[], Piece* board[8][8]){
    // convert positions to integer indeces
    int fileSource= _sourceSquare[0]-'A';
    int fileDestination = _destinationSquare[0]-'A';
    int rankSource = _sourceSquare[1]-'1';
    int rankDestination = _destinationSquare[1]-'1';

    // if moving along a rank
    if (rankSource==rankDestination){
        // check that the rook is not leaping over other pieces 
        // if rook is moving to the right
        if(fileDestination>fileSource){
            for(int column =fileSource+1; column<fileDestination; column++){
                if(board[rankSource][column]!=NULL){
                    return false;
                }
            }
            return true;
        }
        // if rook is moving to the left
        else{
            for(int column =fileSource-1; column>fileDestination; column--){
                if(board[rankSource][column]!=NULL){
                    return false;
                }
            }
            return true;
        }
    }

    // if moving along a file
    else if(fileSource==fileDestination){
        // check that the rook is not leaping over other pieces 
        // if rook is moving up the board
        if(rankDestination>rankSource){
            for(int row =rankSource+1; row<rankDestination; row++){
                if(board[row][fileSource]!=NULL){
                    return false;
                }
            }
            return true;
        }
        // if rook is moving to the left
        else{
            for(int row =rankSource-1; row>rankDestination; row--){
                if(board[row][rankSource]!=NULL){
                    return false;
                }
            }
            return true;
        }

    }
    // return false if the move is not along a rank or file
    return false;
}