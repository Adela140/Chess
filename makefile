chess: ChessTest.o ChessBoard.o piece.o bishop.o king.o knight.o pawn.o queen.o rook.o
	g++ -g ChessTest.o ChessBoard.o piece.o bishop.o king.o knight.o pawn.o queen.o rook.o -o chess

ChessTest.o: ChessTest.cpp ChessBoard.h piece.h bishop.h king.h knight.h pawn.h queen.h rook.h
	g++ -Wall -g -c ChessTest.cpp

ChessBoard.o: ChessBoard.cpp ChessBoard.h piece.h bishop.h king.h knight.h pawn.h queen.h rook.h
	g++ -Wall -g -c ChessBoard.cpp

piece.o: piece.cpp piece.h ChessBoard.h
	g++ -Wall -g -c piece.cpp

bishop.o: bishop.cpp bishop.h piece.h ChessBoard.h
	g++ -Wall -g -c bishop.cpp

king.o: king.cpp king.h piece.h ChessBoard.h
	g++ -Wall -g -c king.cpp

knight.o: knight.cpp knight.h piece.h ChessBoard.h
	g++ -Wall -g -c knight.cpp

pawn.o:pawn.cpp pawn.h piece.h ChessBoard.h
	g++ -Wall -g -c pawn.cpp

queen.o: queen.cpp queen.h piece.h ChessBoard.h
	g++ -Wall -g -c queen.cpp

rook.o: rook.cpp rook.h piece.h ChessBoard.h
	g++ -Wall -g -c rook.cpp

clean: 
	rm -f *.o chess
