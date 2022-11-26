#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

#include "piece.h"
#include "pawn.h"

Pawn::Pawn(Colour _pieceColour) : Piece(_pieceColour, "Pawn"){}
Pawn::~Pawn(){}
bool Pawn::isMoveValid(int rankStart, int fileStart, int rankEnd, int fileEnd, Piece* const board[8][8]){

    // if capturing another piece 
    if(board[rankEnd][fileEnd]!=NULL){
        // check if the move is one square diagonally in front of the source squre
        // if pawn is white destination rank must be larger by one
        // if black it must be smaller by one
        if(((pieceColour==white) 
            && (rankEnd-rankStart==1) && (abs(fileEnd-fileStart)==1))
        || ((pieceColour==black) 
            && (rankEnd-rankStart==-1) && (abs(fileEnd-fileStart)==1))){
            return true;
        }
        return false;
    }
    // if moving to unoccupied square
    else if(board[rankEnd][fileEnd]==NULL){
        
        // if the first move(so the _sourceSquare has rank 1 or 6), it can move up to two places
        if (rankStart == 1 || rankStart ==6){
            // check if the pawn is leaping over a piece if moving two squares forward
            if((fileEnd==fileStart) && (abs(rankEnd-rankStart)==2)){
                for(int row = rankStart+1; row<=rankEnd; row++){
                    if(board[row][fileStart]!=NULL){
                        return false;
                    }
                }
            
                return true;       
            }
            // if moving one square forward
            else if((fileEnd==fileStart) && (abs(rankEnd-rankStart)==1)){
                
                return true;
            }
            return false;
        }
        // if not the pawn's first move, it can move one square forward
        if((fileEnd==fileStart) && (rankEnd-rankStart==1)){
            
            return true;
        }
        return false;
    }
    return false;
}