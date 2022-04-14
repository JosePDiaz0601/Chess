/*
 * chess.c
 *
 *  Created on: Apr 11, 2022
 *      Author: arhan
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "chessPieces.h"
#include "chess.h"

/**#define ANSI_COLOR_RED  "\x1B[31m"
#define ANSI_COLOR_GREEN  "\x1B[32m"
#define ANSI_COLOR_BLUE  "\x1B[34m"
#define Color_reset  "\x1B[0m"*/

// array with initial positions of chess pieces, have the zeroth row correspond to white's first rank
// columns go from a to h on board, 0 to 7 for array indices
char positionValues[8][8][3] = {
    {{'w', 'R', '\0'}, {'w', 'N', '\0'}, {'w', 'B', '\0'}, {'w', 'Q', '\0'}, {'w', 'K', '\0'}, {'w', 'B', '\0'}, {'w', 'N', '\0'}, {'w', 'R', '\0'}}, // First rank of board , index 0 for row of array
    {{'w', 'P', '\0'}, {'w', 'P', '\0'}, {'w', 'P', '\0'}, {'w', 'P', '\0'}, {'w', 'P', '\0'}, {'w', 'P', '\0'}, {'w', 'P', '\0'}, {'w', 'P', '\0'}}, // second rank
    {{' ', ' ', '\0'}, {' ', ' ', '\0'}, {' ', ' ', '\0'}, {' ', ' ', '\0'}, {' ', ' ', '\0'}, {' ', ' ', '\0'}, {' ', ' ', '\0'}, {' ', ' ', '\0'}}, // third rank
    {{' ', ' ', '\0'}, {' ', ' ', '\0'}, {' ', ' ', '\0'}, {' ', ' ', '\0'}, {' ', ' ', '\0'}, {' ', ' ', '\0'}, {' ', ' ', '\0'}, {' ', ' ', '\0'}}, // fourth rank
    {{' ', ' ', '\0'}, {' ', ' ', '\0'}, {' ', ' ', '\0'}, {' ', ' ', '\0'}, {' ', ' ', '\0'}, {' ', ' ', '\0'}, {' ', ' ', '\0'}, {' ', ' ', '\0'}}, // fifth rank
    {{' ', ' ', '\0'}, {' ', ' ', '\0'}, {' ', ' ', '\0'}, {' ', ' ', '\0'}, {' ', ' ', '\0'}, {' ', ' ', '\0'}, {' ', ' ', '\0'}, {' ', ' ', '\0'}}, // sixth rank
    {{'b', 'P', '\0'}, {'b', 'P', '\0'}, {'b', 'P', '\0'}, {'b', 'P', '\0'}, {'b', 'P', '\0'}, {'b', 'P', '\0'}, {'b', 'P', '\0'}, {'b', 'P', '\0'}}, // seventh rank of board, index 6 for row of array
    {{'b', 'R', '\0'}, {'b', 'N', '\0'}, {'b', 'B', '\0'}, {'b', 'K', '\0'}, {'b', 'Q', '\0'}, {'b', 'B', '\0'}, {'b', 'N', '\0'}, {'b', 'R', '\0'}}  // eight rank, index 7 for row of array
};
// (0,0) corresponds to a1, (4,7) corresponds to d7, (7,7) corresponds to h8

/**
char player1Sign = 'X';
char player2Sign = 'O';*/
/**
//chars for colors for player 1 and player2
char player1Col = ' ';
char player2Col = ' ';

//arrays to accept move locations
char player1Move[2] = {' ',' '};
char player2Move[2] = {' ',' '};
char playerUserMove[2] = {' ',' '};*/

// main function that determines which version of game to play and whether to exit
int main(void)
{
    int promptInput = 0; // user's input assigned to promptInput
    bool done = false;   // checks whether game is exited

    while (!done)
    {

        // display menu prompt
        printf("Welcome to Unoptimized Chess, our newly released chess game from Loading��!\n");
        //        printf("2. Start New Game (Human v. Human)\n");
        printf("1. Start New Game (Human v. AI)\n");
        printf("2. Game Settings\n");
        printf("3. Exit Game\n");
        printf("Choose Option: ");
        scanf("%d", &promptInput);
        int j;
        if (promptInput == 1)
        {
            // print board with starting position
            printf("  +----+----+----+----+----+----+----+----+\n");
            for (int i = 8; i > 0; i--)
            {
                j = 0;
                printf("%d | %s | %s | %s | %s | %s | %s | %s | %s |\n", i, positionValues[i - 1][j], positionValues[i - 1][j + 1], positionValues[i - 1][j + 2], positionValues[i - 1][j + 3], positionValues[i - 1][j + 4], positionValues[i - 1][j + 5], positionValues[i - 1][j + 6], positionValues[i - 1][j + 7]);
                printf("  +----+----+----+----+----+----+----+----+\n");
            }
            printf("    a    b    c    d    e    f    g    h\n");
            //        	playAgainstAI();
        }
        else if (promptInput == 2)
        {
            //            viewGameSettings();
        }
        else if (promptInput == 3)
        {
            done = true;
        }
        printf("\n\n\n\n");
    }
    return 0;
}

void viewGameSettings()
{
}
// update these functions in the future
void playAgainstAI()
{
}

void newBoard()
{
    struct PIECE board[8][8];
    PIECE *pawn1;
    pawn1 = (PIECE *)malloc(sizeof(IMAGE));
    // Instantiate pawns
    for (int i = 0; i < 8; i++)
    {
    }
}

/* EOF */
