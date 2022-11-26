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

/************************** Definitions for ChessBoard class ****************************/

/* Constructs a ChessBoard with chess pieces set up on 8x8 board*/
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

/* Resets the 8x8 board in ChessBoard to contain original set up */ 
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

/* Sets all the squares in the 8x8 board to null */
void ChessBoard::clearBoard(){
    for (int row =0; row<8; row++){
        for (int column=0; column<8; column++){
            board[row][column]=NULL;
        }
    }
}

/* Changes the pieces if the submitted move is valid*/
bool ChessBoard::submitMove(const char source_square[], const char destination_square[]){
    
    // convert source_square and destination_square to integer indeces for rank and file
    int fileSource= source_square[0]-'A';
    int fileDestination = destination_square[0]-'A';
    int rankSource = source_square[1]-'1';
    int rankDestination = destination_square[1]-'1';

    // do not attempt the move if the game is already over, the inputs are invalid, 
    // the source is not empty or if the incorrect player is making the move:
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
    
    // keep track of the contents of the source and destination squares
    Piece* destination_piece = board[rankDestination][fileDestination];
    Piece* source_piece = board[rankSource][fileSource];

    // check if the piece in source square can make the move legally
    if(board[rankSource][fileSource]->isMoveValid(rankSource, fileSource, rankDestination,
                                                 fileDestination, board, chessPieces)){
        // if the move is valid, move the piece to the destination square 
        // and remove it from source square
        board[rankDestination][fileDestination]=source_piece;
        board[rankSource][fileSource]=NULL;

        cout<< player <<"'s "<< board[rankDestination][fileDestination]->name 
            << " moves from "<<source_square<<" to "<< destination_square;
        if(destination_piece!=NULL){
            cout<<" taking "<< destination_piece->pieceColour <<"' "
                << destination_piece->name;
        }
        cout<<endl;

        // check if the move ended the game (the other player is in checkmate or stalemate)
        if(endOfGame()){
            gameOver=true;
            return true;
        }

        // if not the end of game, check if the move put other Player's king in check
        // note: white king = chessPieces[0][0] and black king = chessPieces[1][0]
        // and white=0 and black=1
        Colour otherPlayer =  static_cast<Colour>(!player);
        if((chessPieces[otherPlayer][0]->inCheck(board, chessPieces))){
            cout<< chessPieces[otherPlayer][0]->pieceColour<<" is in check"<<endl;
        }

        // change player
        changePlayer();

        return true;
    }

    cout<< player <<"'s "<< board[rankSource][fileSource]->name 
        << " cannot move to "<< destination_square <<"!"<<endl;

    return false;
}

/* Checks if coordinates of inputs are valid */
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
    return(_sourceSquare[0]>='A' && _sourceSquare[0]<='H' && _sourceSquare[1]>='1' 
        && _sourceSquare[1]<='8'&& _destinationSquare[0]>='A' && _destinationSquare[0]<='H' 
        && _destinationSquare[1]>='1' && _destinationSquare[1]<='8');

}

/* Returns true if the source is not empty */
bool ChessBoard::sourceNotEmpty(int start_row, int start_column){

    return(!(board[start_row][start_column]==NULL));
}

/* Returns true if the correct player is making the move */
bool ChessBoard::correctPlayer(int start_row, int start_column){

    return(board[start_row][start_column]->pieceColour==player);
}

/* Returns true if the current player made the other player be in checkmate or stalemate */
bool ChessBoard::endOfGame(){
    
    Colour otherPlayer =  static_cast<Colour>(!player); // this would be the future player
    // end of game if other player cannot move without putting king in check:
    // note: white king = chessPieces[0][0] and black king = chessPieces[1][0]
    // and white=0 and black=1
    if(!(canMove(otherPlayer))){
        // if the player cannot legally move AND is in check, player is in checkmate
        if((chessPieces[otherPlayer][0]->inCheck(board, chessPieces))){
            cout<< chessPieces[otherPlayer][0]->pieceColour<<" is in checkmate"<<endl;
            return true;
        }
        // otherwise player is in stalemate
        cout<< otherPlayer<<" is in stalemate"<<endl;
        return true;
    }      
    return false;
}

/* Returns true if the '_player' can make any valid move */
bool ChessBoard::canMove(Colour _player){

    // for each remaining piece of the same colour as _player
    // try moving it to any other square:

    // iterate through the board to get a source square
    for(int rank=0; rank<8; rank++){
        for(int file=0; file<8; file++){
            // iterate through the board to find destination square
            for(int row=0; row<8; row++){
                for(int column=0; column<8; column++){
                    // _player can move if any piece finds a valid move
                    if((board[rank][file]!=NULL)
                        && (board[rank][file]->pieceColour==_player)
                        && (board[rank][file]->isMoveValid(rank, file, row, column, 
                            board, chessPieces))){
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

/* Changes 'player' attribute from white to black and from black to white */
void ChessBoard::changePlayer(){
    switch(player){
        case white: player = black; break;
        case black: player = white; break;
        default: player = white; break;
    }
    return;
}

/* Destructs the ChessBoard object*/
ChessBoard::~ChessBoard(){
    // deleting all the chess pieces from chessPieces matrix that were created on the heap
    for(int row=0; row<2; row++){
        for(int column=0;column<6; column++){
            delete chessPieces[row][column];
            chessPieces[row][column]=NULL;
        }
    }
}

/* Prints current status of the 8x8 board */
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