chess: main.o piece.o ChessBoard.o
	g++ -g main.o piece.o ChessBoard.o -o chess

main.o: main.cpp piece.h ChessBoard.h
	g++ -Wall -g -c main.cpp

piece.o: piece.cpp piece.h
	g++ -Wall -g -c piece.cpp

ChessBoard.o: ChessBoard.cpp ChessBoard.h piece.h
	g++ -Wall -g -c ChessBoard.cpp

clean: 
	rm -f *.o chess
