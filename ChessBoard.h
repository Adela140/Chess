#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include "piece.h"

/************************** Declarations for ChessBoard class ***************************/

/* ChessBoard provides an interface through which players can interact with 
   chess pieces in an 8x8 board */

class ChessBoard{
    private:
        Colour player; // the colour of the current player
        Piece* chessPieces[2][6]; // matrix of all the pieces needed in chess
        Piece* board[8][8]; // 8x8 chess board
        bool gameOver;
        
        /* Changes 'player' attribute from white to black and from black to white */
        void changePlayer();

        /* Returns true if the coordinates of source and destination square:
            - are only two characters, and
            - are not the same coordinates, and
            - are in range 
         * Parameters: both squares are referred to with A-H for rank and 1-8 for file 
           (eg. 'A1' refers to first row and first column) */
        bool inputsValid(const char _sourceSquare[], const char _destinationSquare[]);

        /* Returns true if the source square is not empty (NULL)
         * Parameters: integer indeces indicating the row and column of start square */
        bool sourceNotEmpty(int start_row, int start_column);

        /* Returns true if the correct player is making the move
           so that the colour of the source square piece is the same as the 'player'
         * Parameters: integer indeces indicating the row and column of start square */
        bool correctPlayer(int start_row, int start_column);

        /* Sets all the squares in the 8x8 board to null */
        void clearBoard();

        /* Returns true if the '_player' can make any valid move with any of its pieces */
        bool canMove(Colour _player);

        /* Returns true if the current player made the other player be in checkmate or
           stalemate */
        bool endOfGame();

    public:
        /* Constructs the ChessBoard to contain an 8x8 board with pieces set up
         * Sets the first player to be white and gameOver to be false by default*/
        ChessBoard();

        /* Destructs the ChessBoard and all the pieces created on the heap*/
        ~ChessBoard();

        /* Resets the 8x8 board in ChessBoard to contain original set up */ 
        void resetBoard();

        /* Requests a move with a piece in source_square to destination_square 
         * If the inputs are correct, the player is valid, and the move is legal
           it changes the destination square to contain the piece from source square,
           checks if the move puts the other player in check/checkmate/stalemate 
           and changes the player 
         * If the move results in checkmate/stalemate, 'gameOver' is set to true
         * Parameters: both squares are referred to with A-H for rank and 1-8 for file 
           (eg. 'A1' refers to first row and first column) */
        bool submitMove(const char source_square[], const char destination_square[]);
        
        /* Prints current status of the 8x8 board */
        void printBoard();
    
};

#endif