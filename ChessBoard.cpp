#include <iostream>
using namespace std;

#include "ChessBoard.h"
#include "piece.h"
#include "king.h"
#include "queen.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "pawn.h"

ChessBoard::ChessBoard(): player(white), gameOver(false){

    // create new pointers to all the board pieces and store them in chessPieces matrix
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

    // reset the board to original piece arrangement
    resetBoard();
}

void ChessBoard::resetBoard(){
    
    // reset next player to white
    player =white;

    // initially set all the squares to NULL
    clearBoard();

    // set up the pawns for both players
    for (int column=0; column<8; column++){
        board[1][column] = chessPieces[0][5]; // white pawn
        board[6][column] = chessPieces[1][5]; // black pawn
    }  

    // set up white pieces in first rank
    board[0][0] = board[0][7] = chessPieces[0][1]; // white rook
    board[0][1] = board[0][6] = chessPieces[0][4]; // white knight
    board[0][2] = board[0][5] = chessPieces[0][2]; // white bishop
    board[0][3] = chessPieces[0][3]; // white queen
    board[0][4] = chessPieces[0][0]; // white king

    // set up black pieces in last rank
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
    
    // check that inputs are only two characters
    if((strlen(_sourceSquare)!=2) || (strlen(_destinationSquare)!=2)){
            return false;
    }

    // check that the source square and destination square are not the same
    if(!(strcmp(_sourceSquare, _destinationSquare))){
        return false;
    }
        
    // return true if the rank for both the source and destination lies between '1' and '8'
    // and the file for both lies between 'A' and 'H'
    return(_sourceSquare[0]>='A' && _sourceSquare[0]<='H' && _sourceSquare[1]>='1' && _sourceSquare[1]<='8'
    && _destinationSquare[0]>='A' && _destinationSquare[0]<='H' && _destinationSquare[1]>='1' && _destinationSquare[1]<='8');

}

bool ChessBoard::sourceNotEmpty(int start_row, int start_column){

    return(!(board[start_row][start_column]==NULL));
}

bool ChessBoard::correctPlayer(int start_row, int start_column){

    return(board[start_row][start_column]->pieceColour==player);
}

bool ChessBoard::submitMove(const char source_square[], const char destination_square[]){
    //cout<<" TRYING to make a move from "<< source_square <<" to "<<destination_square<<endl;
    // convert positions to integer indeces
    int fileSource= source_square[0]-'A';
    int fileDestination = destination_square[0]-'A';
    int rankSource = source_square[1]-'1';
    int rankDestination = destination_square[1]-'1';

    if(gameOver){
        return false;
    }
    if(!(inputsValid(source_square, destination_square))){
        return false;
    }
    if(!(sourceNotEmpty(rankSource, fileSource))){
        cout<< "There is no piece at position "<< source_square <<"!"<< endl;
        return false;
    }
    if(!(correctPlayer(rankSource, fileSource))){
        cout<<"It is not "<<board[rankSource][fileSource]->pieceColour<<"'s turn to move!"<<endl;
        return false;
    }
    
    Piece* destination_piece = board[rankDestination][fileDestination];
    Piece* source_piece = board[rankSource][fileSource];


    if(board[rankSource][fileSource]->canMove(rankSource, fileSource, rankDestination, fileDestination, board, chessPieces)){
        
        // move the piece to the destination square and remove it from source square
        board[rankDestination][fileDestination]=source_piece;
        //cout<<"Assigned piece to new position"<<endl;
        board[rankSource][fileSource]=NULL;

        cout<< player <<"'s "<< board[rankDestination][fileDestination]->name << " moves from "<<source_square<<" to "<< destination_square;
        if(destination_piece!=NULL){
            cout<<" taking "<< destination_piece->pieceColour <<"' "
                << destination_piece->name;
        }
        cout<<endl;

        // check for end of game 
        if(endOfGame(player)){
            gameOver=true;
            return true;
        }

        // if not end of game, check if the move put other Player's king in check
        if((player == white)&&(chessPieces[1][0]->inCheck(board, chessPieces))){
            cout<< chessPieces[1][0]->pieceColour<<" is in check"<<endl;}
        else if((player == black)&&(chessPieces[0][0]->inCheck(board, chessPieces))){
            cout<< chessPieces[0][0]->pieceColour<<" is in check"<<endl;
        }

        // change player
        changePlayer();

        return true;
        }

    cout<< player <<"'s "<< board[rankSource][fileSource]->name << " cannot move to "<< destination_square <<"!"<<endl;
    return false;
}

bool ChessBoard::endOfGame(Colour _player){
    // end of game if other player cannot move without putting king in check
    Colour otherPlayer = ++_player;
    if(!(canMove(otherPlayer))){
        // if cannot legally move and is in check, player is in checkmate
        if(checkmate(otherPlayer)){
            cout<< otherPlayer<< " is in checkmate"<<endl;
            return true;
        }
        // otherwise player is in stalemate
        cout<< otherPlayer<<" is in stalemate"<<endl;
        return true;
    }      
    return false;
}
bool ChessBoard::checkmate(Colour _player){
    // checkmate happens when none of the pieces can legally move to any destination square
    // which includes not putting your own king in check

    for(int rank=0; rank<8; rank++){
        for(int file=0; file<8; file++){
            for(int row=0; row<8; row++){
                for(int column=0; column<8; column++){
                    if((board[rank][file]!=NULL)
                        && (board[rank][file]->pieceColour==_player)
                        && (board[rank][file]->canMove(rank, file, row, column, 
                            board, chessPieces))){
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

bool ChessBoard::canMove(Colour _player){

    // stalemate occurs when the player cannot legally play any moves
    for(int rank=0; rank<8; rank++){
        for(int file=0; file<8; file++){
            for(int row=0; row<8; row++){
                for(int column=0; column<8; column++){
                    if((board[rank][file]!=NULL)
                        && (board[rank][file]->pieceColour==_player)
                        && (board[rank][file]->canMove(rank, file, row, column, 
                            board, chessPieces))){
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

void ChessBoard::changePlayer(){
    switch(player){
        case white: player = black; break;
        case black: player = white; break;
        default: player = white; break;
    }
    return;
}

void ChessBoard::getElement(const char _square[2]){
    int x = _square[1] - '1';
    int y = _square[0] - 'A';
    cout<<board[x][y]->name;
}
ChessBoard::~ChessBoard(){
    for(int row=0; row<2; row++){
        for(int column=0;column<6; column++){
            delete chessPieces[row][column];
            chessPieces[row][column]=NULL;
        }
    }
}

void ChessBoard::printBoard(){
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