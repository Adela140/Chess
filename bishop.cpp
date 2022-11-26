#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

#include "piece.h"
#include "bishop.h"

Bishop::Bishop(Colour _pieceColour) : Piece(_pieceColour, "Bishop"){}
Bishop::~Bishop(){}
bool Bishop::isMoveValid(int rankStart, int fileStart, int rankEnd, int fileEnd, Piece* const board[8][8]){

    // determine in which direction the bishop is moving
    int rankDirec = (rankEnd > rankStart) ? 1 : -1;
    int fileDirec = (fileEnd > fileStart) ? 1 : -1;

    // to move diagonally, the difference between the destination and source must be 
    // the same for the rank and file
    if((abs(rankEnd-rankStart))==(abs(fileEnd-fileStart))){
        // iterate through the diagonal in which the bishop is moving to check if it is leaping
        // over other pieces
        //cout<<"Bishop moving diagonally"<<endl;
        //cout<<"rankDir: "<<rankDirec<<" and fileDirec:"<<fileDirec<<endl;
        for(int row = rankStart+rankDirec, column = fileStart+fileDirec; row != rankEnd ; 
            row=row+rankDirec, column=column+fileDirec){
            if (board[row][column]!=NULL){
                return false;
            }
            //cout<<"Bishop moving freely"<<endl;
        }
        return true;
    }
    // if bishop not moving diagonally, return false
    return false;
}