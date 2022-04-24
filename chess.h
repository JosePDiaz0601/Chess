#ifndef CHESSHEADER
#define CHESSHEADER

#include <stdio.h>
#include <stdbool.h>
#include "chessAI.h"
#include "chessPieces.h"


void newBoard();

int getAIMoveInitialSquareRow();

int getAIMoveInitialSquareColumn();

int getAIMoveFinalSquareRow();

int getAIMoveFinalSquareColumn();

void displayErrorParsingInput();

void resetStartingPosition();

void printCurrentBoardBlackPerspective();

void printCurrentBoardWhitePerspective();

void viewGameSettings();

void displayStartingMenu();

void printPromptBlackToMove();

void printPromptWhiteToMove();


#endif
