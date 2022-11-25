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

bool ChessBoard::inCheck(Piece* king_ptr){
    cout<<"Checking if " << king_ptr->pieceColour<<" in check"<<endl;
    // chessPieces[0][0]; // white king
    // chessPieces[1][0]; // black king
    
    char kingPosition[3];
    // find position of the king
    for(int row=0; row<8; row++){
        for (int column=0; column<8; column++){
            if(board[row][column] == king_ptr){
                kingPosition[0]= column + 'A';
                kingPosition[1] = row + '1';
                kingPosition[2] ='\0';
            }
        }
    }

    cout<<"Found "<<king_ptr->pieceColour<<" king's position at:"<<kingPosition<<endl;
    
    // king in check if its position is a valid move for any of the opposite Player's pieces
    for (int row=0; row<8; row++){
        for(int column=0; column<8; column++){
            char sourceSquare[3]={column + 'A', row + '1', '\0'};
            if(board[row][column]!=NULL){
                if((board[row][column]->get_colour()!=king_ptr->get_colour())
                && (board[row][column]->canMove(sourceSquare, kingPosition, board))){
                cout<< king_ptr->pieceColour<<" is in check"<<endl;
                cout<< "by row: "<< row <<" and column:"<<column<<endl;
                cout<<" position: "<<sourceSquare<<endl;
                cout<<" with "<<board[row][column]->pieceColour<<" "<<board[row][column]->name<<endl;
                return true;
                }
            }
        }
    }
    cout<<"King is not in check"<<endl;
    return false;
}

bool ChessBoard::submitMove(const char source_square[], const char destination_square[]){
    cout<<" TRYING to make a move from "<< source_square <<" to "<<destination_square<<endl;
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
        
    if(board[rankSource][fileSource]->canMove(source_square, destination_square, board)){
            // keep track of the destination piece that might be eaten
            Piece* destination_piece = board[rankDestination][fileDestination];
            
            // move the piece to the destination square and remove it from source square
            board[rankDestination][fileDestination]=board[rankSource][fileSource];
            //cout<<"Assigned piece to new position"<<endl;
            board[rankSource][fileSource]=NULL;

            // is own king in check, if yes, reset the pointers to original squares
            if (((Player == white) && (inCheck(chessPieces[0][0]))) || 
                ((Player==black) && (inCheck(chessPieces[1][0])))){
                board[rankSource][fileSource]=board[rankDestination][fileDestination];
                board[rankDestination][fileDestination]=destination_piece;
                
                return false;
            }
            
            
        cout<< Player <<"'s "<< board[rankDestination][fileDestination]->name << " moves from "<<source_square<<" to "<< destination_square;
        if(destination_piece!=NULL){
            cout<<" taking "<< destination_piece->pieceColour <<"' "
                << destination_piece->name;
        }
        cout<<endl;

        // check if the move put other Player's king in check
            if (((Player == white) && (inCheck(chessPieces[1][0]))) ||
                ((Player == black) && (inCheck(chessPieces[0][0])))){
                cout<< Player<< " is in check";
            }

            // change player
            changePlayer();

            return true;
        }

    cout<< Player <<"'s "<< board[rankSource][fileSource]->name << " cannot move to "<< destination_square <<"!"<<endl;
    return false;
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