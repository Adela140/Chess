#ifndef ROOK_H
#define ROOK_H

#include "piece.h"

class Rook: public Piece {
    private:
        bool isMoveValid(const char _sourceSquare[], const char _destinationSquare[], Piece* board[8][8]);
    public:
        Rook(Colour _pieceColour);
        ~Rook();
};

#endif
