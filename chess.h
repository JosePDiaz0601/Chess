#ifndef CHESSHEADER
#define CHESSHEADER


char justMovedPieceColor;	//this variable stores either 'w' or 'b' for the piece that moved most recently (either from AI or human)
char justMovedPieceType;	/*this variable stores 'P','N','B','R','Q','K' for the type of the piece that
							moved most recently*/
char movePart1[3], movePart2[3];
char computerMovePart1[3];
char computerMovePart2[3];
int destSquareCol;
int destSquareRow;
int userColor;
int aiColor;

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
