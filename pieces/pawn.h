#ifndef PAWN_H
#define PAWN_H

#include "chessBoard.h"


enum Colour{white, black};

class Pawn{
    private: 
        string name = "pawn";
        Colour pieceColour;
        bool moveValid(const char source_square[], const char destination_square[]);

    public:
        Pawn(Colour pieceColour, bool inCheck);

};


#endif