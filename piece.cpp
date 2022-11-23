#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

#include "piece.h"

std::ostream& operator <<(std::ostream& out, Colour& _pieceColour){
    switch (_pieceColour) {
    case white:
        out << "White"; break;
    case black:
        out << "Black"; break;
    default:
        out << "invalid colour"; break;
    }
    return out;
}

Piece::Piece(Colour _pieceColour, string _name): pieceColour(_pieceColour), name(_name){}

string Piece::printType(){
    cout<< pieceColour<<endl;
    cout<< this->name<<endl;
    return name;
}

Piece::~Piece(){}

bool Piece::isDestinationLegal(const char _destinationSquare[], Piece* board[8][8]){
    // convert positions to integer indeces
    int fileDestination = _destinationSquare[0]-'A';
    int rankDestination = _destinationSquare[1]-'1';
    cout<<"In the function isDestinationLegal"<<endl;

    //if the destination is not NULL, it cannot contain the same colour as the player
    if(board[rankDestination][fileDestination]!=NULL){
        if (board[rankDestination][fileDestination]->pieceColour == this->pieceColour){
            cout<<"Destination is NOT legal"<<endl;
            return false;
        }
    }
    cout<<"Destination is legal"<<endl;
    return true;
}

const Colour Piece::get_colour() const {
    return pieceColour;
}

void Piece::printColour() {
    cout<< pieceColour;
}

bool Piece::canMove(const char source_square[], const char destination_square[], Piece* board[8][8]){
    if(isDestinationLegal(destination_square, board) && isMoveValid(source_square, destination_square, board)){
        cout<< pieceColour <<"'s "<< name << " moves to "<< destination_square <<"!"<<endl;
        return true;
    }
    cout<< pieceColour <<"'s "<< name << " cannot move to "<< destination_square <<"!"<<endl;
    return false;
}

King::King(Colour _pieceColour) : Piece(_pieceColour, "King"){}
King::~King(){}
bool King::isMoveValid(const char _sourceSquare[], const char _destinationSquare[], Piece* board[8][8]){
    // convert positions to integer indeces
    int fileSource= _sourceSquare[0]-'A';
    int fileDestination = _destinationSquare[0]-'A';
    int rankSource = _sourceSquare[1]-'1';
    int rankDestination = _destinationSquare[1]-'1';

    int rankDifference = rankDestination - rankSource;
    int fileDifference = fileDestination - fileSource;

    // return true if the destination position is within one 
    // square of the source position
    return(abs(rankDifference)<=1 && abs(fileDifference)<=1);
    
}


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

Bishop::Bishop(Colour _pieceColour) : Piece(_pieceColour, "Bishop"){}
Bishop::~Bishop(){}
bool Bishop::isMoveValid(const char _sourceSquare[], const char _destinationSquare[], Piece* board[8][8]){
    // convert positions to integer indeces
    int fileSource= _sourceSquare[0]-'A';
    int fileDestination = _destinationSquare[0]-'A';
    int rankSource = _sourceSquare[1]-'1';
    int rankDestination = _destinationSquare[1]-'1';

    // determine in which direction the bishop is moving
    int rankDirec = (rankDestination > rankSource) ? 1 : -1;
    int fileDirec = (fileDestination > fileSource) ? 1 : -1;

    // to move diagonally, the difference between the destination and source must be 
    // the same for the rank and file
    if((abs(rankDestination-rankSource))==(abs(fileDestination-fileSource))){
        // iterate through the diagonal in which the bishop is moving to check if it is leaping
        // over other pieces
        for(int row = rankSource+fileDirec, column = fileSource+fileDirec; row != rankDestination ; 
            row=row+rankDirec, column=column+fileDirec){
            if (board[row][column]!=NULL){
                return false;
            }
        }
        return true;
    }
    // if bishop not moving diagonally, return false
    return false;
}



Queen::Queen(Colour _pieceColour) : Piece(_pieceColour, "Queen"){}
Queen::~Queen(){}
bool Queen::isMoveValid(const char _sourceSquare[], const char _destinationSquare[], Piece* board[8][8]){
    // convert positions to integer indeces
    int fileSource= _sourceSquare[0]-'A';
    int fileDestination = _destinationSquare[0]-'A';
    int rankSource = _sourceSquare[1]-'1';
    int rankDestination = _destinationSquare[1]-'1';

    // determine in which direction the queen is moving
    int rankDirec;
    int fileDirec;
    if(rankDestination>rankSource){
        rankDirec=1;
    }
    else if(rankDestination==rankSource){
        rankDirec=0;
    }
    else
        rankDirec=-1;

    if(fileDestination>fileSource){
        fileDirec=1;
    }
    else if(fileDestination==fileSource){
        fileDirec=0;
    }
    else
        fileDirec=-1;

    // check that the queen is either moving diagonally or along a file or rank
    if((rankDestination==rankSource)||(fileDestination==fileSource)||
        ((abs(rankDestination-rankSource))==(abs(fileDestination-fileSource)))){
        
        // check if the queen is leaping over some pieces
        for(int row=rankSource+rankDirec, column=fileSource+fileDirec; row!=rankDestination
            || column!=fileDestination; row=row+rankDirec, column=column+fileDirec){
                if(board[row][column]!=NULL){
                    return false;
                }
        }
        return true;
    }
    // return false if not moving either diagonally or along a file or rank
    return false;
}

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
        if((rankDestination-rankSource==1) && (abs(fileDestination-fileSource)==1)){
            return true;
        }
        return false;
    }
    // if moving to unoccupied square
    else if(board[rankDestination][fileDestination]==NULL){
        
        // if the first move(so the _sourceSquare has rank 1 or 6), it can move up to two places
        if (rankSource == 1 || rankSource ==6){
            // check if the pawn is leaping over a piece if moving two squares forward
            if((fileDestination==fileSource) && (rankDestination-rankSource==2)){
                for(int row = rankSource+1; row<=rankDestination; row++){
                    if(board[row][fileSource]!=NULL){
                        return false;
                    }
                }
            
            return true;       
            }
            // if moving one square forward
            else if((fileDestination==fileSource) && (rankDestination-rankSource==1)){
                
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
    
    


