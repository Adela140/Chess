#ifndef ROOK_H
#define ROOK_H

#include "piece.h"

class Rook: public Piece {
    private:
        bool isMoveValid(int rankStart, int fileStart, int rankEnd, int fileEnd, Piece* const board[8][8]);
    public:
        Rook(Colour _pieceColour);
        ~Rook();
};

#endif
