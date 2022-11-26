#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include "piece.h"

class ChessBoard{
    private:
        Colour Player;
        Piece* chessPieces[2][6];
        Piece* board[8][8];
        
        void changePlayer();
        bool inputsValid(const char _sourceSquare[], const char _destinationSquare[]);
        bool sourceNotEmpty(int start_row, int start_column);
        bool correctPlayer(int start_row, int start_column);
        void clearBoard();
        bool inCheck(Piece* king_ptr);
        bool checkMate(Colour _player);

    public:
        /* Constructs the ChessBoard to contain an 8x8 board with pieces set up
         * Sets the first player to be white by default*/
        ChessBoard();

        /* Destructs the ChessBoard and all the pieces created on the heap*/
        ~ChessBoard();

        /* Resets the 8x8 board in ChessBoard to contain original set up */ 
        void resetBoard();

        /* Requests a move with a piece in source_square to destination_square 
         * If the inputs are correct, the player is valid, and the move is legal
           it changes the destination square to contain the piece from source square,
           checks if the move puts the other player in check/checkmate 
           and changes the player */
        bool submitMove(const char source_square[], const char destination_square[]);
        
        void getElement(const char _square[]);
        
        void printBoard();
    
    
};

#endif