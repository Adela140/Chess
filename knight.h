#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece.h"
#include "ChessBoard.h"

class ChessBoard;

/***************************** Declarations for Knight class *****************************/
/* Knight inherits from Piece class */

class Knight: public Piece {
    private:
        /* Returns true if moving two squares vertically and one square horizontally, 
           or two squares horizontally and one square vertically
         * Parameters: integer indeces of rank and files of the source and destination, 
           and the 8x8 board containing current state of the game */
        bool legalPieceMove(int rankStart, int fileStart, int rankEnd, int fileEnd, 
                            const ChessBoard* const _cb);
    public:
        /* Contructs a Knight object with default name (inherited from Piece) "Knight"
         * Parameters: colour of the piece (White or Black) */
        Knight(Colour _pieceColour);

        /* Destructs the Knight object */
        ~Knight();
};

#endif