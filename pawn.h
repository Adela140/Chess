#ifndef PAWN_H
#define PAWN_H

#include "piece.h"

class Pawn: public Piece {
    private:
        bool isMoveValid(int rankStart, int fileStart, int rankEnd, int fileEnd, Piece* const board[8][8]);
    public:
        Pawn(Colour _pieceColour);
        ~Pawn();
        
};

#endif