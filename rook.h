#ifndef ROOK_H
#define ROOK_H

#include "piece.h"
#include "ChessBoard.h"

/***************************** Declarations for Rook class ******************************/
/* Rook inherits from Piece class */

class Rook: public Piece {
    private:
        /* Returns true if moving along a rank or file but not leaping over other pieces 
         * Parameters: integer indeces of rank and files of the source and destination, 
           and pointer to a ChessBoard object */
        bool legalPieceMove(int rankStart, int fileStart, int rankEnd, int fileEnd, 
                            const ChessBoard* const _cb);
    
        bool hasMovedA; // keeps track if rook has moved if starting at file A (for castling)
        bool hasMovedH; // keeps track if rook has moved if starting at file H (for castling)
    
    friend class ChessBoard; // allows ChessBoard to access 'hasMoved' for castling
    
    public:
        /* Contructs a Rook object with default name (inherited from Piece) "Rook"
         * Parameters: colour of the piece (White or Black) */
        Rook(Colour _pieceColour);

        /* Destructs the Rook object */
        ~Rook();
};

#endif
