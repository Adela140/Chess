#ifndef PAWN_H
#define PAWN_H

#include "piece.h"
#include "ChessBoard.h"

/************************ Declarations for Pawn class ************************/
/* Knight inherits from Pawn class */

class Pawn: public Piece {
    private:
        /* Returns true if:
            - first move and moving one OR two squares right in front of it 
              (but not leaping over other pieces), OR
            - not a first move and moving one square right in front of it, OR
            - capturing another piece and moving one piece diagonally (but not backwards)
         * Parameters: integer indeces of rank and files of the source and 
           destination, and pointer to a ChessBoard object */
        bool legalPieceMove(int rankStart, int fileStart, int rankEnd, 
                            int fileEnd, const ChessBoard* const _cb);
    public:
        /* Contructs a Pawn object with default name (inherited from Piece) "Pawn"
         * Parameters: colour of the piece (White or Black) */
        Pawn(Colour _pieceColour);

        /* Destructs the Pawn object */
        ~Pawn();
        
};

#endif