#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

#include "piece.h"
#include "pawn.h"

Pawn::Pawn(Colour _pieceColour) : Piece(_pieceColour, "Pawn"){}
Pawn::~Pawn(){}
bool Pawn::isMoveValid(const char _sourceSquare[], const char _destinationSquare[], Piece* board[8][8]){
    
    // convert positions to integer indeces
    int fileSource= _sourceSquare[0]-'A';
    int fileDestination = _destinationSquare[0]-'A';
    int rankSource = _sourceSquare[1]-'1';
    int rankDestination = _destinationSquare[1]-'1';

    // if capturing another piece 
    if(board[rankDestination][fileDestination]!=NULL){
        // check if the move is one square diagonally in front of the source squre
        // if pawn is white destination rank must be larger by one
        // if black it must be smaller by one
        if(((pieceColour==white) 
            && (rankDestination-rankSource==1) && (abs(fileDestination-fileSource)==1))
        || ((pieceColour==black) 
            && (rankDestination-rankSource==-1) && (abs(fileDestination-fileSource)==1))){
            return true;
        }
        return false;
    }
    // if moving to unoccupied square
    else if(board[rankDestination][fileDestination]==NULL){
        
        // if the first move(so the _sourceSquare has rank 1 or 6), it can move up to two places
        if (rankSource == 1 || rankSource ==6){
            // check if the pawn is leaping over a piece if moving two squares forward
            if((fileDestination==fileSource) && (abs(rankDestination-rankSource)==2)){
                for(int row = rankSource+1; row<=rankDestination; row++){
                    if(board[row][fileSource]!=NULL){
                        return false;
                    }
                }
            
                return true;       
            }
            // if moving one square forward
            else if((fileDestination==fileSource) && (abs(rankDestination-rankSource)==1)){
                
                return true;
            }
            return false;
        }
        // if not the pawn's first move, it can move one square forward
        if((fileDestination==fileSource) && (rankDestination-rankSource==1)){
            
            return true;
        }
        return false;
    }
    return false;
}