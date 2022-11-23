#include <iostream>
using namespace std;

#include "ChessBoard.h"
#include "piece.h"

ChessBoard::ChessBoard(): nextPlayer(white){

        chessPieces[0][0] = new King(white);
        chessPieces[1][0] = new King(black);
        chessPieces[0][1] = new Rook(white);
        chessPieces[1][1] = new Rook(black);
        chessPieces[0][2] = new Bishop(white);
        chessPieces[1][2] = new Bishop(black);
        chessPieces[0][3] = new Queen(white);
        chessPieces[1][3] = new Queen(black);
        chessPieces[0][4] = new Knight(white);
        chessPieces[1][4] = new Knight(black);
        chessPieces[0][5] = new Pawn(white);
        chessPieces[1][5] = new Pawn(black);

    resetBoard();
}
void ChessBoard::resetBoard(){
    
    // reset next player to white
    nextPlayer =white;

    clearBoard();

    for (int column=0; column<8; column++){
        board[1][column] = chessPieces[0][5]; // white pawn
        board[6][column] = chessPieces[1][5]; // black pawn
    }  

    board[0][0] = board[0][7] = chessPieces[0][1]; // white rook
    board[0][1] = board[0][6] = chessPieces[0][4]; // white knight
    board[0][2] = board[0][5] = chessPieces[0][2]; // white bishop
    board[0][3] = chessPieces[0][3]; // white queen
    board[0][4] = chessPieces[0][0]; // white king

    board[7][0] = board[7][7] = chessPieces[1][1]; // black rook
    board[7][1] = board[7][6] = chessPieces[1][4]; // black knight
    board[7][2] = board[7][5] = chessPieces[1][2]; // black bishop
    board[7][3] = chessPieces[1][3]; // black queen
    board[7][4] = chessPieces[1][0]; // black king

      
    cout<<"A new chess game is started!"<<endl;

}

void ChessBoard::clearBoard(){
    for (int row =0; row<8; row++){
        for (int column=0; column<8; column++){
            board[row][column]=NULL;
        }
    }
}
bool ChessBoard::inputsValid(const char _sourceSquare[], const char _destinationSquare[]){
    // check that the source square and destination square are not the same
    if(_sourceSquare == _destinationSquare)
        return false;
    
    // return true if the rank for both the source and destination lies between '1' and '8'
    // and the file for both lies between 'A' and 'H'
    return(_sourceSquare[0]>='A' && _sourceSquare[0]<='H' && _sourceSquare[1]>='1' && _sourceSquare[1]<='8'
    && _destinationSquare[0]>='A' && _destinationSquare[0]<='H' && _destinationSquare[1]>='1' && _destinationSquare[1]<='8');

}

bool ChessBoard::sourceNotEmpty(const char _sourceSquare[]){
    // convert positions to integer indeces
    int fileSource= _sourceSquare[0]-'A';
    int rankSource = _sourceSquare[1]-'1';

    if(board[rankSource][fileSource]==NULL){
        cout<< "There is no piece at position "<< _sourceSquare <<"!"<< endl;
        return false;
    }
    return true;
}

bool ChessBoard::correctPlayer(const char _sourceSquare[]){
    // convert positions to integer indeces
    int fileSource= _sourceSquare[0]-'A';
    int rankSource = _sourceSquare[1]-'1';

    if(board[rankSource][fileSource]->get_colour()==nextPlayer){
        return true;
    }

    cout<<"It is not ";
    board[rankSource][fileSource]->printColour();
    cout<<"'s turn to move!"<<endl;
    
    return false;
}

bool ChessBoard::submitMove(const char source_square[], const char destination_square[]){
    // convert positions to integer indeces
    int fileSource= source_square[0]-'A';
    int fileDestination = destination_square[0]-'A';
    int rankSource = source_square[1]-'1';
    int rankDestination = destination_square[1]-'1';

    if((inputsValid(source_square, destination_square))&& 
        (sourceNotEmpty(source_square))&&
        (correctPlayer(source_square)) && 
        (board[rankSource][fileSource]->canMove(source_square, destination_square, board))
        ){
            // move the piece to the destination square and remove it from source square
            board[rankDestination][fileDestination]=board[rankSource][fileSource];
            cout<<"Assigned piece to new position"<<endl;
            board[rankSource][fileSource]=NULL;

            // change player
            changePlayer();

            return true;
        }
        
    
    return false;
}

void ChessBoard::changePlayer(){
    switch(nextPlayer){
        case white: nextPlayer = black; break;
        case black: nextPlayer = white; break;
        default: nextPlayer = white; break;
    }
    return;
}

void ChessBoard::getElement(const char _square[2]){
    int x = _square[1] - '1';
    int y = _square[0] - 'A';
    board[x][y]->printType();
}
ChessBoard::~ChessBoard(){
    for(int row=0; row<2; row++){
        for(int column=0;column<6; column++){
            delete chessPieces[row][column];
            chessPieces[row][column]=NULL;
        }
    }
}