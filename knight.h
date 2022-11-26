#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece.h"

class Knight: public Piece {
    private:
        bool isMoveValid(int rankStart, int fileStart, int rankEnd, int fileEnd, Piece* const board[8][8]);
    public:
        Knight(Colour _pieceColour);
        ~Knight();
};

#endif