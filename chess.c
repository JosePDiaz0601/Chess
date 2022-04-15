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
    // Creating the array for tha board
    // struct PIECE board[8][8];

    // The Empty Piece
    struct PIECE *empty = {7, 'W', 0};

    // Create and assign the pieces
    struct PIECE *pawn0 = {1, 'W', 0};
    board[1][0] = *pawn0;

    struct PIECE *pawn1 = {1, 'W', 0};
    board[1][1] = *pawn1;

    struct PIECE *pawn2 = {1, 'W', 0};
    board[1][2] = *pawn2;

    struct PIECE *pawn3 = {1, 'W', 0};
    board[1][3] = *pawn3;

    struct PIECE *pawn4 = {1, 'W', 0};
    board[1][4] = *pawn4;

    struct PIECE *pawn5 = {1, 'W', 0};
    board[1][5] = *pawn5;

    struct PIECE *pawn6 = {1, 'W', 0};
    board[1][6] = *pawn6;

    struct PIECE *pawn7 = {1, 'W', 0};
    board[1][7] = *pawn7;

    struct PIECE *pawn0B = {1, 'B', 0};
    board[6][0] = *pawn0B;

    struct PIECE *pawn1B = {1, 'B', 0};
    board[6][1] = *pawn1B;

    struct PIECE *pawn2B = {1, 'B', 0};
    board[6][2] = *pawn2B;

    struct PIECE *pawn3B = {1, 'B', 0};
    board[6][3] = *pawn3B;

    struct PIECE *pawn4B = {1, 'B', 0};
    board[6][4] = *pawn4B;

    struct PIECE *pawn5B = {1, 'B', 0};
    board[6][5] = *pawn5B;

    struct PIECE *pawn6B = {1, 'B', 0};
    board[6][6] = *pawn6B;

    struct PIECE *pawn7B = {1, 'B', 0};
    board[6][7] = *pawn7B;

    struct PIECE *rook0 = {4, 'W', 0};
    board[0][0] = *rook0;

    struct PIECE *rook1 = {4, 'W', 0};
    board[0][7] = *rook1;

    struct PIECE *rook0B = {4, 'B', 0};
    board[7][0] = *rook0B;

    struct PIECE *rook1B = {4, 'B', 0};
    board[7][7] = *rook1B;

    struct PIECE *knight0 = {2, 'W', 0};
    board[0][1] = *knight0;

    struct PIECE *knight1 = {2, 'W', 0};
    board[0][6] = *knight1;

    struct PIECE *knight0B = {2, 'B', 0};
    board[7][1] = *knight0B;

    struct PIECE *knight1B = {2, 'B', 0};
    board[7][6] = *knight1B;

    struct PIECE *bishop0 = {3, 'W', 0};
    board[0][2] = *bishop0;

    struct PIECE *bishop1 = {3, 'W', 0};
    board[0][5] = *bishop1;

    struct PIECE *bishop0B = {3, 'B', 0};
    board[7][2] = *bishop0B;

    struct PIECE *bishop1B = {3, 'B', 0};
    board[7][5] = *bishop1B;

    struct PIECE *queen = {5, 'W', 0};
    board[0][3] = *queen;

    struct PIECE *queenB = {5, 'B', 0};
    board[7][3] = *queenB;

    struct PIECE *king = {6, 'W', 0};
    board[0][4] = *king;

    struct PIECE *kingB = {6, 'B', 0};
    board[7][4] = *kingB;

    // Instantiate blank spaces as null
    for (int i = 2; i < 6; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            board[i][j] = *empty;
        }
    }
}

/* EOF */
