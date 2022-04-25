/* This program contains the loop of the main gameplay. A menu is shown prompting
 * the user to start a game against an AI, view game settings, or exit the game.  
 * The board display based on ASCII text updates after every move for White and Black.
 */
#include <stdio.h>
#include <stdbool.h>
#include "chessPieces.h"
//#include "chessPieces.c"
//#include "chessAI.c"
#include "chessAI.h"
//#include "LogFile.c"
#include "LogFile.h"
#include "chess.h"

int userColor; //the int that user types to choose color 0 for white 1 for black
// array with initial positions of chess pieces, have the zeroth row correspond to white's first rank
// columns go from a to h on board, 0 to 7 for array indices
//
char positionValues[8][8][3] = {
    {{'w', 'R', '\0'}, {'w', 'N', '\0'}, {'w', 'B', '\0'}, {'w', 'Q', '\0'}, {'w', 'K', '\0'}, {'w', 'B', '\0'}, {'w', 'N', '\0'}, {'w', 'R', '\0'}}, // First rank of board , index 0 for row of array
    {{'w', 'P', '\0'}, {'w', 'P', '\0'}, {'w', 'P', '\0'}, {'w', 'P', '\0'}, {'w', 'P', '\0'}, {'w', 'P', '\0'}, {'w', 'P', '\0'}, {'w', 'P', '\0'}}, // second rank
    {{' ', ' ', '\0'}, {' ', ' ', '\0'}, {' ', ' ', '\0'}, {' ', ' ', '\0'}, {' ', ' ', '\0'}, {' ', ' ', '\0'}, {' ', ' ', '\0'}, {' ', ' ', '\0'}}, // third rank
    {{' ', ' ', '\0'}, {' ', ' ', '\0'}, {' ', ' ', '\0'}, {' ', ' ', '\0'}, {' ', ' ', '\0'}, {' ', ' ', '\0'}, {' ', ' ', '\0'}, {' ', ' ', '\0'}}, // fourth rank
    {{' ', ' ', '\0'}, {' ', ' ', '\0'}, {' ', ' ', '\0'}, {' ', ' ', '\0'}, {' ', ' ', '\0'}, {' ', ' ', '\0'}, {' ', ' ', '\0'}, {' ', ' ', '\0'}}, // fifth rank
    {{' ', ' ', '\0'}, {' ', ' ', '\0'}, {' ', ' ', '\0'}, {' ', ' ', '\0'}, {' ', ' ', '\0'}, {' ', ' ', '\0'}, {' ', ' ', '\0'}, {' ', ' ', '\0'}}, // sixth rank
    {{'b', 'P', '\0'}, {'b', 'P', '\0'}, {'b', 'P', '\0'}, {'b', 'P', '\0'}, {'b', 'P', '\0'}, {'b', 'P', '\0'}, {'b', 'P', '\0'}, {'b', 'P', '\0'}}, // seventh rank of board, index 6 for row of array
    {{'b', 'R', '\0'}, {'b', 'N', '\0'}, {'b', 'B', '\0'}, {'b', 'Q', '\0'}, {'b', 'K', '\0'}, {'b', 'B', '\0'}, {'b', 'N', '\0'}, {'b', 'R', '\0'}}  // eight rank, index 7 for row of array
};
// (0,0) corresponds to a1, (4,7) corresponds to d7, (7,7) corresponds to h8




void promptWhiteToMove(){
    printf("\nWhite to move. Please enter a move in the format of initial square \n");
    printf("and destination square (e.g. e2 e4). Note that the file must be \n");
    printf("typed in lowercase (a to h), and the rank must be from 1 to 8. For castling \n");
    printf("type the square of the king's current position as the initial square and the \n");
    printf("square of the rook's current position as the final square (e.g. e1 h1). : ");
}

