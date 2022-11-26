#ifndef PAWN_H
#define PAWN_H

#include "piece.h"

class Pawn: public Piece {
    private:
        bool isMoveValid(const char _sourceSquare[], const char _destinationSquare[], Piece* board[8][8]);
    public:
        Pawn(Colour _pieceColour);
        ~Pawn();
        
};

#endif