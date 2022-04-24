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
int enpassant = 0;

/*
HOW TO GET X AND Y VALUES FOR RANGE OF MOTION
	rangeOfMotion is 64 spaces wide
	if rangeOfMotion(42) == 1, to get the x and y do:
		int 42/8, which is the y (5)
		int 42%8, which is the x (2)
*/
int promotion;

int * getRangeOfMotion(int x, int y)
{
	//int looper = 0;
    for(int x = 63; x >= 0; x--){
        rangeOfMotion[x] = 0;
		//printf("%d", rangeOfMotion[x]);
		//if(looper = 8){
		//printf("\n");
		//looper = 0;
		//}
		//looper++;
    }
	
	enum PIECETYPE piece = board[0][y][x].type;

	char pieceColor = board[0][y][x].color;
	printf("\nX is %d\nY is %d\nPiece is %d\n\n", x, y, piece);


    if ((piece == 1) && ('W' == pieceColor))
    {
        if (y < 7 && board[0][y+1][x].type == 7)
        {
            rangeOfMotion[x+(8*(y+1))] = 1;
            if (board[0][y][x].hasMoved == 0 && board[0][y+2][x].type == 7)
            {
                rangeOfMotion[x+(8*(y+2))] = 1;
				
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

	if (piece == 1 && 'B' == pieceColor){
		if (y >= 0 && board[0][y-1][x].type == 7)
        {
            rangeOfMotion[x+(8*(y-1))] = 1;
            if (board[0][y][x].hasMoved == 0 && board[0][y-2][x].type == 7)
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
		while (y-1 >= 0 && x+1 < 8)
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
		while (y-1 >= 0 && x+1 < 8)
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
	printf("\nCOLOR IS : %c\n", king);
	int x = 999;
	int y = 999;
	for (int loop1 = 0; loop1 < 8; loop1++){
		for(int loop2 = 0; loop2 < 8; loop2++){
			if (board[boardNumber][loop2][loop1].type == 6 && board[boardNumber][loop2][loop1].color == king){
				x = loop1;
				y = loop2;
				
			}
		}
	}
	printf("\nKING (X,Y) IS  : (%d,%d)\n", x,y);
	
	if(x == 999 && y == 999)
	{
		printf("ERROR %c KING COULD NOT BE FOUND", king);
		return 5;
	}

	//QUEEN CHECK
	int tempx = x;
	int tempy = y;
	char pieceColor = board[boardNumber][y][x].color;
	//printf("pieceColor = %c\n", pieceColor);
	int isInCheck = 0;
	while (x+1 < 8)
	{
		x++;
		if (board[boardNumber][y][x].color != pieceColor && board[boardNumber][y][x].color != 'E'){
		if ((board[boardNumber][y][x].type == 4  || board[boardNumber][y][x].type == 5)){
			isInCheck = 24;
		}
			break;
		}
	}
	x = tempx;
	y = tempy;
	while (x-1 >= 0)
	{
		x--;
		if (board[boardNumber][y][x].color != pieceColor && board[boardNumber][y][x].color != 'E'){
		if ((board[boardNumber][y][x].type == 4  || board[boardNumber][y][x].type == 5)){
			isInCheck = 23;
		}
			break;
		}
		
	}
	x = tempx;
	y = tempy;
	while (y+1 < 8)
	{
		y++;
		if (board[boardNumber][y][x].color != pieceColor && board[boardNumber][y][x].color != 'E'){
		if ((board[boardNumber][y][x].type == 4  || board[boardNumber][y][x].type == 5)){
			isInCheck = 22;
		}
		break;
		}
		
	}
	x = tempx;
	y = tempy;
	while (y-1 >= 0)
	{

		y--;
		
		if (board[boardNumber][y][x].color != pieceColor && board[boardNumber][y][x].color != 'E'){
		if ((board[boardNumber][y][x].type == 4  || board[boardNumber][y][x].type == 5)){
			isInCheck = 21;
		}
			break;
		}
		
	}
	x = tempx;
	y = tempy;
	while (x+1 < 8 && y+1 < 8)
	{

		x++;
		y++;
		
		if (board[boardNumber][y][x].color != pieceColor && board[boardNumber][y][x].color != 'E'){
		if ((board[boardNumber][y][x].type == 3  || board[boardNumber][y][x].type == 5)){
			isInCheck = 20;
		}
			break;
		}
		
	}
	x = tempx;
	y = tempy;
	while (x-1 >= 0 && y+1 <8)
	{

		x--;
		y++;
		
		if (board[boardNumber][y][x].color != pieceColor && board[boardNumber][y][x].color != 'E'){
		if ((board[boardNumber][y][x].type == 3  || board[boardNumber][y][x].type == 5)){
			isInCheck = 19;
		}
			break;
		}
		
	}
	x = tempx;
	y = tempy;
	while (y-1 >= 0 && x+1 < 8)
	{

		y--;
		x++;
		
		if (board[boardNumber][y][x].color != pieceColor && board[boardNumber][y][x].color != 'E'){
		if ((board[boardNumber][y][x].type == 3  || board[boardNumber][y][x].type == 5)){
			//printf("%d %d %c %d", x, y, board[boardNumber][y][x].color, board[boardNumber][y][x].type);
			isInCheck = 18;
		}
			break;
		}
		
	}
	x = tempx;
	y = tempy;
	while (y-1 >= 0 && x-1 >= 0)
	{

		y--;
		x--;
		
		if (board[boardNumber][y][x].color != pieceColor && board[boardNumber][y][x].color != 'E'){
		if ((board[boardNumber][y][x].type == 3  || board[boardNumber][y][x].type == 5)){
			isInCheck = 17;
		}
			//printf("EXAMINE queen CHECK");
			break;
		}
		
	}

	x = tempx;
	y = tempy;

	//KNIGHT CHECK
	//printf("\npieceColor = %c\n", pieceColor);
	if((y+2) < 8)
    {
		if (x+1 < 8 && (board[boardNumber][y+2][x+1].color != pieceColor ) && (board[boardNumber][y+2][x+1].color != 'E') && (board[boardNumber][y+2][x+1].type == 2))
		{
			isInCheck = 1;
		}
		if (x-1 >= 0 && (board[boardNumber][y+2][x-1].color != pieceColor) && (board[boardNumber][y+2][x-1].color != 'E') && (board[boardNumber][y+2][x-1].type == 2))
		{
			//printf("EXAMINE KNIGHT CHECK");
			isInCheck = 2;
		}
	}
	if (y-2 >= 0) 
	{
		if (x+1 < 8 && (board[boardNumber][y-2][x+1].color != pieceColor)&&(board[boardNumber][y-2][x+1].color != 'E') && (board[boardNumber][y-2][x+1].type == 2))
		{
			isInCheck = 3;
		}
		if (x-1 >= 0 && (board[boardNumber][y-2][x-1].color != pieceColor) && (board[boardNumber][y-2][x-1].color != 'E') && (board[boardNumber][y-2][x-1].type == 2))
		{
			isInCheck = 4;
		}
	}

	if (y+1 < 8 )
	{
		if (x+2 < 8 && (board[boardNumber][y+1][x+2].color != pieceColor) && (board[boardNumber][y+1][x+2].color != 'E') && (board[boardNumber][y+1][x+2].type == 2)) 
		{
			isInCheck = 5;
		}
		if (x-2 >= 0 && (board[boardNumber][y+1][x-2].color != pieceColor) && (board[boardNumber][y+1][x-2].color != 'E') && (board[boardNumber][y+1][x-2].type == 2))
		{
			isInCheck = 6;
		}
	}
	if (y-1 >= 0)
	{
		if (x+2 < 8 && (board[boardNumber][y-1][x+2].color != pieceColor) && (board[boardNumber][y-1][x+2].color != 'E') && (board[boardNumber][y-1][x+2].type == 2))
		{
			isInCheck = 7;
		}
		if (x-2 >= 0 && (board[boardNumber][y-1][x-2].color != pieceColor) && (board[boardNumber][y-1][x-2].color != 'E') && (board[boardNumber][y-1][x-2].type == 2))
		{
			isInCheck = 8;
		}
	}
	//printf("\npieceColor = %c\n", pieceColor);
	//KING CHECK
	if ((y+1 < 8 ) && (board[0][y+1][x].color != pieceColor)  && (board[0][y+1][x].type == 6)){
			isInCheck = 9;
		}
		if ((y-1 >= 0) && (board[0][y-1][x].color != pieceColor) && (board[0][y-1][x].type == 6)){
			isInCheck = 10;
		}
		if ((x+1 < 8) && (board[0][y][x+1].color != pieceColor) && (board[0][y][x+1].type == 6)){
			isInCheck = 11;
		}
		if ((x-1 >= 0) && (board[0][y][x-1].color != pieceColor) && (board[0][y][x-1].type == 6)){
			isInCheck = 12;
		}
		if ((x+1 < 8) && (y+1 < 8) && (board[0][y+1][x+1].color != pieceColor) && (board[0][y+1][x+1].type == 6)){
			isInCheck = 13;
		}
		if ((y+1 < 8) && (x-1 >= 0)  && (board[0][y+1][x-1].color != pieceColor) && (board[0][y+1][x-1].type == 6)){ 
			isInCheck = 14;
		}
		if ((y-1 >= 0) && (x-1 >= 0) && (board[0][y-1][x-1].color != pieceColor) && (board[0][y-1][x-1].type == 6)){
			//printf("EXAMINE KING CHECK");
			isInCheck = 15;
		}
		if ((y-1 >= 0) && (x+1 < 8) && (board[0][y-1][x+1].color != pieceColor)  && (board[0][y-1][x+1].type == 6)){
			isInCheck = 16;
		}
	printf("\nisInCheck : %d\n=====================================\n", isInCheck);
	//printf("\nAI LOCATION X1 : %d\nAI LOCATION Y1 : %d\nAI LOCATION X2 : %d\nAI LOCATION Y2 : %d\n", x1Global, x2Global, y1Global, y2Global);
	return isInCheck;
}
int checkForCheckMate(char playercolor, int boardnumber)
{
	int xtemp, ytemp, ROMtemp;
	int *pROM;
	struct PIECE piece, s1, s2;
	int x2Global = x2Global;
	int y2Global = y2Global;
	for(xtemp = 0; xtemp < 8; xtemp++){
			for(ytemp = 0; ytemp < 8; ytemp++){
				board[0][ytemp][xtemp] = piece;
				pROM = getRangeOfMotion(xtemp, ytemp);
				int isInCheck = check(playercolor, boardnumber);
				if(isInCheck == 0){
					return 0;
				}
				if(isInCheck == 1){
				for(ROMtemp = 0; ROMtemp < 64; ROMtemp++){
					if (pROM[ROMtemp] == 0){
						continue;
					}	
					if (pROM[ROMtemp] == 1){
							int yROM = ROMtemp/8;
							int xROM = ROMtemp%8;
							s1 = board[0][ytemp][xtemp];
							s2 = board[0][yROM][xROM];

							board[0][yROM][xROM] = s1;
							board[0][ytemp][xtemp] = empty;

							int isInCheck = check(playercolor, boardnumber);
							
							if(isInCheck = 0){
								break;
							}
							
							if(isInCheck = 1){
								pROM[ROMtemp] = 0;
								board[0][ytemp][xtemp] = s1;
								board[0][yROM][xROM] = s2;
							}	
						}	
					for (ROMtemp = 0; ROMtemp < 64; ROMtemp++){
						if (pROM[ROMtemp] == 1){
							return 1;
						}
					}
				}
			}
	return 0;
		}
	}
}

void makeMove(int x1Global, int y1Global, int x2Global, int y2Global, char playercolor){
	valid = 0;
	if (playercolor == 0){
		playercolor = 'W';
	}
	if (playercolor == 1){
		playercolor = 'B';
	}
	struct PIECE s1 = board[0][y1Global][x1Global]; 
	struct PIECE s2 = board[0][y2Global][x2Global];
	int *p;
	int isInCheck = 0;
	int isInCheckMate = 0;
	p = getRangeOfMotion(x1Global, y1Global);
	//printf("P = %d\n", *(p+(x2Global + (8*y2Global))));
	if (*(p+(x2Global + (8*y2Global))) == 1 /*&& board[0][y1Global][x1Global].color == playercolor*/){
		
		if(board[0][y1Global][x1Global].type == 1 && board[0][y1Global][x1Global].color == 'W' && y2Global - 2 == y1Global){
			enpassant = 1;
			//printf("\nHAS MOVES EQUALS 2, %d\n", enpassant);
		}else if(board[0][y1Global][x1Global].type == 1 && board[0][y1Global][x1Global].color == 'B' && y2Global + 2 == y1Global){
			enpassant = 1;
			//printf("\nHAS MOVES EQUALS 2, %d\n", enpassant);
		}else{
			enpassant = 0;
		}

		board[0][y1Global][x1Global] = empty;
		board[0][y2Global][x2Global] = s1;
		board[0][y2Global][x2Global].hasMoved = 1;
		
		
		

			isInCheck = check(playercolor, 0);
			if(isInCheck != 0){
				board[0][y1Global][x1Global] = s1;
				board[0][y2Global][x2Global] = s2;
				board[0][y1Global][x1Global].hasMoved = 0;
				printf("INVALID MOVE: CHECK");
				valid = 1;
			}
			isInCheckMate = checkForCheckMate('W', 0);
			if(isInCheckMate != 0){
				printf("CheckMate! Black Wins!");
				checkMate = 1;
			}
			isInCheckMate = checkForCheckMate('B', 0);
			if(isInCheckMate != 0){
				printf("CheckMate! White Wins!");
				checkMate = 2;
			}
		
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
		playercolor = 'W';
	}
	if (playercolor == 1){
		playercolor = 'B';
	}
	//en passant
		if (s.type == 1 && y1Global == 4 && s.color == 'W'){
		//printf("%d %d %d %d %d %d\n", board[0][y1Global][x1Global+1].type, board[0][y1Global][x1Global+1].hasMoved, x1Global+1, x2Global, y1Global, y2Global);
		if (board[0][y1Global][x1Global-1].type == 1 && enpassant == 1 && x1Global-1 == x2Global && (y1Global == y2Global-1)) {
		board[0][y1Global+1][x1Global-1] = s;
		board[0][y1Global][x1Global] =   empty;
		board[0][y1Global][x1Global-1] = empty;
		positionValues[y1Global][x1Global-1][0] = ' '; 
		positionValues[y1Global][x1Global-1][1] = ' '; 
		return valid;
				}
	if (board[0][y1Global][x1Global+1].type == 1 && enpassant == 1 && x1Global+1 == x2Global && (y1Global == y2Global-1)) {
		board[0][y1Global+1][x1Global+1] = s;
		board[0][y1Global][x1Global] =   empty;
		board[0][y1Global][x1Global+1] = empty;
		positionValues[y1Global][x1Global+1][0] = ' '; 
		positionValues[y1Global][x1Global+1][1] = ' '; 
		return valid;
		}
	}
	if (s.type == 1 && y1Global == 3 && s.color == 'B'){
		//printf("white");
		if (board[0][y1Global][x1Global-1].type == 1 && enpassant == 1 && x1Global-1 == x2Global && (y1Global == y2Global+1)) {
			board[0][y1Global-1][x1Global-1] = s;
			board[0][y1Global][x1Global] =   empty;
			board[0][y1Global][x1Global-1] = empty;
			positionValues[y1Global][x1Global-1][0] = ' '; 
			positionValues[y1Global][x1Global-1][1] = ' '; 
			return valid;
		}
		if (board[0][y1Global][x1Global+1].type == 1 && enpassant == 1 && x1Global+1 == x2Global && (y1Global == y2Global+1)) {
			board[0][y1Global-1][x1Global+1] = s;
			board[0][y1Global][x1Global] =   empty;
			board[0][y1Global][x1Global+1] = empty;
			positionValues[y1Global][x1Global+1][0] = ' '; 
			positionValues[y1Global][x1Global+1][1] = ' '; 
			return valid;
		}
	}
	//Promotion
		if ((board[0][y1Global][x1Global].type == 1) && (board[0][y1Global][x1Global].color == 'W') && ((y1Global == 6) && (y2Global == 7))){
		board[0][y1Global][x1Global] = empty;
		printf("Promotion! White, please enter: 2 for Knight, 3 for Bishop, 4 for Rook, 5 for Queen\n");
		scanf(" %d", &promotion);
			printf("Promoted!");
			board[0][y2Global][x2Global].type = promotion;
			board[0][y2Global][x2Global].color = 'W';
			board[0][y2Global][x2Global].hasMoved = 1; 
			positionValues[y2Global][x2Global][0] = (char)(positionValues[y1Global][x1Global][0]) ;
			if (promotion == 5 ){
				printf("\nX2 Global is : %d", x2Global);
				positionValues[y2Global][x2Global][1] = 'Q';
			}
			if (promotion == 4 ){
				positionValues[y2Global][x2Global][1] = 'R';
			}
			if (promotion == 3 ){
				positionValues[y2Global][x2Global][1] = 'B';
			}
			if (promotion == 2 ){
				positionValues[y2Global][x2Global][1] = 'N';
			}
			positionValues[y1Global][x1Global][0] = ' ';
			positionValues[y1Global][x1Global][1] = ' ';
			promotion = 0;
			valid = 2;
			return valid;
		}

	if ((board[0][y1Global][x1Global].type == 1) && (board[0][y1Global][x1Global].color == 'B') && ((y2Global == 0) && (y1Global==1))){
		board[0][y1Global][x1Global] = empty;
		printf("Promotion! Black, please enter: 2 for Knight, 3 for Bishop, 4 for Rook, 5 for Queen\n");
		scanf(" %d", &promotion);
			printf("Promoted!");
			board[0][y2Global][x2Global].type = promotion;
			board[0][y2Global][x2Global].color = 'B';
			board[0][y2Global][x2Global].hasMoved = 1; 
			positionValues[y2Global][x2Global][0] = (char)(positionValues[y1Global][x1Global][0]) ;
			if (promotion == 5 ){
				positionValues[y2Global][x2Global][1] = 'Q';
			}
			if (promotion == 4 ){
				positionValues[y2Global][x2Global][1] = 'R';
			}
			if (promotion == 3 ){
				positionValues[y2Global][x2Global][1] = 'B';
			}
			if (promotion == 2 ){
				positionValues[y2Global][x2Global][1] = 'N';
			}
			positionValues[y1Global][x1Global][0] = ' ';
			positionValues[y1Global][x1Global][1] = ' ';
			promotion = 0;
			valid = 2;
			return valid;
		}
	//castling
	/*printf("PLAYER COLOR IS : %d\n", playercolor);
	printf("x1Global : %d || y1Global : %d || x2Global : %d || y2Global : %d || SourcePieceColor : %c || DestPieceColor : %c || PlayerColor : %c\n", x1Global, y1Global, x2Global, y2Global, board[0][y1Global][x1Global].color, board[0][y2Global][x2Global].color, playercolor);
	printf("KingHasMoved : %d || RookHasMoved : %d\n", board[0][y1Global][x1Global].hasMoved, board[0][y2Global][x2Global].hasMoved);
	printf("First Space empty : %d || Second Space empty : %d\n", board[0][y1Global][x1Global+1].type, board[0][y1Global][x1Global+2].type);*/
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
