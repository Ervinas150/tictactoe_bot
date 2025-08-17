
#include "../game/game.h"
#include "ai.h"
#include "../utils/utils.h"

void evaluate(char board[][3], char botSym, int *x, int *y)
{
    int score = -1;
    int bestScore = -2;
    int tempx;
    int tempy;

    int i;
    int k;

    //finding out the other players symbol
    char userSym = ' ';
    if(botSym == 'O')
    {
        userSym = 'X';
    }
    else
    {
        userSym = 'O';
    }

    for(i = 0; i < 3; i++)
    {
        for(k = 0; k < 3; k++)
        {
            //if the board is empty we try it and see the minimax score on it
            if(board[i][k] == '0')
            {
                board[i][k] = botSym;

                score = minimax(board, botSym, userSym);
                if(bestScore < score)
                {
                    bestScore = score;
                    *x = i;
                    *y = k;

                }

                board[i][k] = '0';
            }

        }

    }//end for loop

}

int minimax(char board[][3], char MAX, char MIN)
{
    int stateWinCheck = winCheck(board, '0');

    int i = 0;
    int k = 0;

    //first check if its in terminal value
    if((stateWinCheck == 1) || (isFull(board) == 1))
    {
        //if the game is full and no one won, its a draw return 0
        if((stateWinCheck == 0) && (isFull(board) == 1))
        {
            return 0;

        }

        //if max player wins return 1
        else if(winCheck(board, MAX) == 1)
        {
            return 1;
        }

        //if min player wins return -1
        else if(winCheck(board, MIN) == 1)
        {
            return -1;
        }

    }
    else if(whoTurn(board, 'X') == MAX)//MAXIMISING
    {
        int values = -2;

        for(i = 0; i < 3; i++)
        {
            for(k = 0; k < 3; k++)
            {
                if(board[i][k] == '0')
                {
                    board[i][k] = MAX;
                    values = max(values, minimax(board, MAX, MIN));

                    board[i][k] = '0';
                }

            }

        }
        return values;
        
    }
    else //MINIMISING
    {
 
        int values = 2;

        for(i = 0; i < 3; i++)
        {
            for(k = 0; k < 3; k++)
            {
                if(board[i][k] == '0')
                {
                    board[i][k] = MIN;
                    values = min(values, minimax(board, MAX, MIN));

                    board[i][k] = '0';
                }

            }

        }
        return values;
    }

}