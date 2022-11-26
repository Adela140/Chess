#ifndef PIECE_H
#define PIECE_H

#include <string>
using namespace std;

enum Colour{white, black};
std::ostream& operator << (std::ostream& out, Colour _colour);

/* Overriding the ++ operator for Colour
* Changes colour from white to black and from black to white */
Colour operator++(Colour& _colour);


class Piece {
    private:

    protected:
        Colour pieceColour;
        string name;
        bool isDestinationLegal(int rankEnd, int fileEnd, Piece* const board[8][8]);
        virtual bool isMoveValid(int rankStart, int fileStart, int rankEnd, int fileEnd, Piece* const board[8][8]) =0;
        virtual bool inCheck(Piece* board[8][8], Piece* const _chessPiece[2][6]);
        virtual bool checkMate(Piece* const board[8][8]);

    friend class ChessBoard; 
    public:
        Piece(Colour _pieceColour, string _name);
        virtual ~Piece();
        bool canMove(int rankStart, int fileStart, int rankEnd, int fileEnd, 
                    Piece* board[8][8], Piece* const _chessPiece[2][6]);
        const Colour get_colour() const;
};

#endif