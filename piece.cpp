#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

#include "piece.h"

/************************ Definitions for Colour type ************************/

/* Prints out the colour to either White or Black */
std::ostream& operator <<(std::ostream& out, Colour _pieceColour){
    switch (_pieceColour) {
    case white:
        out << "White"; break;
    case black:
        out << "Black"; break;
    default:
        out << "invalid colour"; break;
    }
    return out;
}

/* Changes colour to the opposite colour */
Colour operator!(Colour _colour){
    _colour = static_cast<Colour>((static_cast<int>(_colour) + 1) % 2);
    return _colour;
}

/************************ Definitions for Piece class ************************/

/* Constructs Piece object */
Piece::Piece(string _name, Colour _pieceColour): name(_name), pieceColour(_pieceColour){}

/* Destructs the Piece object */
Piece::~Piece(){}


