#ifndef QUEEN_H
#define QUEEN_H

#include "piece.h"

class Queen: public Piece {
    private:
        bool isMoveValid(const char _sourceSquare[], const char _destinationSquare[], Piece* board[8][8]);
    public:
        Queen(Colour _pieceColour);
        ~Queen();
};

#endif