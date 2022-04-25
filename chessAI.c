/*********************************************************************/
/* Chess Assignment, for EECS 22L, Spring 22                         */
/*                                                                   */
/* Initial author: Batman (Paul) Robin (Cameron)                     */
/*                                                                   */
/* ChessAI.c: C file for Artifical Intelligence                      */
/*                                                                   */
/*********************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "chessAI.h"
#include "chessPieces.h"
#include "chess.h"
int counter = 0;

void randomMove()
{
    // First is location on board, second is the available locations to move on the board
    // int moves[8][8][64]
    // X by Y by legal moves
    int moves[8][8][64];
    int *temp;
    int succ = 0;
    time_t t;
    // Create time seed
    srand((unsigned)time(&t));
    // Color Initialization (only allows bot to move)
    if (userColor == 0)
        aiColor = 1;
    else
        aiColor = 0;

    printf("\nAI COLOR INITIALIZATION DONE AI COLOR IS : %d", aiColor);
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            temp = getRangeOfMotion(i, j);
            for (int k = 0; k < 64; k++)
            {
                moves[i][j][k] = *(temp + k);
                // printf("\nK IS : %d", moves[i][j][k]);
            }
        }
    }
    // Inefficent asf because it does 2 rands a misses a lot before making a move
    while (succ == 0)
    {

        // int location = (rand() % 64);
        int locationx = (rand() % 8);
        int locationy = (rand() % 8);
        if ((board[0][locationy][locationx].color == 'W' && aiColor == 0) || (board[0][locationy][locationx].color == 'B' && aiColor == 1))
        {
            int moveset = (rand() % 64);
            // printf("\nAI LOCATION X1 : %d\nAI LOCATION Y1 : %d\nMOVESET : %d", locationx, locationy, moves[locationx][locationy][moveset]);

            if (moves[locationx][locationy][moveset] == 0)
            {
                continue;
            }
            // Promotion check, if not move randomly
            else if (moves[locationx][locationy][moveset] == 1)
            {
                int movesetx = moveset % 8;
                int movesety = moveset / 8;
                printf("\nAI LOCATION X1 : %d\nAI LOCATION Y1 : %d\nAI LOCATION X2 : %d\nAI LOCATION Y2 : %d\n", locationx, locationy, movesetx, movesety);
                if (board[0][locationy][locationx].color != userColor && board[0][locationy][locationx].color != 'E')
                {
                    if (board[0][locationy][locationx].type == 1)
                    {
                        if (aiColor == 0 && locationy == 6)
                        {
                            // If Prommotion becomes avilaible as a function change this line
                            // board[0][locationy][locationx].type = 5;
                            // movePiece((location / 8), (location % 8), 7, (location % 8));
                        }
                        else if (aiColor == 1 && locationy == 1)
                        {

                            // board[0][location][moveset].type = 5;
                            // movePiece((location / 8), (location % 8), 0, (location % 8));
                        }
                        // succ = 1;
                    }
                    x1Global = locationx;
                    y1Global = locationy;
                    x2Global = movesetx;
                    y2Global = movesety;

                    int validCheck = movePiece(x1Global, y1Global, x2Global, y2Global, aiColor);
                    printf("\nVALIDCHECK IS : %d\n", validCheck);
                    if (validCheck == 0){
                    positionValues[y2Global][x2Global][0] = (char)(positionValues[y1Global][x1Global][0]);
                    positionValues[y2Global][x2Global][1] = (char)(positionValues[y1Global][x1Global][1]);

                    positionValues[y1Global][x1Global][0] = ' ';
                    positionValues[y1Global][x1Global][1] = ' ';
                    succ = 1;
                    break;
                    }else{
                        succ = 0;
                        continue;
                    }
                }
            }
        }
    }
}

void checkMateAI()
{
    // Color Initialization
    if (userColor == 0)
        aiColor = 1;
    else
        aiColor = 0;
    if (counter == 0)
    {
            movePiece(4, 6, 4, 5, aiColor);
            positionValues[5][4][0] = (char)(positionValues[6][4][0]);
            positionValues[5][4][1] = (char)(positionValues[6][4][1]);

            positionValues[6][4][0] = ' ';
            positionValues[6][4][1] = ' ';
            counter++;
            return;
            
    }
    if (counter == 1)
    {
        movePiece(3, 7, 7, 3, aiColor);
        positionValues[3][7][0] = (char)(positionValues[7][3][0]);
        positionValues[3][7][1] = (char)(positionValues[7][3][1]);

        positionValues[7][3][0] = ' ';
        positionValues[7][3][1] = ' ';
        counter++;
        }
    }

