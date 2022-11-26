#ifndef ROOK_H
#define ROOK_H

#include "piece.h"

/***************************** Declarations for Rook class ******************************/
/* Rook inherits from Piece class */

class Rook: public Piece {
    private:
        /* Returns true if moving along a rank or file but not leaping over other pieces 
         * Parameters: integer indeces of rank and files of the source and destination, 
           and the 8x8 board containing current state of the game */
        bool legalPieceMove(int rankStart, int fileStart, int rankEnd, int fileEnd, 
                            Piece* const board[8][8]);
    public:
        /* Contructs a Rook object with default name (inherited from Piece) "Rook"
         * Parameters: colour of the piece (White or Black) */
        Rook(Colour _pieceColour);

        /* Destructs the Rook object */
        ~Rook();
};

#endif
