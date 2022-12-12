#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

#include "pawn.h"

/************************ Definitions for Pawn class *************************/

/* Constructs the Pawn object */
Pawn::Pawn(Colour _pieceColour) : Piece("Pawn", _pieceColour){}

/* Destructs the Pawn object */
Pawn::~Pawn(){}

/* Returns true if Pawn moving legally */
bool Pawn::legalPieceMove(int rankStart, int fileStart, int rankEnd, 
                          int fileEnd, const ChessBoard* const _cb){
    int rankDirec;
    // if pawn is white, rank direction must be +1
    // if pawn is black, rank direction must be -1
    if(pieceColour==white){rankDirec=1;}
    else if(pieceColour==black){rankDirec=-1;}
    // if capturing another piece 
    if(_cb->get_piece(rankEnd,fileEnd)!=NULL){
        // check if the move is one square diagonally in front of the source 
        // square if pawn is white destination rank must be larger by one
        // if black it must be smaller by one
        if(((rankEnd-rankStart==rankDirec) && (abs(fileEnd-fileStart)==1))){
            return true;
        }
        return false;
    }
    // if moving to unoccupied square
    else if(_cb->get_piece(rankEnd,fileEnd)==NULL){
        
        // if the first move(so the _sourceSquare has rank 1 or 6), 
        // it can move up to two places
        if (rankStart == 1 || rankStart ==6){
            // check if the pawn is leaping over a piece if moving two squares forward
            if((fileEnd==fileStart) && ((rankEnd-rankStart)==(2*rankDirec))){
                for(int row = rankStart+rankDirec; row!=rankEnd; row=row+rankDirec){
                    // return false if encountering a piece before the destination square
                    if(_cb->get_piece(row,fileStart)!=NULL){
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