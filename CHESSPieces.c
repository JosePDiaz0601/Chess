#include "chessPieces.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

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
bool hasMoved;


/*
HOW TO GET X AND Y VALUES FOR RANGE OF MOTION
	rangeOfMotion is 64 spaces wide
	if rangeOfMotion(42) == 1, to get the x and y do:
		int 42/8, which is the y (5)
		int 42%8, which is the x (2)
*/

int * getRangeOfMotion(int piece, char color, int x, int y)
{
	static int rangeOfMotion[64];
    if (piece == 1 && (strcmp("w", color) == 0))
    {
        if (y < 7)
        {
            rangeOfMotion[x+(8*(y+1))] = 1;
            if (hasMoved != 1)
            {
                rangeOfMotion[x+(8*(y+2))] = 1;
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
	if (piece == 7 && (strcmp("b", color) == 0))
    {
        if (y > 0)
        {
            rangeOfMotion[x+(8*(y-1))] = 1;
            if (hasMoved != 1)
            {
                rangeOfMotion[x+(8*(y-2))] = 1;
            }
        }
    }
	
        if (piece == 8){

                while (x+1 < 8 && y-1 < 8)
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
		
	
    if(piece == 9)
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
		
	
	if (piece == 10){
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
	
	if (piece == 11){
		
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
(piece == 12){
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
	return rangeOfMotion;





/*WHEN CALLING rangeOfMotion do this format

int *p;

p = getRangeOfMotion(piece);


P WILL BE ARRAY rangeOfMotion;
*/
