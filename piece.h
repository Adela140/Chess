#ifndef PIECE_H
#define PIECE_H

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

enum Colour{white, black};
std::ostream& operator << (std::ostream& out, Colour _lightColour);


class Piece {
    private:

    protected:
        Colour pieceColour;
        string name;
        bool isDestinationLegal(const char _destinationSquare[], Piece* board[8][8]);
        virtual bool isMoveValid(const char source_square[], const char destination_square[], Piece* board[8][8]) =0;

    friend class ChessBoard; 
    public:
        Piece(Colour _pieceColour, string _name);
        virtual ~Piece();
        bool canMove(const char source_square[], const char destination_square[], Piece* board[8][8]);
        const Colour get_colour() const;
        void printColour();
        string printType() const;
};

//put every attribute as virtual
// in oawn have virtual bool moveValid()


class King: public Piece {
    private:
        bool isMoveValid(const char _sourceSquare[], const char _destinationSquare[], Piece* board[8][8]);
    public:
        King(Colour _pieceColour);
        ~King();
};

class Rook: public Piece {
    private:
        bool isMoveValid(const char _sourceSquare[], const char _destinationSquare[], Piece* board[8][8]);
    public:
        Rook(Colour _pieceColour);
        ~Rook();
};

class Bishop: public Piece {
    private:
        bool isMoveValid(const char _sourceSquare[], const char _destinationSquare[], Piece* board[8][8]);
    public:
        Bishop(Colour _pieceColour);
        ~Bishop();
};

class Queen: public Piece {
    private:
        bool isMoveValid(const char _sourceSquare[], const char _destinationSquare[], Piece* board[8][8]);
    public:
        Queen(Colour _pieceColour);
        ~Queen();
};

class Knight: public Piece {
    private:
        bool isMoveValid(const char _sourceSquare[], const char _destinationSquare[], Piece* board[8][8]);
    public:
        Knight(Colour _pieceColour);
        ~Knight();
};

class Pawn: public Piece {
    private:
        bool isMoveValid(const char _sourceSquare[], const char _destinationSquare[], Piece* board[8][8]);
    public:
        Pawn(Colour _pieceColour);
        ~Pawn();
        
};

#endif