void promptBlackToMove(){
    printf("\nBlack to move. Please enter a move in the format of initial square \n");
    printf("and destination square (e.g. e2 e4). Note that the file must be \n");
    printf("typed in lowercase (a to h), and the rank must be from 1 to 8. For castling \n");
    printf("type the square of the king's current position as the initial square and the \n");
    printf("square of the rook's current position as the final square (e.g. e8 h8). : ");
}

void displayStartingMenu()
{
    // display menu prompt
    printf("\nWelcome to Unoptimized Chess, our newly released chess game from Loading.. !\n");
    printf("1. Start New Game (Human v. AI)\n");
    printf("2. Game Settings\n");
    printf("3. Exit Game\n");
    newBoard();
}

// explain some game settings to user
void viewGameSettings()
{
    printf("\nFor this version release, the human user may choose which color to play as. ");
    printf("\nThere is no limit on the number of moves that can be played. ");
    printf("\nFor more information about the program objectives, we urge players to ");
    printf("\nconsult the user manual. ");
}

void printCurrentBoard(){
	// display the current positions from White's view
	if (userColor == 0){
        printf("\n  +----+----+----+----+----+----+----+----+\n");
        int i;
        for (i = 8; i > 0; i--)
        {
            int j = 0;
            printf("%d | %s | %s | %s | %s | %s | %s | %s | %s |\n", i, positionValues[i - 1][j], positionValues[i - 1][j + 1], positionValues[i - 1][j + 2], positionValues[i - 1][j + 3], positionValues[i - 1][j + 4], positionValues[i - 1][j + 5], positionValues[i - 1][j + 6], positionValues[i - 1][j + 7]);
            printf("  +----+----+----+----+----+----+----+----+\n");
        }
        printf("    a    b    c    d    e    f    g    h");
        printf("\n========================================================================");
        printf("\n========================================================================");
    }
	// display the current positions from Black's view
	else{
        printf("\n  +----+----+----+----+----+----+----+----+\n");
        for (int i = 0; i < 8; i++)
        {
            int j = 7;
            printf("%d | %s | %s | %s | %s | %s | %s | %s | %s |\n", i+1, positionValues[i][j], positionValues[i][j - 1], positionValues[i][j - 2], positionValues[i][j - 3], positionValues[i][j - 4], positionValues[i][j - 5], positionValues[i][j - 6], positionValues[i][j - 7]);
            printf("  +----+----+----+----+----+----+----+----+\n");
        }
        printf("    h    g    f    e    d    c    b    a");
        printf("\n========================================================================");
        printf("\n========================================================================");
    }
}

