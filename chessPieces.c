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
int type, x, y, color; //paul made color to char type.
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

	if (piece == 2){	
		for (i = x+1; i <=7; i++){
			for (j = y+1; j <= 7; j++){  
				rangeOfMotion[i][j] = 1;
			}
		}
		for (i = 0; i < x; i++){
			for (j = 0; j < y; j++){
				rangeOfMotion[i][j] = 1;
	 		}
		}
		for (i = x-1; i >= 0; i--){ 
			for (j = y+1; j <= 7; i++){
				rangeOfMotion[i][j] = 1;   
			}
		}
		for (i = 7; i > x; i--){
			for (j = 0; j < y; j++){
				rangeOfMotion[i][j] = 1; 
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

	if (piece == 5){
		for (i = x+1; i <=7; i++){
			for (j = y+1; j <= 7; j++){  
				rangeOfMotion[i][j] = 1;
			}
		}
		for (i = 0; i < x; i++){
			for (j = 0; j < y; j++){
				rangeOfMotion[i][j] = 1;
	 		}
		}
		for (i = x-1; i >= 0; i--){ 
			for (j = y+1; j <= 7; i++){
				rangeOfMotion[i][j] = 1;   
			}
		}
		for (i = 7; i > x; i--){
			for (j = 0; j < y; j++){
				rangeOfMotion[i][j] = 1; 
			}
		}
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

	if (pieces == 6){
		if (y+1 < 8){
			rangeOfMotion[x][y+1] = 1; 
		}
		if ((y-1 < 8) == (y-1 > 0)){
			rangeOfMotion[x][y-1] = 1;
		}
		if (x+1 < 8){
			rangeOfMotion[x+1][y] = 1;
		}
		if ((x-1 < 8) == (x-1 > 0)){
			rangeOfMotion[x-1][y] = 1;
		}
		if ((x+1 < 8) == (x+1 > 0) == (y+1 < 0) == (y+1 < 8)){
			rangeOfMotion[x+1][y+1] = 1;
		}
		if ((x-1 < 8) == (x-1 > 0) == (y+1 < 0) == (y+1 < 8)){ 
			rangeOfMotion[x-1][y+1] = 1;
		}
		if ((x-1 < 8) == (x-1 > 0) == (y-1))
			 
