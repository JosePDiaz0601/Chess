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
struct PIECE empty = {7, 'E', 0};
int valid = 0;
/*
HOW TO GET X AND Y VALUES FOR RANGE OF MOTION
	rangeOfMotion is 64 spaces wide
	if rangeOfMotion(42) == 1, to get the x and y do:
		int 42/8, which is the y (5)
		int 42%8, which is the x (2)
*/
char promotion;

int * getRangeOfMotion(enum PIECETYPE piece, char color, int x, int y, int x2Global, int y2Global, bool hasMoved)
{
	//int looper = 0;
    for(int x = 63; x >= 0; x--){
        rangeOfMotion[x] = 0;
		printf("%d", rangeOfMotion[x]);
		//if(looper = 8){
		//printf("\n");
		//looper = 0;
		//}
		//looper++;
    }
	for(int x = 0; x < 7; x++){
		for(int y = 0; y < 7; y++){
			if(board[0][y][x].type == 1 && board[0][y][x].hasMoved > 0){
				board[0][y][x].hasMoved = 1;
			}
		}
	}
	char pieceColor = board[0][y][x].color;
	printf("X is %d\nY is %d\nPiece is %d\n", x, y, piece);


    if ((piece == 1) && ('W' == color))
    {
        if (y < 7 && board[0][y+1][x].type == 7)
        {
            rangeOfMotion[x+(8*(y+1))] = 1;
            if (hasMoved == 0 && board[0][y+2][x].type == 7)
            {
                rangeOfMotion[x+(8*(y+2))] = 1;
				board[0][y1Global][x1Global].hasMoved = 2;
            }
        }
		if ((y < 7 && x-1 >= 0) && (board[0][y+1][x-1].color != pieceColor) && (board[0][y+1][x-1].color != 'E'))
		{
			rangeOfMotion[(x-1)+(8*(y+1))] = 1;
		}
		if ((y < 7 && x+1 < 7) && (board[0][y+1][x+1].color != pieceColor) && (board[0][y+1][x+1].color != 'E'))
		{
			rangeOfMotion[(x+1)+(8*(y+1))] = 1;
		}
    }

	if (piece == 1 && 'B' == color){
		if (y >= 0 && board[0][y-1][x].type == 7)
        {
            rangeOfMotion[x+(8*(y-1))] = 1;
            if (hasMoved == 0 && board[0][y-2][x].type == 7)
            {
                rangeOfMotion[x+(8*(y-2))] = 1;
            }
        }
		if ((y >= 0 && x-1 >= 0) && (board[0][y-1][x-1].color != pieceColor) && (board[0][y-1][x-1].color != 'E'))
		{
			rangeOfMotion[(x-1)+(8*(y-1))] = 1;
		}
		if ((y >= 0 && x+1 < 7) && (board[0][y-1][x+1].color != pieceColor) && (board[0][y-1][x+1].color != 'E'))
		{
			rangeOfMotion[(x+1)+(8*(y-1))] = 1;
		}
	} 

	if (piece == 3){	
		int tempx = x;
		int tempy = y;
		while (x+1 < 8 && y+1 < 8)
		{
			if (board[0][y+1][x+1].color == pieceColor){
				break;
			}else{
			x++;
			y++;
			rangeOfMotion[x+(8*y)] = 1;
			if (board[0][y][x].color != pieceColor && board[0][y][x].color != 'E'){
				break;
			}
			}
		}
		x = tempx;
		y = tempy;
		while (x-1 >= 0 && y+1 <8)
		{
			if (board[0][y+1][x-1].color == pieceColor){
				break;
			}else{
			x--;
			y++;
			rangeOfMotion[x+(8*y)] = 1;
			if (board[0][y][x].color != pieceColor && board[0][y][x].color != 'E'){
				break;
			}
			}
		}
		x = tempx;
		y = tempy;
		while (y-1 < 8 && x+1 < 8)
		{
			if (board[0][y-1][x+1].color == pieceColor){
				break;
			}else{
			y--;
			x++;
			rangeOfMotion[x+(8*y)] = 1;
			if (board[0][y][x].color != pieceColor && board[0][y][x].color != 'E'){
				break;
			}
			}
		}
		x = tempx;
		y = tempy;
		while (y-1 >= 0 && x-1 >= 0)
		{
			if (board[0][y-1][x-1].color == pieceColor){
				break;
			}else{
			y--;
			x--;
			rangeOfMotion[x+(8*y)] = 1;
			if (board[0][y][x].color != pieceColor && board[0][y][x].color != 'E'){
				break;
			}
			}
		}
	}
		/*int tempx = x;
		int tempy = y;
		while (tempx+1 < 8 && tempy+1 < 8)
		{
			tempx++;
			tempy++;
			rangeOfMotion[tempx+(8*tempy)] = 1;
		}
		tempx = x;
		tempy = y;
		while (tempx-1 >= 0 && tempy+1 < 8)
		{
			tempx--;

			tempy++;
			rangeOfMotion[tempx+(8*tempy)] = 1;
		}
		tempx = x;
		tempy = y;
		while (tempx+1 < 8 && tempy-1 >= 0)
		{
			tempx++;
			tempy--;
			rangeOfMotion[tempx+(8*tempy)] = 1;
		}
		tempx = x;
		tempy = y;
		while (tempx-1 >= 0 && tempy-1 >= 0)
		{
			tempx--;
			tempy--;
			rangeOfMotion[tempx+(8*tempy)] = 1;
		}*/
	

    if(piece == 2)
    {
        if((y+2) < 8)
        {
            if (x+1 < 8 && (board[0][y+2][x+1].color != pieceColor)){

                rangeOfMotion[(x+1)+(8*(y+2))] = 1;
            }
            if (x-1 >= 0 && (board[0][y+2][x-1].color != pieceColor))
            {
                rangeOfMotion[(x-1)+(8*(y+2))] = 1;
            }
        }
        if (y-2 >= 0) 
        {
            if (x+1 < 8 && (board[0][y-2][x+1].color != pieceColor))
            {
                rangeOfMotion[(x+1)+(8*(y-2))] = 1;
            }
            if (x-1 >= 0 && (board[0][y-2][x-1].color != pieceColor))
            {
                rangeOfMotion[(x-1)+(8*(y-2))] = 1;
            }
        }

        if (y+1 < 8 )
        {
            if (x+2 < 8 && (board[0][y+1][x+2].color != pieceColor)) 
            {
                rangeOfMotion[(x+2)+(8*(y+1))] = 1;
            }
            if (x-2 >= 0 && (board[0][y+1][x-2].color != pieceColor))
            {
                rangeOfMotion[(x-2)+(8*(y+1))] = 1;
            }
        }
        if (y-1 >= 0)
        {
            if (x+2 < 8 && (board[0][y-1][x+2].color != pieceColor))
            {
                rangeOfMotion[(x+2)+(8*(y-1))] = 1;
            }
            if (x-2 >= 0 && (board[0][y-1][x-2].color != pieceColor))
            {
                rangeOfMotion[(x-2)+(8*(y-1))] = 1;
            }
        }
        
    }

	if (piece == 4){
		int tempx = x;
		int tempy = y;
		while (x+1 < 8)
		{
			if (board[0][y][x+1].color == pieceColor){
				break;
			}else{
			x++;
			rangeOfMotion[x+(8*y)] = 1;
			if (board[0][y][x].color != pieceColor && board[0][y][x].color != 'E'){
				break;
			}
			}
		}
		x = tempx;
		y = tempy;
		while (x-1 >= 0)
		{
			if (board[0][y][x-1].color == pieceColor){
				break;
			}else{
			x--;
			rangeOfMotion[x+(8*y)] = 1;
			if (board[0][y][x].color != pieceColor && board[0][y][x].color != 'E'){
				break;
			}
			}
		}
		x = tempx;
		y = tempy;
		while (y+1 < 8)
		{
			if (board[0][y+1][x].color == pieceColor){
				break;
			}else{
			y++;
			rangeOfMotion[x+(8*y)] = 1;
			if (board[0][y][x].color != pieceColor && board[0][y][x].color != 'E'){
				break;
			}
			}
		}
		x = tempx;
		y = tempy;
		while (y-1 >= 0)
		{
			if (board[0][y-1][x].color == pieceColor){
				break;
			}else{
			y--;
			rangeOfMotion[x+(8*y)] = 1;
			if (board[0][y][x].color != pieceColor && board[0][y][x].color != 'E'){
				break;
			}
			}
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
		int tempx = x;
		int tempy = y;
		while (x+1 < 8)
		{
			if (board[0][y][x+1].color == pieceColor){
				break;
			}else{
			x++;
			rangeOfMotion[x+(8*y)] = 1;
			if (board[0][y][x].color != pieceColor && board[0][y][x].color != 'E'){
				break;
			}
			}
		}
		x = tempx;
		y = tempy;
		while (x-1 >= 0)
		{
			if (board[0][y][x-1].color == pieceColor){
				break;
			}else{
			x--;
			rangeOfMotion[x+(8*y)] = 1;
			if (board[0][y][x].color != pieceColor && board[0][y][x].color != 'E'){
				break;
			}
			}
		}
		x = tempx;
		y = tempy;
		while (y+1 < 8)
		{
			if (board[0][y+1][x].color == pieceColor){
				break;
			}else{
			y++;
			rangeOfMotion[x+(8*y)] = 1;
			if (board[0][y][x].color != pieceColor && board[0][y][x].color != 'E'){
				break;
			}
			}
		}
		x = tempx;
		y = tempy;
		while (y-1 >= 0)
		{
			if (board[0][y-1][x].color == pieceColor){
				break;
			}else{
			y--;
			rangeOfMotion[x+(8*y)] = 1;
			if (board[0][y][x].color != pieceColor && board[0][y][x].color != 'E'){
				break;
			}
			}
		}
		x = tempx;
		y = tempy;
		while (x+1 < 8 && y+1 < 8)
		{
			if (board[0][y+1][x+1].color == pieceColor){
				break;
			}else{
			x++;
			y++;
			rangeOfMotion[x+(8*y)] = 1;
			if (board[0][y][x].color != pieceColor && board[0][y][x].color != 'E'){
				break;
			}
			}
		}
		x = tempx;
		y = tempy;
		while (x-1 >= 0 && y+1 <8)
		{
			if (board[0][y+1][x-1].color == pieceColor){
				break;
			}else{
			x--;
			y++;
			rangeOfMotion[x+(8*y)] = 1;
			if (board[0][y][x].color != pieceColor && board[0][y][x].color != 'E'){
				break;
			}
			}
		}
		x = tempx;
		y = tempy;
		while (y-1 < 8 && x+1 < 8)
		{
			if (board[0][y-1][x+1].color == pieceColor){
				break;
			}else{
			y--;
			x++;
			rangeOfMotion[x+(8*y)] = 1;
			if (board[0][y][x].color != pieceColor && board[0][y][x].color != 'E'){
				break;
			}
			}
		}
		x = tempx;
		y = tempy;
		while (y-1 >= 0 && x-1 >= 0)
		{
			if (board[0][y-1][x-1].color == pieceColor){
				break;
			}else{
			y--;
			x--;
			rangeOfMotion[x+(8*y)] = 1;
			if (board[0][y][x].color != pieceColor && board[0][y][x].color != 'E'){
				break;
			}
			}
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
		if ((y+1 < 8 ) && (board[0][y+1][x].color != pieceColor)){
			rangeOfMotion[x+(8*(y+1))] = 1; 
		}
		if ((y-1 >= 0) && (board[0][y-1][x].color != pieceColor)){
			rangeOfMotion[x+(8*(y-1))] = 1;
		}
		if ((x+1 < 8) && (board[0][y][x+1].color != pieceColor)){
			rangeOfMotion[x+1+(8*(y))] = 1;
		}
		if ((x-1 >= 0) && (board[0][y][x-1].color != pieceColor)){
			rangeOfMotion[x-1+(8*(y))] = 1;
		}
		if ((x+1 < 8) && (y+1 < 8) && (board[0][y+1][x+1].color != pieceColor) ){
			rangeOfMotion[x+1+(8*(y+1))] = 1;
		}
		if ((y+1 < 8) && (x-1 >= 0)  && (board[0][y+1][x-1].color != pieceColor) ){ 
			rangeOfMotion[x-1+(8*(y+1))] = 1;
		}
		if ((y-1 >= 0) && (x-1 >= 0) && (board[0][y-1][x-1].color != pieceColor)){
			rangeOfMotion[x-1+(8*(y-1))] = 1;
		}
		if ((y-1 >= 0) && (x+1 < 8) && (board[0][y-1][x+1].color != pieceColor) ){
			rangeOfMotion[x+1+(8*(y-1))] = 1;
		}
	}

	int checkLoop = 56;
	for(int testing = 0; testing <= 7; testing++){
		printf("%d %d %d %d %d %d %d %d \n", rangeOfMotion[checkLoop], rangeOfMotion[checkLoop+1], rangeOfMotion[checkLoop+2], rangeOfMotion[checkLoop+3], rangeOfMotion[checkLoop+4], rangeOfMotion[checkLoop+5], rangeOfMotion[checkLoop+6], rangeOfMotion[checkLoop+7]);
		checkLoop -= 8;
	}
	return rangeOfMotion; //this line returns an error when compiling try this website https://stackoverflow.com/questions/23593597/returning-an-integer-array-pointer-in-c
}

int check(char king, int boardNumber){
	int x = 999;
	int y = 999;
	for (int loop1 = 0; loop1 < 8; loop1++){
		for(int loop2 = 0; loop2 < 8; loop2++){
			if (board[boardNumber][loop2][loop1].type == 6 && board[boardNumber][loop2][loop1].color == king){
				int x = loop1;
				int y = loop2;
			}
		}
	}
	
	if(x == 999 && y == 999)
	{
		printf("ERROR %c KING COULD NOT BE FOUND", king);
		return 5;
	}

	//QUEEN CHECK
	int tempx = x;
	int tempy = y;
	char pieceColor = board[boardNumber][y][x].color;
	int isInCheck = 0;
	while (x+1 < 8)
	{
		if (board[boardNumber][y][x+1].color == pieceColor){
			break;
		}else{
		x++;
		
		if (board[boardNumber][y][x].color != pieceColor && board[boardNumber][y][x].color != 'E'){
			int isInCheck = 1;
			break;
		}
		}
	}
	x = tempx;
	y = tempy;
	while (x-1 >= 0)
	{
		if (board[boardNumber][y][x-1].color == pieceColor){
			break;
		}else{
		x--;
		
		if (board[boardNumber][y][x].color != pieceColor && board[boardNumber][y][x].color != 'E'){
			int isInCheck = 1;
			break;
		}
		}
	}
	x = tempx;
	y = tempy;
	while (y+1 < 8)
	{
		if (board[boardNumber][y+1][x].color == pieceColor){
			break;
		}else{
		y++;
		
		if (board[boardNumber][y][x].color != pieceColor && board[boardNumber][y][x].color != 'E'){
			int isInCheck = 1;
			break;
		}
		}
	}
	x = tempx;
	y = tempy;
	while (y-1 >= 0)
	{
		if (board[boardNumber][y-1][x].color == pieceColor){
			break;
		}else{
		y--;
		
		if (board[boardNumber][y][x].color != pieceColor && board[boardNumber][y][x].color != 'E'){
			int isInCheck = 1;
			break;
		}
		}
	}
	x = tempx;
	y = tempy;
	while (x+1 < 8 && y+1 < 8)
	{
		if (board[boardNumber][y+1][x+1].color == pieceColor){
			break;
		}else{
		x++;
		y++;
		
		if (board[boardNumber][y][x].color != pieceColor && board[boardNumber][y][x].color != 'E'){
			int isInCheck = 1;
			break;
		}
		}
	}
	x = tempx;
	y = tempy;
	while (x-1 >= 0 && y+1 <8)
	{
		if (board[boardNumber][y+1][x-1].color == pieceColor){
			break;
		}else{
		x--;
		y++;
		
		if (board[boardNumber][y][x].color != pieceColor && board[boardNumber][y][x].color != 'E'){
			int isInCheck = 1;
			break;
		}
		}
	}
	x = tempx;
	y = tempy;
	while (y-1 < 8 && x+1 < 8)
	{
		if (board[boardNumber][y-1][x+1].color == pieceColor){
			break;
		}else{
		y--;
		x++;
		
		if (board[boardNumber][y][x].color != pieceColor && board[boardNumber][y][x].color != 'E'){
			int isInCheck = 1;
			break;
		}
		}
	}
	x = tempx;
	y = tempy;
	while (y-1 >= 0 && x-1 >= 0)
	{
		if (board[boardNumber][y-1][x-1].color == pieceColor){
			break;
		}else{
		y--;
		x--;
		
		if (board[boardNumber][y][x].color != pieceColor && board[boardNumber][y][x].color != 'E'){
			int isInCheck = 1;
			break;
			}
		}
	}

	x = tempx;
	y = tempy;

	//KNIGHT CHECK
	if((y+2) < 8)
    {
		if (x+1 < 8 && (board[boardNumber][y+2][x+1].color != pieceColor ) && (board[boardNumber][y+2][x+1].color != 'E'))
		{
			int isInCheck = 1;
		}
		if (x-1 >= 0 && (board[boardNumber][y+2][x-1].color != pieceColor) && (board[boardNumber][y+2][x-1].color != 'E'))
		{
			int isInCheck = 1;
		}
	}
	if (y-2 >= 0) 
	{
		if (x+1 < 8 && (board[boardNumber][y-2][x+1].color != pieceColor)&&(board[boardNumber][y-2][x+1].color != 'E'))
		{
			int isInCheck = 1;
		}
		if (x-1 >= 0 && (board[boardNumber][y-2][x-1].color != pieceColor) && (board[boardNumber][y-2][x-1].color != 'E'))
		{
			int isInCheck = 1;
		}
	}

	if (y+1 < 8 )
	{
		if (x+2 < 8 && (board[boardNumber][y+1][x+2].color != pieceColor) && (board[boardNumber][y+1][x+2].color != 'E')) 
		{
			int isInCheck = 1;
		}
		if (x-2 >= 0 && (board[boardNumber][y+1][x-2].color != pieceColor) && (board[boardNumber][y+1][x-2].color != 'E'))
		{
			int isInCheck = 1;
		}
	}
	if (y-1 >= 0)
	{
		if (x+2 < 8 && (board[boardNumber][y-1][x+2].color != pieceColor) && (board[boardNumber][y-1][x+2].color != 'E'))
		{
			int isInCheck = 1;
		}
		if (x-2 >= 0 && (board[boardNumber][y-1][x-2].color != pieceColor) && (board[boardNumber][y-1][x-2].color != 'E'))
		{
			int isInCheck = 1;
		}
	}
	return isInCheck;
}

void makeMove(int x1Global, int y1Global, int x2Global, int y2Global, char playercolor){
	valid = 0;
	if (playercolor == 0){
		playercolor = 'w';
	}
	if (playercolor == 1){
		playercolor = 'b';
	}
	struct PIECE s1 = board[0][y1Global][x1Global]; 
	struct PIECE s2 = board[0][y2Global][x2Global];
	int *p;
	int isInCheck = 0;
	p = getRangeOfMotion(s1.type, s1.color, x1Global, y1Global, x2Global, y2Global, s1.hasMoved);
	printf("P = %d\n", *(p+(x2Global + (8*y2Global))));
	if (*(p+(x2Global + (8*y2Global))) == 1 /*&& board[0][y1Global][x1Global].color == playercolor*/){
		do
		{
		board[0][y1Global][x1Global] = empty;
		board[0][y2Global][x2Global] = s1;
		board[0][y2Global][x2Global].hasMoved = 1;

			//isInCheck = check(playercolor, 0);
			if(isInCheck == 1){
				board[0][y1Global][x1Global] = s1;
				board[0][y2Global][x2Global] = s2;
				board[0][y1Global][x1Global].hasMoved = 0;
				printf("INVALID MOVE: CURRENTLY IN CHECK");
			}
		} while (isInCheck == 1);
	}else{
		valid = 1;
	}
	return;
}


int movePiece(int x1Local, int y1Local, int x2Local, int y2Local, int playercolor)
{
	x1Global = (int)(x1Local);
	x2Global = (int)(x2Local);
	y1Global = (int)(y1Local);
	y2Global = (int)(y2Local);
 /**
	int selection = 0;
  selection = (x2Global + (8*y2Global));*/ //these are currently not being used, when they are used --> uncomment
	//printf("s.type = %d\n", board[y1Global][x1Global].type);
	//printf("s.color = %c\n", board[y1Global][x1Global].color);
	//printf("x1Global = %d\n", x1Global);
	//printf("y1Global = %d\n", y1Global);
	struct PIECE s = board[0][y1Global][x1Global]; 
	if (playercolor == 0){
		playercolor == 'w';
	}
	if (playercolor == 1){
		playercolor == 'b';
	}
	//en passant
	if (s.type == 1 && y1Global == 4){
	if (board[0][y1Global][x1Global-1].type == 1 && board[0][y1Global][x1Global-1].hasMoved == 2 && x1Global-1 == x2Global) {
		board[0][y1Global+1][x1Global-1] = s;
		board[0][y1Global][x1Global] =   empty;
		board[0][y1Global][x1Global-1] = empty;
				}
	if (board[0][y1Global][x1Global+1].type == 1 && board[0][y1Global][x1Global+1].hasMoved == 2 && x1Global+1 == x2Global) {
		board[0][y1Global+1][x1Global+1] = s;
		board[0][y1Global][x1Global] =   empty;
		board[0][y1Global][x1Global+1] = empty;}
	}
	//Promotion
		if ((board[0][y1Global][x1Global].type == 1) && (board[0][y1Global][x1Global].color == 'W') && ((y1Global == 6) && (y2Global == 7))){
		board[0][y1Global][x1Global] = empty;
		printf("Promotion! White, please enter: Q for queen, N for Knight, B for Bishop, R for Rook\n");
		scanf(" %c", &promotion);
		printf("Promotion is %c\n", promotion);
	
		if (promotion == 'Q'){
			printf("Promoted to Queen");
			board[0][y2Global][x2Global].type = 5;
			board[0][y2Global][x2Global].color = 'W';
			board[0][y2Global][x2Global].hasMoved = 1; 
		}
		if (promotion == 'N'){
			board[0][y2Global][x2Global].type = 2;
			board[0][y2Global][x2Global].color = 'W';
			board[0][y2Global][x2Global].hasMoved = 1; 
		}
		if (promotion == 'B'){
			board[0][y2Global][x2Global].type = 3;
			board[0][y2Global][x2Global].color = 'W';
			board[0][y2Global][x2Global].hasMoved = 1; 
		}
		if (promotion == 'R'){
			board[0][y2Global][x2Global].type = 4;
			board[0][y2Global][x2Global].color = 'W';
			board[0][y2Global][x2Global].hasMoved = 1; 
		}
		return valid;
	}

	if ((board[0][y1Global][x1Global].type == 1) && (board[0][y1Global][x1Global].color == 'B') && ((y2Global == 0) && (y1Global==1))){
		board[0][y1Global][x1Global] = empty;
		printf("Promotion! Black, please enter: Q for queen, N for Knight, B for Bishop, R for Rook\n");
		scanf(" %c", &promotion);
		printf("%c", promotion);
		if (promotion == 'Q'){
			board[0][y2Global][x2Global].type = 5;
			board[0][y2Global][x2Global].color = 'B';
			board[0][y2Global][x2Global].hasMoved = 1; 
		}
		if (promotion == 'N'){
			board[0][y2Global][x2Global].type = 2;
			board[0][y2Global][x2Global].color = 'B';
			board[0][y2Global][x2Global].hasMoved = 1; 
		}
		if (promotion == 'B'){
			board[0][y2Global][x2Global].type = 3;
			board[0][y2Global][x2Global].color = 'B';
			board[0][y2Global][x2Global].hasMoved = 1; 
		}
		if (promotion == 'R'){
			board[0][y2Global][x2Global].type = 4;
			board[0][y2Global][x2Global].color = 'B';
			board[0][y2Global][x2Global].hasMoved = 1; 
		}
	return valid;
	}
	//castling
	if(x1Global == 4 && y1Global == 0 && x2Global == 7 && y2Global == 0 && board[0][y1Global][x1Global].color == playercolor && board[0][y2Global][x2Global].color == playercolor){
		if(board[0][y1Global][x1Global].hasMoved == 0 && board[0][y2Global][x2Global].hasMoved == 0){
			if(board[0][y1Global][x1Global+1].type == 7 && board[0][y1Global][x1Global+2].type == 7){
				
				struct PIECE k = board[0][y1Global][x1Global];
				struct PIECE r = board[0][y2Global][x2Global];
				board[0][0][6] = k;
				board[0][0][5] = r;
				board[0][0][4] = empty;
				board[0][0][7] = empty;
				
				return valid;
			}else{
				makeMove(x1Global, y1Global, x2Global, y2Global, playercolor);
			}
		}else{
			makeMove(x1Global, y1Global, x2Global, y2Global, playercolor);
		}
	}else if(x1Global == 4 && y1Global == 7 && x2Global == 7 && y2Global == 7 && board[0][y1Global][x1Global].color == playercolor && board[0][y2Global][x2Global].color == playercolor){
		if(board[0][y1Global][x1Global].hasMoved == 0 && board[0][y2Global][x2Global].hasMoved == 0){
			if(board[0][y1Global][x1Global+1].type == 7 && board[0][y1Global][x1Global+2].type == 7){
				
				struct PIECE k = board[0][y1Global][x1Global];
				struct PIECE r = board[0][y2Global][x2Global];
				board[0][7][6] = k;
				board[0][7][5] = r;
				board[0][7][4] = empty;
				board[0][7][7] = empty;
				
				return valid;
			}else{
				makeMove(x1Global, y1Global, x2Global, y2Global, playercolor);
			}
		}else{
			makeMove(x1Global, y1Global, x2Global, y2Global, playercolor);
		}
		}else if(x1Global == 4 && y1Global == 7 && x2Global == 0 && y2Global == 7 && board[0][y1Global][x1Global].color == playercolor && board[0][y2Global][x2Global].color == playercolor){
		if(board[0][y1Global][x1Global].hasMoved == 0 && board[0][y2Global][x2Global].hasMoved == 0){
			if(board[0][y1Global][x1Global-1].type == 7 && board[0][y1Global][x1Global-2].type == 7 && board[0][y1Global][x1Global-3].type == 7){
				
				struct PIECE k = board[0][y1Global][x1Global];
				struct PIECE r = board[0][y2Global][x2Global];
				board[0][7][2] = k;
				board[0][7][3] = r;
				board[0][7][4] = empty;
				board[0][7][0] = empty;
				
				return valid;
			}else{
				makeMove(x1Global, y1Global, x2Global, y2Global, playercolor);
			}
		}else{
			makeMove(x1Global, y1Global, x2Global, y2Global, playercolor);
		}
		}else if(x1Global == 4 && y1Global == 0 && x2Global == 0 && y2Global == 0 && board[0][y1Global][x1Global].color == playercolor && board[0][y2Global][x2Global].color == playercolor){
		if(board[0][y1Global][x1Global].hasMoved == 0 && board[0][y2Global][x2Global].hasMoved == 0){
			if(board[0][y1Global][x1Global-1].type == 7 && board[0][y1Global][x1Global-2].type == 7 && board[0][y1Global][x1Global-3].type == 7){
				
				struct PIECE k = board[0][y1Global][x1Global];
				struct PIECE r = board[0][y2Global][x2Global];
				board[0][0][2] = k;
				board[0][0][3] = r;
				board[0][0][4] = empty;
				board[0][0][0] = empty;
				
				return valid;
			}else{
				makeMove(x1Global, y1Global, x2Global, y2Global, playercolor);
			}
		}else{
			makeMove(x1Global, y1Global, x2Global, y2Global, playercolor);
		}
	}else{
		makeMove(x1Global, y1Global, x2Global, y2Global, playercolor);
	}
		//printf("P IS EQUAL TO 1\n");
	return valid;
}

/*WHEN CALLING rangeOfMotion do this format

int *p;

p = getRangeOfMotion(piece);


P WILL BE ARRAY rangeOfMotion;
*/