// display the starting position
void resetStartingPosition()
{
    whiteIsInCheck = 0;
    blackIsInCheck = 0;
    checkMate = 0;
    char boardStartingValues[8][8][3] = {
        {{'w', 'R', '\0'}, {'w', 'N', '\0'}, {'w', 'B', '\0'}, {'w', 'Q', '\0'}, {'w', 'K', '\0'}, {'w', 'B', '\0'}, {'w', 'N', '\0'}, {'w', 'R', '\0'}}, // First rank of board , index 0 for row of array
        {{'w', 'P', '\0'}, {'w', 'P', '\0'}, {'w', 'P', '\0'}, {'w', 'P', '\0'}, {'w', 'P', '\0'}, {'w', 'P', '\0'}, {'w', 'P', '\0'}, {'w', 'P', '\0'}}, // second rank
        {{' ', ' ', '\0'}, {' ', ' ', '\0'}, {' ', ' ', '\0'}, {' ', ' ', '\0'}, {' ', ' ', '\0'}, {' ', ' ', '\0'}, {' ', ' ', '\0'}, {' ', ' ', '\0'}}, // third rank
        {{' ', ' ', '\0'}, {' ', ' ', '\0'}, {' ', ' ', '\0'}, {' ', ' ', '\0'}, {' ', ' ', '\0'}, {' ', ' ', '\0'}, {' ', ' ', '\0'}, {' ', ' ', '\0'}}, // fourth rank
        {{' ', ' ', '\0'}, {' ', ' ', '\0'}, {' ', ' ', '\0'}, {' ', ' ', '\0'}, {' ', ' ', '\0'}, {' ', ' ', '\0'}, {' ', ' ', '\0'}, {' ', ' ', '\0'}}, // fifth rank
        {{' ', ' ', '\0'}, {' ', ' ', '\0'}, {' ', ' ', '\0'}, {' ', ' ', '\0'}, {' ', ' ', '\0'}, {' ', ' ', '\0'}, {' ', ' ', '\0'}, {' ', ' ', '\0'}}, // sixth rank
        {{'b', 'P', '\0'}, {'b', 'P', '\0'}, {'b', 'P', '\0'}, {'b', 'P', '\0'}, {'b', 'P', '\0'}, {'b', 'P', '\0'}, {'b', 'P', '\0'}, {'b', 'P', '\0'}}, // seventh rank of board, index 6 for row of array
        {{'b', 'R', '\0'}, {'b', 'N', '\0'}, {'b', 'B', '\0'}, {'b', 'K', '\0'}, {'b', 'Q', '\0'}, {'b', 'B', '\0'}, {'b', 'N', '\0'}, {'b', 'R', '\0'}}  // eight rank, index 7 for row of array
    };
    int i;
    for (i = 0; i < 8; i++)
    {
        int j;
        for (j = 0; j < 8; j++)
        {
            int k;
            for (k = 0; k < 3; k++)
            {
                positionValues[i][j][k] = (char)(boardStartingValues[i][j][k]);
            }
        }
    }
}
// display an error parsing the move input
void displayErrorParsingInput()
{
    printf("\nERROR. Cannot parse move. Please enter a move in the following format,");
    printf("\ncurrentSquare space destinationSquare (e.g. ‘f1 c4’). Make sure that ");
    printf("\nthe rank and file of the currentSquare and destinationSquare are ");
    printf("\nwithin the limits of a chessboard (a to h and 1 to 8). A new message ");
    printf("\nprompting the user for input will be displayed until a correctly ");
    printf("\nformatted move is inputted.\n");
}

