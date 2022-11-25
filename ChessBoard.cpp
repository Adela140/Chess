#include <iostream>
using namespace std;

#include "ChessBoard.h"
#include "piece.h"

ChessBoard::ChessBoard(): Player(white){

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

Piece* ChessBoard::get_white_king() const{
    return chessPieces[0][0];
}

Piece* ChessBoard::get_black_king() const{
    return chessPieces[1][0];
}

void ChessBoard::resetBoard(){
    
    // reset next player to white
    Player =white;

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

    //strcpy(whiteKingsPosition, "E1");
    //strcpy(blackKingsPosition, "E8");
      
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

    if(board[rankSource][fileSource]->get_colour()==Player){
        return true;
    }

    cout<<"It is not "<<board[rankSource][fileSource]->get_colour()<<"'s turn to move!"<<endl;
    
    return false;
}

bool ChessBoard::submitMove(const char source_square[], const char destination_square[]){
    //cout<<" TRYING to make a move from "<< source_square <<" to "<<destination_square<<endl;
    // convert positions to integer indeces
    int fileSource= source_square[0]-'A';
    int fileDestination = destination_square[0]-'A';
    int rankSource = source_square[1]-'1';
    int rankDestination = destination_square[1]-'1';

    if(!((inputsValid(source_square, destination_square))&& (sourceNotEmpty(source_square))&&
        (correctPlayer(source_square)))){
            //cout<<"Not valid"<<endl;
            return false;
        }
    
    Piece* destination_piece = board[rankDestination][fileDestination];
    Piece* source_piece = board[rankSource][fileSource];


    if(board[rankSource][fileSource]->canMove(source_square, destination_square, board, chessPieces)){
            
        cout<< Player <<"'s "<< board[rankSource][fileSource]->name << " moves from "<<source_square<<" to "<< destination_square;
        if(destination_piece!=NULL){
            cout<<" taking "<< destination_piece->pieceColour <<"' "
                << destination_piece->name;
        }
        cout<<endl;

        // move the piece to the destination square and remove it from source square
        board[rankDestination][fileDestination]=source_piece;
        //cout<<"Assigned piece to new position"<<endl;
        board[rankSource][fileSource]=NULL;

        // check for checkmate of other player 
        if((Player == white)&&(checkMate(black))){
                cout<<"Black is in checkmate"<<endl;
                return true;}
        else if((Player == black)&&(checkMate(white))){
                cout<<"White is in checkmate"<<endl;
                return true;}

        // check if the move put other Player's king in check
        if((Player == white)&&(chessPieces[1][0]->inCheck(board, chessPieces))){
            cout<< chessPieces[1][0]->pieceColour<<" is in check"<<endl;}
        else if((Player == black)&&(chessPieces[0][0]->inCheck(board, chessPieces))){
            cout<< chessPieces[0][0]->pieceColour<<" is in check"<<endl;
        }

        // change player
        changePlayer();

        return true;
        }

    cout<< Player <<"'s "<< board[rankSource][fileSource]->name << " cannot move to "<< destination_square <<"!"<<endl;
    return false;
}


bool ChessBoard::checkMate(Colour _player){
    // checkmate happens when any of the pieces can legally move to any destination square
    // which includes not putting your own king in check

    for(int rank=0; rank<8; rank++){
        for(int file=0; file<8; file++){
            for(int row=0; row<8; row++){
                for(int column=0; column<8; column++){
                    char sourceSquare[3]={file + 'A', rank + '1', '\0'};
                    char destinationSquare[3]={column + 'A', row + '1', '\0'};
                    if((board[rank][file]!=NULL)
                        && (board[rank][file]->pieceColour==_player)
                        && (board[rank][file]->canMove(sourceSquare, destinationSquare, 
                            board, chessPieces))){
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

void ChessBoard::changePlayer(){
    switch(Player){
        case white: Player = black; break;
        case black: Player = white; break;
        default: Player = white; break;
    }
    return;
}

void ChessBoard::getElement(const char _square[2]){
    int x = _square[1] - '1';
    int y = _square[0] - 'A';
    cout<<board[x][y]->printType();
}
ChessBoard::~ChessBoard(){
    for(int row=0; row<2; row++){
        for(int column=0;column<6; column++){
            delete chessPieces[row][column];
            chessPieces[row][column]=NULL;
        }
    }
}

void ChessBoard::printBoard(Piece* board[8][8]){
    for(int row=7; row>=0; row--){
        cout<<endl;
        cout<<"------------------------------------------------------------------------------------"<<endl;
        for(int column=0; column<8; column++){
            if(board[row][column]==NULL){
                cout<< "     .     ";
            }
            else{ 
            cout<<board[row][column]->pieceColour <<" "<<board[row][column]->name;
            }
            cout<<"|";
        }
    }
    cout<<endl;
}