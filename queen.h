#ifndef QUEEN_H
#define QUEEN_H

#include "piece.h"

class Queen: public Piece {
    private:
        bool isMoveValid(int rankStart, int fileStart, int rankEnd, int fileEnd, Piece* const board[8][8]);
    public:
        Queen(Colour _pieceColour);
        ~Queen();
};

#endif