// main function that determines which version of game to play and whether to exit
int main(void)
{
    int promptInput = 0;          /* user's input (from menu, choose 1 to start game,
    2 to view game settings, 3 to exit game) assigned to promptInput*/
    userColor = 0; //set color to 0 (white) by default before taking user's choice
    //char colorInputStr[2][6] = {
    //		{'W','h','i','t','e'} ,
	//		{'B','l','a','c','k'}
    //};
    bool programFinished = false; // checks whether game is exited
    int turn;
    turn = 0;
    //when turn % 2 == 0 (white's Turn), when turn % 2 == 1 (black's Turn)

/**    char movePart1[3], movePart2[3];
    char computerMovePart1[3];
    char computerMovePart2[3];*/
    while (!programFinished)
    {
        displayStartingMenu();
        printf("Choose Option: ");
        scanf("%d", &promptInput);
        printf("=====================================================================================");
        printf("\n=====================================================================================");
        if (promptInput == 1)
        {
            // print board with starting position, for alpha release, user does not choose color to play
            bool gameOver = false;
            int moveCount = 0;
            printf("\nPick a color to play as.\n");
            printf("0. White\n");
            printf("1. Black\n");
            printf("Choose Option: ");
            scanf("%d", &userColor);
            if (userColor == 0)
            aiColor = 1;
              else
            aiColor = 0;
            printCurrentBoard();
            //initialize variables for current square and destination square of piece to be moved
            int currentSquareRow = -1;
            int currentSquareCol = -1;
            int destSquareRow = -1;
            int destSquareCol = -1;
            //initialize variables for current square and destination square of piece to be moved
            int computerMoveCurrentSquareRow = -1;
            int computerMoveCurrentSquareCol = -1;
            int computerMoveDestSquareRow = -1;
            int computerMoveDestSquareCol = -1;
            while (!gameOver)
            {
            	if ((turn % 2) == 0){
                	if(userColor == 0){
                        promptWhiteToMove();
                        scanf("%s", movePart1);
                        scanf("%s", movePart2);
                        //            printf("String is : \n");
                        //            printf("%s %s %s \n" ,movePart1,movePart2,movePart3);
                        // See if you can take move inputs and just update the ASCII-based text board
                        currentSquareCol = (int)(movePart1[0]) - 97; // a - 97 in ASCII corresponds to 0th column
                        currentSquareRow = (int)(movePart1[1]) - 49;
                        destSquareCol = (int)(movePart2[0]) - 97; // a - 97 in ASCII corresponds to 0th column
                        destSquareRow = (int)(movePart2[1]) - 49;
                        while (!((currentSquareRow >= 0 && currentSquareRow <= 7) &&
                                 (currentSquareCol >= 0 && currentSquareCol <= 7) &&
                                 (destSquareRow >= 0 && destSquareRow <= 7) &&
                                 (destSquareCol >= 0 && destSquareCol <= 7)))
                        {
                            displayErrorParsingInput();
                            promptWhiteToMove();
                            scanf("%s", movePart1);
                            scanf("%s", movePart2);
                            currentSquareCol = (int)(movePart1[0]) - 97; // a - 97 in ASCII corresponds to 0th column
                            currentSquareRow = (int)(movePart1[1]) - 49; // 1 as an ASCII char corresponds to 0th row
                            destSquareCol = (int)(movePart2[0]) - 97;    // a - 97 in ASCII corresponds to 0th column
                            destSquareRow = (int)(movePart2[1]) - 49;    // 1 as an ASCII char corresponds to 0th row
                        }
                        turn += 1;
                        int check = movePiece(currentSquareCol, currentSquareRow, destSquareCol, destSquareRow, userColor);
                        
                        if (check == 0){
                            if(currentSquareCol == 4 && currentSquareRow == 0 && destSquareCol == 7 && destSquareRow == 0){
                                positionValues[0][6][0] = (char)(positionValues[0][4][0]);
                                positionValues[0][6][1] = (char)(positionValues[0][4][1]);
                                positionValues[0][5][0] = (char)(positionValues[0][7][0]);
                                positionValues[0][5][1] = (char)(positionValues[0][7][1]);
                                positionValues[0][4][0] = ' ';
                                positionValues[0][4][1] = ' ';
                                positionValues[0][7][0] = ' ';
                                positionValues[0][7][1] = ' ';
                                randomMove();
                            }else if(currentSquareCol == 4 && currentSquareRow == 7 && destSquareCol == 7 && destSquareRow == 7){
                                positionValues[7][6][0] = (char)(positionValues[7][4][0]);
                                positionValues[7][6][1] = (char)(positionValues[7][4][1]);
                                positionValues[7][5][0] = (char)(positionValues[7][7][0]);
                                positionValues[7][5][1] = (char)(positionValues[7][7][1]);
                                positionValues[7][4][0] = ' ';
                                positionValues[7][4][1] = ' ';
                                positionValues[7][7][0] = ' ';
                                positionValues[7][7][1] = ' ';
                                randomMove();
                            }else if(currentSquareCol == 4 && currentSquareRow == 7 && destSquareCol == 0 && destSquareRow == 7){
                                positionValues[7][2][0] = (char)(positionValues[7][4][0]);
                                positionValues[7][2][1] = (char)(positionValues[7][4][1]);
                                positionValues[7][3][0] = (char)(positionValues[7][0][0]);
                                positionValues[7][3][1] = (char)(positionValues[7][0][1]);
                                positionValues[7][4][0] = ' ';
                                positionValues[7][4][1] = ' ';
                                positionValues[7][0][0] = ' ';
                                positionValues[7][0][1] = ' ';
                                randomMove();
                            }else if(currentSquareCol == 4 && currentSquareRow == 0 && destSquareCol == 0 && destSquareRow == 0){
                                positionValues[0][2][0] = (char)(positionValues[0][4][0]);
                                positionValues[0][2][1] = (char)(positionValues[0][4][1]);
                                positionValues[0][3][0] = (char)(positionValues[0][0][0]);
                                positionValues[0][3][1] = (char)(positionValues[0][0][1]);
                                positionValues[0][4][0] = ' ';
                                positionValues[0][4][1] = ' ';
                                positionValues[0][0][0] = ' ';
                                positionValues[0][0][1] = ' ';
                                randomMove();
                            }else{
								positionValues[destSquareRow][destSquareCol][0] = (char)(positionValues[currentSquareRow][currentSquareCol][0]);
								positionValues[destSquareRow][destSquareCol][1] = (char)(positionValues[currentSquareRow][currentSquareCol][1]);

								positionValues[currentSquareRow][currentSquareCol][0] = ' ';
								positionValues[currentSquareRow][currentSquareCol][1] = ' ';
								//store color and type of piece that just moved
								justMovedPieceColor = (char)(positionValues[destSquareRow][destSquareCol][0]);
								justMovedPieceType = (char)(positionValues[destSquareRow][destSquareCol][1]);
                                randomMove();
                            }
                        }
                        else if (check == 1){
        //                    printf("INVALID MOVE, PLEASE ENTER A POSSIBLE MOVE");
                            printf("\nERROR. An illegal move has been made. Please enter an allowed move\n");
                            printf("according to the rules of chess. For more information on legal moves,\n");
                            printf("consult our user manual’s glossary and index containing definitions of\n");
                            printf("specific pieces, their allowed range of squares to move to, and other\n");
                            printf("details regarding move limitations.\n");
                            continue;
                        }
                        printf("\n========================================================================");
                        printf("\n========================================================================");
                        printCurrentBoard();
                        if ((checkMate != 0)){
                        	gameOver = true;
                            programFinished = true;
                        	break;
                        }
                        
                        WriteToLog(movePart1,movePart2,justMovedPieceColor,justMovedPieceType);
                	}
                	//White's turn with the AI being white.
                	else{
                	    printf("\nWhite to move. It is the computer's turn.");
                	    //convert computer's move to a string
                        computerMoveCurrentSquareRow = y1Global;
                        computerMoveCurrentSquareCol = x1Global;
                        computerMoveDestSquareRow = y2Global;
                        computerMoveDestSquareCol = x2Global;
                        char firstChar = 'a';
                        char secondChar = '1';
                        firstChar = (char)(computerMoveCurrentSquareCol + 97);
                        secondChar = (char)(computerMoveCurrentSquareRow + 49);
                        computerMovePart1[0] = firstChar;
                        computerMovePart1[1] = secondChar;
                        computerMovePart1[2] = '\0';

                        firstChar = (char)(computerMoveDestSquareCol + 97);
                        secondChar = (char)(computerMoveDestSquareRow + 49);

						computerMovePart2[0] = firstChar;
                        computerMovePart2[1] = secondChar;
                        computerMovePart2[2] = '\0';
                        turn += 1;

						//store color and type of piece that just moved
						justMovedPieceColor = (char)(positionValues[computerMoveDestSquareRow][computerMoveDestSquareCol][0]);
						justMovedPieceType = (char)(positionValues[computerMoveDestSquareRow][computerMoveDestSquareCol][1]);
						printf("\nThe computer has chosen to play %s %s\n",computerMovePart1,computerMovePart2);
                        printCurrentBoard();
                        if ((checkMate != 0)){
                        	gameOver = true;
                            programFinished = true;
                        	break;

                	}

                    WriteToLog(computerMovePart1,computerMovePart2,justMovedPieceColor,justMovedPieceType); 
                }
                }
                //else: It is the turn of Black regardless of which side is the AI and which is the human user
                //turb % 2 ==1
                else{
                	//Black's turn with human being white
                	if(userColor == 0){
                	    printf("\nBlack to move. It is the computer's turn.");
                	    //convert computer's move to a string
                        computerMoveCurrentSquareRow = y1Global;
                        computerMoveCurrentSquareCol = x1Global;
                        computerMoveDestSquareRow = y2Global;
                        computerMoveDestSquareCol = x2Global;

                        char firstChar = 'a';
                        char secondChar = '1';
                        firstChar = (char)(computerMoveCurrentSquareCol + 97);
                        secondChar = (char)(computerMoveCurrentSquareRow + 49);
                        computerMovePart1[0] = firstChar;
                        computerMovePart1[1] = secondChar;
                        computerMovePart1[2] = '\0';

                        firstChar = (char)(computerMoveDestSquareCol + 97);
                        secondChar = (char)(computerMoveDestSquareRow + 49);

						computerMovePart2[0] = firstChar;
                        computerMovePart2[1] = secondChar;
                        computerMovePart2[2] = '\0';
                        turn += 1;
						printf("\nThe computer has chosen to play %s %s\n",computerMovePart1,computerMovePart2);
						printCurrentBoard();
                        if ((checkMate != 0)){
                        	gameOver = true;
                            programFinished = true;
                        	break;
                        
                        }
                     WriteToLog(computerMovePart1,computerMovePart2,justMovedPieceColor,justMovedPieceType); 
                	}
                	//Black's turn with human being black
                	else{
                        promptBlackToMove();
                        scanf("%s", movePart1);
                        scanf("%s", movePart2);
                        currentSquareCol = (int)(movePart1[0]) - 97; // a - 97 in ASCII corresponds to 0th column
                        currentSquareRow = (int)(movePart1[1]) - 49; // 1 as an ASCII char corresponds to 0th row
                        destSquareCol = (int)(movePart2[0]) - 97;    // a - 97 in ASCII corresponds to 0th column
                        destSquareRow = (int)(movePart2[1]) - 49;    // 1 as an ASCII char corresponds to 0th row

                        while (!((currentSquareRow >= 0 && currentSquareRow <= 8) &&
                                 (currentSquareCol >= 0 && currentSquareCol <= 8) &&
                                 (destSquareRow >= 0 && destSquareRow <= 8) &&
                                 (destSquareCol >= 0 && destSquareCol <= 8)))
                        {
                            displayErrorParsingInput();
                            promptBlackToMove();
                            scanf("%s", movePart1);
                            scanf("%s", movePart2);
                            currentSquareCol = (int)(movePart1[0]) - 97; // a - 97 in ASCII corresponds to 0th column
                            currentSquareRow = (int)(movePart1[1]) - 49; // 1 as an ASCII char corresponds to 0th row
                            destSquareCol = (int)(movePart2[0]) - 97;    // a - 97 in ASCII corresponds to 0th column
                            destSquareRow = (int)(movePart2[1]) - 49;    // 1 as an ASCII char corresponds to 0th row
                        }
                        turn += 1; //updates whose turn it is
                        int check = movePiece(currentSquareCol, currentSquareRow, destSquareCol, destSquareRow, userColor);
                        if (check == 0){
                            if(currentSquareCol == 4 && currentSquareRow == 0 && destSquareCol == 7 && destSquareRow == 0){
                                positionValues[0][6][0] = (char)(positionValues[0][4][0]);
                                positionValues[0][6][1] = (char)(positionValues[0][4][1]);
                                positionValues[0][5][0] = (char)(positionValues[0][7][0]);
                                positionValues[0][5][1] = (char)(positionValues[0][7][1]);
                                positionValues[0][4][0] = ' ';
                                positionValues[0][4][1] = ' ';
                                positionValues[0][7][0] = ' ';
                                positionValues[0][7][1] = ' ';
                                randomMove();
                            }else if(currentSquareCol == 4 && currentSquareRow == 7 && destSquareCol == 7 && destSquareRow == 7){
                                positionValues[7][6][0] = (char)(positionValues[7][4][0]);
                                positionValues[7][6][1] = (char)(positionValues[7][4][1]);
                                positionValues[7][5][0] = (char)(positionValues[7][7][0]);
                                positionValues[7][5][1] = (char)(positionValues[7][7][1]);
                                positionValues[7][4][0] = ' ';
                                positionValues[7][4][1] = ' ';
                                positionValues[7][7][0] = ' ';
                                positionValues[7][7][1] = ' ';
                                randomMove();
                            }else if(currentSquareCol == 4 && currentSquareRow == 7 && destSquareCol == 0 && destSquareRow == 7){
                                positionValues[7][2][0] = (char)(positionValues[7][4][0]);
                                positionValues[7][2][1] = (char)(positionValues[7][4][1]);
                                positionValues[7][3][0] = (char)(positionValues[7][0][0]);
                                positionValues[7][3][1] = (char)(positionValues[7][0][1]);
                                positionValues[7][4][0] = ' ';
                                positionValues[7][4][1] = ' ';
                                positionValues[7][0][0] = ' ';
                                positionValues[7][0][1] = ' ';
                                randomMove();
                            }else if(currentSquareCol == 4 && currentSquareRow == 0 && destSquareCol == 0 && destSquareRow == 0){
                                positionValues[0][2][0] = (char)(positionValues[0][4][0]);
                                positionValues[0][2][1] = (char)(positionValues[0][4][1]);
                                positionValues[0][3][0] = (char)(positionValues[0][0][0]);
                                positionValues[0][3][1] = (char)(positionValues[0][0][1]);
                                positionValues[0][4][0] = ' ';
                                positionValues[0][4][1] = ' ';
                                positionValues[0][0][0] = ' ';
                                positionValues[0][0][1] = ' ';
                                randomMove();
                            }else{
                        positionValues[destSquareRow][destSquareCol][0] = (char)(positionValues[currentSquareRow][currentSquareCol][0]);
                        positionValues[destSquareRow][destSquareCol][1] = (char)(positionValues[currentSquareRow][currentSquareCol][1]);

                        positionValues[currentSquareRow][currentSquareCol][0] = ' ';
                        positionValues[currentSquareRow][currentSquareCol][1] = ' ';
                        randomMove();}
                        }else if (check == 1){
        //                    printf("INVALID MOVE, PLEASE ENTER A POSSIBLE MOVE");
                            printf("\nERROR. An illegal move has been made. Please enter an allowed move\n");
                            printf("according to the rules of chess. For more information on legal moves,\n");
                            printf("consult our user manual’s glossary and index containing definitions of\n");
                            printf("specific pieces, their allowed range of squares to move to, and other\n");
                            printf("details regarding move limitations.\n");
                            continue;
                        }else if (check == 2){
                            check = 2;
                        }
                        // display the updated board
                        printf("\n========================================================================");
                        printf("\n========================================================================");
                        printCurrentBoard();
                        if ((checkMate != 0) ){
                        	gameOver = true;
                            programFinished = true;
                        	break;
                        }
                 WriteToLog(movePart1,movePart2, justMovedPieceColor,justMovedPieceType);
                	}
                }
                // increment the count of the moves (1 move is done when both White and Black have finished their turn)
                moveCount++;
                int promptGameExit = 0; // user's input assigned to promptInput
                printf("\nTo stop the game choose (1). Type any other charcter, and the game shall continue: ");
                scanf("%d", &promptGameExit);
                if (promptGameExit == 1)
                {
                    gameOver = true;
                }
            }
        }
        else if (promptInput == 2)
        {
            viewGameSettings();
        }
        else if (promptInput == 3)
        {
            programFinished = true;
        }
        resetStartingPosition();
        printf("\n\n\n\n");
    }
    return 0;
}

