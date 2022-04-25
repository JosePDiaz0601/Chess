#ifndef PIECESHEADER
#define PIECESHEADER

#include <stdbool.h>
#include "chess.h"

char positionValues[8][8][3];

void newBoard();
int x1Global, y1Global, x2Global, y2Global;
int checkMate = 0;

int movePiece(int x1, int y1, int x2, int y2, int playercolor);
//int * getRangeOfMotion(enum PIECETYPE piece, char color, int x, int y, bool hasMoved);

enum color
{
    black = 0,
    white = 1
};

enum PIECETYPE
{
    pawn = 1,
    knight = 2,
    bishop = 3,
    rook = 4,
    queen = 5,
    king = 6,
    eempty = 7
};
	int whiteIsInCheck = 0;
	int blackIsInCheck = 0;


struct PIECE
{
    enum PIECETYPE type;
    char color;
    bool hasMoved;
};

struct PIECE board[500][8][8];
//struct PIECE *empty = {7, 'W', 0};
int * getRangeOfMotion(int x, int y);
#endif

/*
PIECE A5;
{
    type 1
    rank 0
    file 4
    color 1
    hasMoved 1
}
int selection == rank + (8*file);
if(rangeOfMotion(selection) == 1){
    A6.Type = A5.type;
    A6.Color = A5.Color;
    A5.type = NULL;
    A5.Color = NULL;

}
*/
