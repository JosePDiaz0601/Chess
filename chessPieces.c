#include "chessPieces.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
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
int type; //paul made color to char type.

static int rangeOfMotion[64];

/*
HOW TO GET X AND Y VALUES FOR RANGE OF MOTION
	rangeOfMotion is 64 spaces wide
	if rangeOfMotion(42) == 1, to get the x and y do:
		int 42/8, which is the y (5)
		int 42%8, which is the x (2)
*/

int * getRangeOfMotion(enum PIECETYPE piece, char color, int x, int y, bool hasMoved)
{
    for(int x = 0; x <= 63; x++){
        rangeOfMotion[x] = 0;
		//printf("RANGE OF MOTION at %d = %d\n", x, rangeOfMotion[x]);
    }
	static int rangeOfMotion[64];
	printf("X is %d\nY is %d\n Piece is %d\n", x, y, piece);
    if ((piece == 1) && ('W' == color))
    {
        if (y < 7)
        {
            rangeOfMotion[x+(8*(y+1))] = 1;
            if (hasMoved == 0)
            {
                rangeOfMotion[x+(8*(y+2))] = 1;
            }
        }
        for (int test = 0; test <= 63; test++){
            //printf("RANGE OF MOTION at %d = %d\n", x, rangeOfMotion[test]);
        }
    }

	if (piece == 1 && 'B' == color){
		if (y >= 0){
			rangeOfMotion[x+(8*(y-1))] = 1;
			if (hasMoved != 1){
					rangeOfMotion[x+(8*(y-2))] = 1;
			}
		}
	} 

	if (piece == 2){	

		while (x+1 < 8 && y+1 < 8)
		{
			x++;
			y++;
			rangeOfMotion[x+(8*y)];
		}
		while (x-1 >= 0 && y+1 < 8)
		{
			x--;
			y++;
			rangeOfMotion[x+(8*y)];
		}
		while (x+1 < 8 && y-1 >= 0)
		{
			x++;
			y--;
			rangeOfMotion[x+(8*y)];
		}
		while (x-1 >= 0 && y-1 >= 0)
		{
			x--;
			y--;
			rangeOfMotion[x+(8*y)];
		}
	}

    if(piece == 3)
    {
        if((y+3) < 8)
        {
            if (x+1 < 8)
            {
                rangeOfMotion[(x+1)+(8*(y+3))] = 1;
            }
            if (x-1 >= 0)
            {
                rangeOfMotion[(x-1)+(8*(y+3))] = 1;
            }
        }
        if (y-3 >= 0) 
        {
            if (x+1 < 8)
            {
                rangeOfMotion[(x+1)+(8*(y-3))] = 1;
            }
            if (x-1 >= 0)
            {
                rangeOfMotion[(x-1)+(8*(y-3))] = 1;
            }
        }

        if (y+1 < 8 )
        {
            if (x+1 < 8)
            {
                rangeOfMotion[(x+3)+(8*(y+1))] = 1;
            }
            if (x-1 >= 0)
            {
                rangeOfMotion[(x-3)+(8*(y+1))] = 1;
            }
        }
        if (y-1 >= 0)
        {
            if (x+3 < 8)
            {
                rangeOfMotion[(x+3)+(8*(y-1))] = 1;
            }
            if (x-3 >= 0)
            {
                rangeOfMotion[(x-3)+(8*(y-1))] = 1;
            }
        }
        
    }

	if (piece == 4){
		while (x+1 < 8)
		{
			x++;
			rangeOfMotion[x+(8*y)];
		}
		while (x-1 >= 0)
		{
			x--;
			rangeOfMotion[x+(8*y)];
		}
		while (y+1 < 8)
		{
			y++;
			rangeOfMotion[x+(8*y)];
		}
		while (y-1 >= 0)
		{
			y--;
			rangeOfMotion[x+(8*y)];
		}
	}

/*		for (i = x+1, i <= 7, i++){
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
*/

	if (piece == 5){
		while (x+1 < 8 && y+1 < 8)
		{
			x++;
			y++;
			rangeOfMotion[x+(8*y)];
		}
		while (x-1 >= 0 && y+1 < 8)
		{
			x--;
			y++;
			rangeOfMotion[x+(8*y)];
		}
		while (x+1 < 8 && y-1 >= 0)
		{
			x++;
			y--;
			rangeOfMotion[x+(8*y)];
		}
		while (x-1 >= 0 && y-1 >= 0)
		{
			x--;
			y--;
			rangeOfMotion[x+(8*y)];
		}
		while (x+1 < 8)
		{
			x++;
			rangeOfMotion[x+(8*y)];
		}
		while (x-1 >= 0)
		{
			x--;
			rangeOfMotion[x+(8*y)];
		}
		while (y+1 < 8)
		{
			y++;
			rangeOfMotion[x+(8*y)];
		}
		while (y-1 >= 0)
		{
			y--;
			rangeOfMotion[x+(8*y)];
		}

	}
/*		for (int i = x+1; i <=7; i++){
			for (int j = y+1; j <= 7; j++){  
				rangeOfMotion[i+(8*j)] = 1;
			}
		}
		for (i = 0; i < x; i++){
			for (j = 0; j < y; j++){
				rangeOfMotion[i+(8*j)] = 1;
	 		}
		}
		for (i = x-1; i >= 0; i--){ 
			for (j = y+1; j <= 7; i++){
				rangeOfMotion[i+(8*j)] = 1;   
			}
		}
		for (i = 7; i > x; i--){
			for (j = 0; j < y; j++){
				rangeOfMotion[i+(8*j)] = 1; 
			}
		}
		for (i = x+1, i <= 7, i++){
			rangeOfMotion[i+(8*y)] = 1;
		}
		for (i = 0, i < x, i++){
			rangeOfMotion[i+(8*y)] = 1;
		}	 
		for (j = y+1, j <= 7, j++){
			rangeOfMotion[x+(8*j)] = 1;
		}
		for (j = 0, j < y, j++){
			rangeOfMotion[x+(8*j)] = 1;
		}

	*/

	if (piece == 6){
		if (y+1 < 8){
			rangeOfMotion[x+(8*(y+1))] = 1; 
		}
		if ((y-1 < 8) == (y-1 > 0)){
			rangeOfMotion[x+(8*(y-1))] = 1;
		}
		if (x+1 < 8){
			rangeOfMotion[x+1+(8*(y))] = 1;
		}
		if ((x-1 < 8) == (x-1 > 0)){
			rangeOfMotion[x-1+(8*(y))] = 1;
		}
		if ((x+1 < 8) == (x+1 > 0) == (y+1 < 0) == (y+1 < 8)){
			rangeOfMotion[x+1+(8*(y+1))] = 1;
		}
		if ((x-1 < 8) == (x-1 > 0) == (y+1 < 0) == (y+1 < 8)){ 
			rangeOfMotion[x-1+(8*(y+1))] = 1;
		}
		if ((x-1 < 8) == (x-1 > 0) == (y-1 > 0) == (y-1 < 8)){
			rangeOfMotion[x-1+(8*(y+1))] = 1;
		}
		if ((x+1 < 8) == (x+1 > 0) == (y-1 > 0) == (y-1 < 8)){
			rangeOfMotion[x+1+(8*(y-1))] = 1;
		}
	}


// we wouldn't need to make black pieces since we have strcmp for pawns, all the other pieces 
// should have the same code, either white or black
	//for(int testing = 0; testing < 64; testing++){
	//printf("%d %d %d %d %d %d %d %d \n%d %d %d %d %d %d %d %d \n%d %d %d %d %d %d %d %d \n%d %d %d %d %d %d %d %d \n%d %d %d %d %d %d %d %d \n%d %d %d %d %d %d %d %d \n%d %d %d %d %d %d %d %d \n%d %d %d %d %d %d %d %d \n", rangeOfMotion[testing]);}
	return rangeOfMotion;
}

int movePiece(int x1, int y1, int x2, int y2)
{
	struct PIECE empty = {7, 'W', 0};
	struct PIECE s = board[y1][x1]; 
	int *p;
	int check = 0;
	int selection = (x2 + (8*y2));
	//printf("s.type = %d\n", board[y1][x1].type);
	//printf("s.color = %c\n", board[y1][x1].color);
	//printf("x1 = %d\n", x1);
	//printf("y1 = %d\n", y1);
	p = getRangeOfMotion(s.type, s.color, x1, y1, s.hasMoved);
	printf("P = %d\n", *(p+(x2 + (8*y2))));
	if (*(p+(x2 + (8*y2))) == 1){
		board[y1][x1] = empty;
		board[y2][x2] = s;
		printf("P IS EQUAL TO 1\n");
	}else{
		check = 1;
	}
	return check;
}

/*WHEN CALLING rangeOfMotion do this format

int *p;

p = getRangeOfMotion(piece);


P WILL BE ARRAY rangeOfMotion;
*/
