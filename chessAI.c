/*********************************************************************/
/* Chess Assignment, for EECS 22L, Spring 22                         */
/*                                                                   */
/* Initial author: Batman (Paul) Robin (Cameron)                     */
/*                                                                   */
/* ChessAI.c: C file for Artifical Intelligence                      */
/*                                                                   */
/*********************************************************************/

#include <stdlib.h>
#include <time.h>
#include "chessAI.h"
#include "chessPieces.h"

void randomMove()
{
    // First is location on board, second is the available locations to move on the board
    //int moves[64][64];
    int moves[8][8][64];
    int *temp;
    int succ = 0;
    time_t t;
    userColor;
    aiColor;
    // Color Initialization
    if (userColor == 0)
        aiColor = 1;
    else
        aiColor = 0;
    int i2, j2;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            temp = getRangeOfMotion(i, j);
            for (int k = 0; k < 64; k++)
            {
                moves[i][j][k] = *(temp+(x2Global + (8*y2Global)));
            }
        }
    }
    // Inefficent asf because it does 2 rands a misses a lot before making a move
    while (succ == 0)
    {
        srand((unsigned)time(&t));
        //int location = (rand() % 64);
        int locationx = (rand() % 64);
        int locationy = (rand() % 64);
        int moveset = (rand() % 64);
        if (moves[locationx][locationy][moveset] == 0)
        {
            continue;
        }
        // Promotion check, if not move randomly
        else if (moves[locationx][locationy][moveset] == 1)
        {
            int movesetx = moveset % 8;
            int movesety = moveset / 8;
            if (board[0][locationy][locationx].color != userColor && board[0][locationy][locationx].color != 'E')
            {
                if (board[0][locationy][locationx].type == 1)
                {
                    if (aiColor == 0 && locationy == 6)
                    {
                        // If Prommotion becomes avilaible as a function change this line
                        //board[0][locationy][locationx].type = 5;
                        //movePiece((location / 8), (location % 8), 7, (location % 8));
                    }
                    else if (aiColor == 1 && locationy == 1) 
                    {
                        
                        //board[0][location][moveset].type = 5;
                        //movePiece((location / 8), (location % 8), 0, (location % 8));
                    }
                    succ = 1;
                }
                x1Global = locationx;
                y1Global = locationy;
                x2Global = movesetx;
                y2Global = movesety;

                movePiece(x1Global, y1Global, x2Global, y2Global, aiColor);
                    succ = 1;
            }
        }
    }
}