/**return the row and column of the initial square and final square of a piece moved by the AI
 * (a-h) corresponds to columns 0 to 7 in the positionValues array
 * (1-8) corresponds to rows 0 to 7 in the positionValues array
 */
int getAIMoveInitialSquareRow()
{
    return 0;
}

int getAIMoveInitialSquareColumn()
{
    return 0;
}

int getAIMoveFinalSquareRow()
{
    return 0;
}

int getAIMoveFinalSquareColumn()
{
    return 0;
}

void newBoard()
{
    // Creating the array for the board
    // struct PIECE board[8][8];

    // The Empty Piece
    struct PIECE empty = {7, 'E', 0};

    // Create and assign the pieces

    struct PIECE pawn0 = {pawn, 'W', 0};
    board[0][1][0] = pawn0;
//   printf("sTEST.type = %d\n", board[1][0].type);
//	printf("sTEST.color = %c\n", board[1][0].color);

    struct PIECE pawn1 = {pawn, 'W', 0};
    board[0][1][1] = pawn1;

    struct PIECE pawn2 = {pawn, 'W', 0};
    board[0][1][2] = pawn2;

    struct PIECE pawn3 = {pawn, 'W', 0};
    board[0][1][3] = pawn3;

    struct PIECE pawn4 = {pawn, 'W', 0};
    board[0][1][4] = pawn4;

    struct PIECE pawn5 = {pawn, 'W', 0};
    board[0][1][5] = pawn5;

    struct PIECE pawn6 = {pawn, 'W', 0};
    board[0][1][6] = pawn6;

    struct PIECE pawn7 = {pawn, 'W', 0};
    board[0][1][7] = pawn7;

    struct PIECE pawn0B = {pawn, 'B', 0};
    board[0][6][0] = pawn0B;

    struct PIECE pawn1B = {pawn, 'B', 0};
    board[0][6][1] = pawn1B;

    struct PIECE pawn2B = {pawn, 'B', 0};
    board[0][6][2] = pawn2B;

    struct PIECE pawn3B = {pawn, 'B', 0};
    board[0][6][3] = pawn3B;

    struct PIECE pawn4B = {pawn, 'B', 0};
    board[0][6][4] = pawn4B;

    struct PIECE pawn5B = {pawn, 'B', 0};
    board[0][6][5] = pawn5B;

    struct PIECE pawn6B = {pawn, 'B', 0};
    board[0][6][6] = pawn6B;

    struct PIECE pawn7B = {pawn, 'B', 0};
    board[0][6][7] = pawn7B;

    struct PIECE rook0 = {rook, 'W', 0};
    board[0][0][0] = rook0;

    struct PIECE rook1 = {rook, 'W', 0};
    board[0][0][7] = rook1;

    struct PIECE rook0B = {rook, 'B', 0};
    board[0][7][0] = rook0B;

    struct PIECE rook1B = {rook, 'B', 0};
    board[0][7][7] = rook1B;

    struct PIECE knight0 = {knight, 'W', 0};
    board[0][0][1] = knight0;

    struct PIECE knight1 = {knight, 'W', 0};
    board[0][0][6] = knight1;

    struct PIECE knight0B = {knight, 'B', 0};
    board[0][7][1] = knight0B;

    struct PIECE knight1B = {knight, 'B', 0};
    board[0][7][6] = knight1B;

    struct PIECE bishop0 = {bishop, 'W', 0};
    board[0][0][2] = bishop0;

    struct PIECE bishop1 = {bishop, 'W', 0};
    board[0][0][5] = bishop1;

    struct PIECE bishop0B = {bishop, 'B', 0};
    board[0][7][2] = bishop0B;

    struct PIECE bishop1B = {bishop, 'B', 0};
    board[0][7][5] = bishop1B;

    struct PIECE queenW = {queen, 'W', 0};
    board[0][0][3] = queenW;

    struct PIECE queenB = {queen, 'B', 0};
    board[0][7][3] = queenB;

    struct PIECE kingW = {king, 'W', 0};
    board[0][0][4] = kingW;

    struct PIECE kingB = {king, 'B', 0};
    board[0][7][4] = kingB;

    // Instantiate blank spaces as null
    for (int y = 0; y < 499; y++)
        for (int i = 2; i < 6; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                board[y][i][j] = empty;
            }
        }
}
// hi
/* EOF */
