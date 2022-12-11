#ifndef BISHOP_H
#define BISHOP_H

#include "piece.h"
#include "ChessBoard.h"

/*********************** Declarations for Bishop class ***********************/
/* Bishop inherits from Piece class */

class Bishop: public Piece {
    private:
        /* Returns true if moving diagonally but not leaping over other pieces 
         * Parameters: integer indeces of rank and files of the source and the 
           destination, and pointer to a ChessBoard object */
        bool legalPieceMove(int rankStart, int fileStart, int rankEnd, 
                            int fileEnd, const ChessBoard* const _cb);
    public:
        /* Contructs a Bishop object with default name (inherited from Piece) "Bishop"
         * Parameters: colour of the piece (White or Black) */
        Bishop(Colour _pieceColour);

        /* Destructs the Bishop object */
        ~Bishop();
};

#endif