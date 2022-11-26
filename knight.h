#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece.h"

class Knight: public Piece {
    private:
        bool isMoveValid(const char _sourceSquare[], const char _destinationSquare[], Piece* board[8][8]);
    public:
        Knight(Colour _pieceColour);
        ~Knight();
};

#endif