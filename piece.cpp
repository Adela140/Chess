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

Piece::Piece(Colour _pieceColour, string _name): pieceColour(_pieceColour), name(_name){}

string Piece::printType() const{
    return name;
}

Piece::~Piece(){}
bool Piece::inCheck(Piece* board[8][8], Piece* _chessPiece[2][6]){return false;}
bool Piece::checkMate(Piece* board[8][8]){return false;}

bool Piece::isDestinationLegal(const char _destinationSquare[], Piece* board[8][8]){
    // convert positions to integer indeces
    int fileDestination = _destinationSquare[0]-'A';
    int rankDestination = _destinationSquare[1]-'1';

    //if the destination is not NULL, it cannot contain the same colour as the player
    if(board[rankDestination][fileDestination]!=NULL){
        if (board[rankDestination][fileDestination]->pieceColour == this->pieceColour){
            return false;
        }
    }
    return true;
}

const Colour Piece::get_colour() const {
    return pieceColour;
}

void Piece::printColour() {
    cout<< pieceColour;
}

bool Piece::canMove(const char source_square[], const char destination_square[], Piece* board[8][8], Piece* _chessPiece[2][6]){
    int fileSource= source_square[0]-'A';
    int fileDestination = destination_square[0]-'A';
    int rankSource = source_square[1]-'1';
    int rankDestination = destination_square[1]-'1';

    if(isDestinationLegal(destination_square, board) && isMoveValid(source_square, destination_square, board)){
        //check if the move would put your own king in check:
        // keep track of the destination piece that might be eaten
        Piece* destination_piece = board[rankDestination][fileDestination];
        Piece* source_piece = board[rankSource][fileSource];

        // move the piece to the destination square and remove it from source square
        board[rankDestination][fileDestination]=board[rankSource][fileSource];
        //cout<<"Assigned piece to new position"<<endl;
        board[rankSource][fileSource]=NULL;

        // is own king in check, if yes, reset the pointers to original squares
        if (((pieceColour == white) && (_chessPiece[0][0]->inCheck(board, _chessPiece))) || 
            ((pieceColour==black) && (_chessPiece[1][0]->inCheck(board, _chessPiece)))){
            board[rankSource][fileSource]=board[rankDestination][fileDestination];
            board[rankDestination][fileDestination]=destination_piece;
                
                return false;
            }
        board[rankSource][fileSource]=board[rankDestination][fileDestination];
        board[rankDestination][fileDestination]=destination_piece;

        return true;
    }
    return false;
}
    
    


