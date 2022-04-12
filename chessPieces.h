#ifndef PIECESHEADER
#define PIECESHEADER

enum color{
black = 0,
white = 1};

enum PIECETYPE{
pawn   = 1,
knight = 2,
bishop = 3,
rook   = 4,
queen  = 5,
king   = 6 };

struct PIECE{
int PIECETYPE,rank,file,color;
bool hasMoved;
}


#endif
