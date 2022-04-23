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
    int moves[64][64];
    int temp[64];
    int succ = 0;
    time_t t;
    int colorInput = 0;
    int AIinput = 0;
    // Color Initialization
    if(colorInput == 0)
      AIinput = 1;
    else
      AIinput = 0;
    
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            temp[64] = getRangeOfMotion(board[0][i][j].type, board[0][i][j].color, i, j, board[0][i][j].hasMoved);
            for (int k = 0; k < 64; k++)
            {
                moves[i + j][k] = temp[k];
            }
        }
    }
    // Inefficent asf because it does 2 rands a misses a lot before making a move
    while (succ == 0)
    {
        srand((unsigned)time(&t));
        int location = (rand() % 64);
        int moveset = (rand() % 64);
        if (moves[location][moveset] == 0)
        {
            continue;
        }
        // Promotion check, if not move randomly
        else if (moves[location][moveset] == 1)
        {
            if(board[0][location][moveset].color != colorInput && board[0][location][moveset].color != 'E')
            {
                if(board[0][location][moveset].type == 1)
                {
                  if(AIinput == 0 && location == 6)
                  {
                    board[0][location][moveset].type = 5;
                    movePiece((location / 8), (location % 8), 7, (location % 8));
                  }
                  else
                  {
                    if(location == 1)
                      board[0][location][moveset].type = 5;
                      movePiece((location / 8), (location % 8), 0, (location % 8));
                  }
                }
                else
                {
                  movePiece((location / 8), (location % 8), (moveset / 8), (moveset % 8));
                  succ = 1;
                }
            }
        }
    }
    
}
