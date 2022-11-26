#ifndef KING_H
#define KING_H

#include "piece.h"

class King: public Piece {
    private:
        bool isMoveValid(int rankStart, int fileStart, int rankEnd, int fileEnd, Piece* const board[8][8]);
    public:
        bool inCheck(Piece* board[8][8], Piece* const _chessPiece[2][6]);
        King(Colour _pieceColour);
        ~King();
};

#endif