#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

#include "piece.h"
#include "pawn.h"

/**************************** Definitions for Pawn class ********************************/

/* Constructs the Pawn object */
Pawn::Pawn(Colour _pieceColour) : Piece(_pieceColour, "Pawn"){}

/* Destructs the Pawn object */
Pawn::~Pawn(){}

/* Returns true if Pawn moving legally */
bool Pawn::legalPieceMove(int rankStart, int fileStart, int rankEnd, int fileEnd, 
                          Piece* const board[8][8]){
    int rankDirec;
    // if pawn is white, rank direction must be +1
    // if pawn is black, rank direction must be -1
    if(pieceColour==white){rankDirec=1;}
    else if(pieceColour==black){rankDirec=-1;}
    // if capturing another piece 
    if(board[rankEnd][fileEnd]!=NULL){
        // check if the move is one square diagonally in front of the source square
        // if pawn is white destination rank must be larger by one
        // if black it must be smaller by one
        if(((rankEnd-rankStart==rankDirec) && (abs(fileEnd-fileStart)==1))){
            return true;
        }
        return false;
    }
    // if moving to unoccupied square
    else if(board[rankEnd][fileEnd]==NULL){
        
        // if the first move(so the _sourceSquare has rank 1 or 6), 
        // it can move up to two places
        if (rankStart == 1 || rankStart ==6){
            // check if the pawn is leaping over a piece if moving two squares forward
            if((fileEnd==fileStart) && ((rankEnd-rankStart)==(2*rankDirec))){
                for(int row = rankStart+rankDirec; row!=rankEnd; row=row+rankDirec){
                    // return false if encountering a piece before the destination square
                    if(board[row][fileStart]!=NULL){
                        return false;
                    }
                }
                return true;       
            }
            // if moving one square forward
            else if((fileEnd==fileStart) && ((rankEnd-rankStart)==rankDirec)){
                
                return true;
            }
            return false;
        }
        // if not the pawn's first move, it can move one square forward
        if((fileEnd==fileStart) && (rankEnd-rankStart==rankDirec)){
            
            return true;
        }
        return false;
    }
    return false;
}