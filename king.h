#ifndef KING_H
#define KING_H

#include "piece.h"

/***************************** Declarations for King class ******************************/
/* King inherits from Piece class */

class King: public Piece {
    private:
        /* Returns true if moving one square in any direction
         * Parameters: integer indeces of rank and files of the source and destination, 
           and the 8x8 board containing current state of the game */
        bool legalPieceMove(int rankStart, int fileStart, int rankEnd, int fileEnd, 
                            Piece* const board[8][8]);
    public:
        /* Contructs a King object with default name (inherited from Piece) "King"
         * Parameters: colour of the piece (White or Black) */
        King(Colour _pieceColour);

        /* Destructs the King object */
        ~King();

        /* Returns true if King is in check
         * Parameters: 8x8 board and _chessPiece matrix containing the king pointers 
            - the king pointers are needed because the method checks for any valid moves
              of other player's pieces which do not put its own king in check */
        bool inCheck(Piece* board[8][8], Piece* const _chessPiece[2][6]);
};

#endif