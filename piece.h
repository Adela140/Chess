#ifndef PIECE_H
#define PIECE_H

#include <string>
using namespace std;

/***************************** Declarations for Colour type ******************************/
enum Colour{white, black};

/* Overriding the << operator for Colour
* Prints out the colour "White" or "Black" */
std::ostream& operator << (std::ostream& out, Colour _colour);

/* Overriding the ! operator for Colour
* Changes colour to the opposite colour (from white to black and from black to white) */
Colour operator!(Colour _colour);

/***************************** Declarations for Piece class ******************************/

class Piece {
    private:

    protected:
        Colour pieceColour; // White or Black
        string name; // name of the chess piece

        /* Returns true if the destination square does not contain a piece 
           of the same colour
         * Parameters: integer indeces of the destination square and 8x8 board*/
        bool isDestinationLegal(int rankEnd, int fileEnd, Piece* const board[8][8]);

        /* Pure virtual function 
         * When implemented by the chess pieces (derived classes), it returns true if 
           the move is legal according to the piece's rules 
         * Parameters: integer indeces of rank and files of the source and destination, 
           and the 8x8 board containing current state of the game */
        virtual bool legalPieceMove(int rankStart, int fileStart, int rankEnd, int fileEnd, 
                                    Piece* const board[8][8]) =0;
        
        /* Checks if a king is in check 
         * For any Piece that is not a King, it returns false 
         * It is virtual as the King inherits and implements the method
         * Parameters: 8x8 board and _chessPiece matrix containing the king pointers 
            - the king pointers are needed because the method checks for any valid moves
              of other player's pieces which do not put its own king in check */
        virtual bool inCheck(Piece* board[8][8], Piece* const _chessPiece[2][6]);

    friend class ChessBoard; 
    public:
        /* Contructs a Piece object 
         * Parameters: colour of the piece (White or Black) and name of the chess piece */
        Piece(Colour _pieceColour, string _name);

        /* Destructs the Piece object */
        virtual ~Piece();

        /* Returns true if the move of the piece is valid
         * It checks for whether the destination square is not of the same colour, 
           that the piece is moving according to its rules, and that the move is 
           not putting your own king in check
         * Parameters: integer indeces of rank and files of the source and destination, 
           and the 8x8 board containing current state of the game, and chessPiece matrix
           containing the king pointers */
        bool isMoveValid(int rankStart, int fileStart, int rankEnd, int fileEnd, 
                    Piece* board[8][8], Piece* const _chessPiece[2][6]);

        /* Returns the colour of the piece */
        const Colour get_colour() const;
};

#endif