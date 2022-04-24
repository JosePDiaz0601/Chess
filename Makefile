CC = gcc
DEBUG = -g -DDEBUG
CFLAGS = -Wall -ansi -std=c99 $(DEBUG)
ALL = chess

test:
	cd src && make chess
	
chess: Chess.o ChessPieces.o ChessAI.o LogFile.o
	$(CC) $(CFLAGS) ./bin/Chess.o ./bin/ChessPieces.o ./bin/ChessAI.o ./bin/LogFile.o -o ./bin/chess
	
Chess.o: ./src/chess.c ./src/chessPieces.h ./src/chessAI.h ./src/LogFile.h ./src/chess.h
	$(CC) $(CFLAGS) -c ./src/chess.c -o ./bin/Chess.o
	
ChessPieces.o: ./src/chessPieces.c ./src/chessPieces.h ./src/chessAI.h ./src/chessAI.c
	$(CC) $(CFLAGS) -c ./src/chessPieces.c -o ./bin/ChessPieces.o
	
ChessAI.o: ./src/chessAI.c ./src/chessAI.h ./src/chessPieces.h ./src/LogFile.h
	$(CC) $(CFLAGS) -c ./src/chessAI.c -o ./bin/ChessAI.o

LogFile.o: ./src/LogFile.c ./src/LogFile.h
	$(CC) $(CFLAGS) -c ./src/LogFile.c -o ./bin/LogFile.o ./bin/LogFile.log
#might have to delete ./bin.LogFile.log

clean:
	rm ./bin/chess
	rm ./bin/*.o

#tar:
#	tar -zcvf Chess_V1.0.tar.gz ./README ./COPYRIGHT ./INSTALL ./bin/chess ./doc
#	tar -zcvf Chess_V1.0_src.tar.gz ./doc ./bin ./src ./Makefile ./README ./COPYRIGHT ./INSTALL
