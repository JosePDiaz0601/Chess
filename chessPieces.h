#ifndef PIECESHEADER
#define PIECESHEADER

enum color{
black = 0;
white = 1;}

enum PIECETYPE{
pawn   = 0;
knight = 1;
bishop = 2;
rook   = 3;
queen  = 4;
king   = 5; }

struct PIECE{
int PIECETYPE,rank,file,color;
bool hasMoved;
}


#endif
