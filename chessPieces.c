#include "chessPieces.h"
#include <stdlib.h>
#include <stdbool.h>

/*  1 - wpawn 
    2 - wbishop
    3 - wknight
    4 - wrook
    5 - wqueen
    6 - wking 
    7 - bpawn
    8 - bbishop
    9 - bknight
    10- brook
    11- bqueen
    12- bking*/
int type, x, y, color;
bool hasMoved;
int rangeOfMotion[][];

void getRangeOfMotion(void)
{
    if piece == 1
    {
        if y < 7
        {
            rangeOfMotion[x][y+1] = 1;
            if hasMoved != 1
            {
                rangeOfMotion[x][y+2] = 1;
            }
        }
    }
    
    if piece == 3
    {
        if y+3 < 8 
        {
            if x+1 < 8
            {
                rangeOfMotion[x+1][y+3] = 1;
            }
            if x-1 >= 0
            {
                rangeOfMotion[x-1][y+3] = 1;
            }
        }
        if y-3 >= 0
        {
            if x+1 < 8
            {
                rangeOfMotion[x+1][y-3] = 1;
            }
            if x-1 >= 0
            {
                rangeOfMotion[x-1][y-3] = 1;
            }
        }

        if y+1 < 8 
        {
            if x+1 < 8
            {
                rangeOfMotion[x+3][y+1] = 1;
            }
            if x-1 >= 0
            {
                rangeOfMotion[x-3][y+1] = 1;
            }
        }
        if y-1 >= 0
        {
            if x+3 < 8
            {
                rangeOfMotion[x+3][y-1] = 1;
            }
            if x-3 >= 0
            {
                rangeOfMotion[x-3][y-1] = 1;
            }
        }
        
    }
}