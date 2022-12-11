#ifndef QUEEN_H
#define QUEEN_H

#include "piece.h"
#include "ChessBoard.h"

/************************ Declarations for Queen class ***********************/
/* Queen inherits from Piece class */

class Queen: public Piece {
    private:
        /* Returns true if moving along a rank, file or diagonally 
           but not leaping over other pieces 
         * Parameters: integer indeces of rank and files of the source and 
           destination, and pointer to a ChessBoard object */
        bool legalPieceMove(int rankStart, int fileStart, int rankEnd, 
                            int fileEnd, const ChessBoard* const _cb);
    public:
        /* Contructs a Queen object with default name (inherited from Piece) "Queen"
         * Parameters: colour of the piece (White or Black) */
        Queen(Colour _pieceColour);

        /* Destructs the Queen object */
        ~Queen();
};

#endif