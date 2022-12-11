#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include "piece.h"

/********************* Declarations for ChessBoard class *********************/

/* ChessBoard provides an interface through which players can interact with 
   chess pieces in an 8x8 board */

class ChessBoard{

   private:

      Colour player; // the colour of the current player
      Piece* chessPieces[2][6]; // matrix of all the pieces needed in chess
      Piece* board[8][8]; // 8x8 chess board
      bool gameOver;
      bool validCastling; // set to true if validCastlingMove returns true

      // matrix containing boolean on whether a piece has moved (used for castling)
      // row contains player: 0: white, 1: black
      // column contains type of piece: 0: king, 1:rook from file A, 2: rook from file H
      // for example, hasMoved[1][2] is false if Black's rook from file H has not moved
      bool hasMoved[2][3];
      
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

      /* Returns true if the destination square does not contain a piece 
         of the same colour as we are trying to move
       * Parameters: integer indeces of the source and destination squares */
      bool isDestinationLegal(int rankStart, int fileStart, int rankEnd, int fileEnd);

      /* Returns true if King is in check
       * Parameters: player (White or Black) for which we want to determine if their king
         is in check */
      bool inCheck(Colour player);

      /* Returns true if the move is valid with respect to the piece and the destination,
         and if the move does not put your own king in check */
      bool validMoveNoCheck(int start_row, int start_column, int end_row, int end_column);

      /* Returns true if the '_player' can make any valid move with any of its pieces */
      bool canMove(Colour _player);

      /* Returns true if the current player made the other player be in checkmate or
         stalemate */
      bool endOfGame();

      /* Returns true if the castling move is valid: 
         - if source quare contains a king and destination is two squares away along the 
           same rank AND 
         - if neither the king or rook involved have moved before AND
         - if there are no pieces between the king and the rook AND
         - if the king is not leaving, crossing over or ending up in a square that is 
           under attack from an opponent's piece 
       * Parameters: rank and file of king (start square) and destination square
         which is two squares away along the same rank */
      bool validCastlingMove(int rankStart, int fileStart, int rankEnd, int fileEnd);

      /* Sets all the squares in the 8x8 board to null */
      void clearBoard();

   public:

      /* Constructs the ChessBoard to contain an 8x8 board with pieces set up
       * Sets the first player to be white and gameOver to be false by default*/
      ChessBoard();

      /* Destructs the ChessBoard and all the pieces created on the heap*/
      ~ChessBoard();

      /* Resets the 8x8 board in ChessBoard to contain original set up */ 
      void resetBoard();

      /* Requests a move with a piece in source_square to destination_square 
       * In order to do castling, source square must contain the king and destination
         square must be two squares along the same rank
       * If the inputs are correct, the player is valid, and the move is legal
         it updates the board according to the move, checks if the move puts 
         the other player in check/checkmate/stalemate and changes the player 
       * If the move results in checkmate/stalemate, 'gameOver' is set to true
       * Parameters: both squares are referred to with A-H for rank and 1-8 for file 
         (eg. 'A1' refers to first row and first column) */
      bool submitMove(const char source_square[], const char destination_square[]);
      
      /* Prints current status of the 8x8 board */
      void printBoard();

      /* Returns a pointer to the piece in position board[rank][file] 
       * Parameters: rank and file of the square you want to return */
      const Piece* get_piece(int rank, int file) const;
    
};

#endif