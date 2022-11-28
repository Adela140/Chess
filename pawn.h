#ifndef PAWN_H
#define PAWN_H

#include "piece.h"
#include "ChessBoard.h"

class ChessBoard;

/***************************** Declarations for Pawn class ******************************/
/* Knight inherits from Pawn class */

class Pawn: public Piece {
    private:
        /* Returns true if:
            - first move and moving one OR two squares right in front of it (but not
              leaping over other pieces)
            - not a first move and moving one square right in front of it 
            - capturing another piece and moving one piece diagonally (but not backwards)
         * Parameters: integer indeces of rank and files of the source and destination, 
           and the 8x8 board containing current state of the game */
        bool legalPieceMove(int rankStart, int fileStart, int rankEnd, int fileEnd, const ChessBoard* const _cb);
    public:
        /* Contructs a Pawn object with default name (inherited from Piece) "Pawn"
         * Parameters: colour of the piece (White or Black) */
        Pawn(Colour _pieceColour);

        /* Destructs the Pawn object */
        ~Pawn();
        
};

#endif