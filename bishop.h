#ifndef BISHOP_H
#define BISHOP_H

#include "piece.h"

/**************************** Declarations for Bishop class ******************************/
/* Bishop inherits from Piece class */

class Bishop: public Piece {
    private:
        /* Returns true if moving diagonally but not leaping over other pieces 
         * Parameters: integer indeces of rank and files of the source and destination, 
           and the 8x8 board containing current state of the game */
        bool legalPieceMove(int rankStart, int fileStart, int rankEnd, int fileEnd, 
                            Piece* const board[8][8]);
    public:
        /* Contructs a Bishop object with default name (inherited from Piece) "Bishop"
         * Parameters: colour of the piece (White or Black) */
        Bishop(Colour _pieceColour);

        /* Destructs the Bishop object */
        ~Bishop();
};

#endif