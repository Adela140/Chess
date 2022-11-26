#ifndef BISHOP_H
#define BISHOP_H

#include "piece.h"

class Bishop: public Piece {
    private:
        bool isMoveValid(const char _sourceSquare[], const char _destinationSquare[], Piece* board[8][8]);
    public:
        Bishop(Colour _pieceColour);
        ~Bishop();
};

#endif