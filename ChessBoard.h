#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include "piece.h"

class ChessBoard{
    private:
        Colour Player;
        
        
        void changePlayer();
        bool inputsValid(const char _sourceSquare[], const char _destinationSquare[]);
        bool sourceNotEmpty(const char _sourceSquare[]);
        bool correctPlayer(const char _sourceSquare[]);
        void clearBoard();
        bool inCheck(Piece* king_ptr);

    public:

        Piece* chessPieces[2][6];
        Piece* board[8][8];
        ChessBoard();
        ~ChessBoard();
        void resetBoard();
        void getElement(const char _square[]);
        bool submitMove(const char source_square[], const char destination_square[]);
        void printBoard(Piece* board[8][8]);
    
    
};

#endif