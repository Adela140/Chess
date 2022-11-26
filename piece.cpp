#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

#include "piece.h"

std::ostream& operator <<(std::ostream& out, Colour _pieceColour){
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
Colour operator++(Colour& _colour){
    _colour = static_cast<Colour>((static_cast<int>(_colour) + 1) % 2);
    return _colour;
}

Piece::Piece(Colour _pieceColour, string _name): pieceColour(_pieceColour), name(_name){}

Piece::~Piece(){}
bool Piece::inCheck(Piece* board[8][8], Piece* const _chessPiece[2][6]){return false;}
bool Piece::checkMate(Piece* const board[8][8]){return false;}

bool Piece::isDestinationLegal(int rankEnd, int fileEnd, Piece* const board[8][8]){

    //if the destination is not NULL, it cannot contain the same colour as the player
    if(board[rankEnd][fileEnd]!=NULL){
        if (board[rankEnd][fileEnd]->pieceColour == this->pieceColour){
            return false;
        }
    }
    return true;
}

const Colour Piece::get_colour() const {
    return pieceColour;
}

bool Piece::canMove(int rankStart, int fileStart, int rankEnd, int fileEnd, Piece* board[8][8], Piece* const _chessPiece[2][6]){

    if(isDestinationLegal(rankEnd, fileEnd, board)
        && isMoveValid(rankStart, fileStart, rankEnd, fileEnd, board)){
        //check if the move would put your own king in check:
        // keep track of the destination piece that might be eaten
        Piece* destination_piece = board[rankEnd][fileEnd];

        // move the piece to the destination square and remove it from source square
        board[rankEnd][fileEnd]=board[rankStart][fileStart];
        //cout<<"Assigned piece to new position"<<endl;
        board[rankStart][fileStart]=NULL;

        // is own king in check, if yes, reset the pointers to original squares
        if (((pieceColour == white) && (_chessPiece[0][0]->inCheck(board, _chessPiece))) || 
            ((pieceColour==black) && (_chessPiece[1][0]->inCheck(board, _chessPiece)))){
            board[rankStart][fileStart]=board[rankEnd][fileEnd];
            board[rankEnd][fileEnd]=destination_piece;
                
                return false;
            }
        board[rankStart][fileStart]=board[rankEnd][fileEnd];
        board[rankEnd][fileEnd]=destination_piece;

        return true;
    }
    return false;
}
    
    


