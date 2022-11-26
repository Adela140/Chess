#ifndef KING_H
#define KING_H

#include "piece.h"

class King: public Piece {
    private:
        bool isMoveValid(const char _sourceSquare[], const char _destinationSquare[], Piece* board[8][8]);
    public:
        bool inCheck(Piece* board[8][8],  Piece* _chessPiece[2][6]);
        King(Colour _pieceColour);
        ~King();
};

#endif