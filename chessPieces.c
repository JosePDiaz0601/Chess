#include "chessPieces.h"
#include <stdlib.h>

/*  1 - pawn 
    2 - bishop
    3 - knight
    4 - rook
    5 - queen
    6 - king */
int type, x, y, color;
bool hasMoved;
int rangeOfMotion[][];

void getRangeOfMotion(void){
    if piece == 3{
        rangeOfMotion[][]
    }

	if (piece == 4){
		for (i = x+1, i <= 7, i++){
			rangeOfMotion[i][y] = 1;
		}
		for (i = 0, i < x, i++){
			rangeOfMotion[i][y] = 1;
		}	 
		for (j = y+1, j <= 7, j++){
			rangeOfMotion[x][j] = 1;
		}
		for (j = 0, j < y, j++){
			rangeOfMotion[x][j] = 1;
		}
	}




