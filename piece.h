#ifndef PIECE_H
#define PIECE_H

#include <string>
using namespace std;

class ChessBoard;

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
        string name; // name of the chess piece
    protected:
        Colour pieceColour; // White or Black
        
        /* Returns true if the destination square does not contain a piece 
           of the same colour
         * Parameters: integer indeces of the destination square 
           and pointer to a ChessBoard object */
        bool isDestinationLegal(int rankEnd, int fileEnd, const ChessBoard* const _cb);

        /* Pure virtual function 
         * When implemented by the chess pieces (derived classes), it returns true if 
           the move is legal according to the piece's rules 
         * Parameters: integer indeces of rank and files of the source and destination, 
           and pointer to a ChessBoard object */
        virtual bool legalPieceMove(int rankStart, int fileStart, int rankEnd, int fileEnd, 
                                    const ChessBoard* const _cb) =0;
        
        /* Returns true if the move of the piece is valid 
         * It checks for whether the destination square is not of the same colour and 
           that the piece is moving according to its rules
         * Parameters: integer indeces of rank and files of the source and destination, 
           and pointer to a ChessBoard object */
        bool isMoveValid(int rankStart, int fileStart, int rankEnd, int fileEnd, 
                         const ChessBoard* const _cb);

    friend class ChessBoard; 
    
    public:
        /* Contructs a Piece object 
         * Parameters: colour of the piece (White or Black) and name of the chess piece */
        Piece(string _name, Colour _pieceColour);

        /* Destructs the Piece object */
        virtual ~Piece();   

};

#endif