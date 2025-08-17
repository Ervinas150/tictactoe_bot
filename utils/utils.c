#include<stdio.h>

#include "../game/game.h"
#include "../ai/ai.h"
#include "utils.h"

//checks if someone has won the game if the second paramater is "0" 
//or looks for an X win OR O win in second paramater is either of those symbols
int winCheck(char board[][3], char lookFor)
{
    int i;
    int k;

    //if just need to know if theres a winner
    if(lookFor == '0')
    {
        int winStatus = checkAll(board, 'O');
        int winStatus2 = checkAll(board, 'X');

        if(winStatus == 1 || winStatus2 == 1)
        {
            return 1;

        }

        else
        {
            return 0;

        }
    }
    
    else if(lookFor == 'X')
    {
        int winStatus = checkAll(board, 'X');

        return winStatus;
    }

    else if(lookFor == 'O')
    {
        int winStatus = checkAll(board, 'O');

        return winStatus;
    }
}
//end win check

//is used with winCheck 
int checkAll(char board[][3], char checkfor)
{
    int k = 0;
    int i = 0;
    int gameWon = 1;

    //this checks for verticle matches
    for(i = 0; i < 3; i++)
    {
        
        for(k = 0; k < 3; k++)
        {
            if( board[i][k] != checkfor)
            {
                break;

            }
            if(k == 2)
            {
                return gameWon;

            }
        }

    }

    //then check for horizontal matches
    for(i = 0; i < 3; i++)
    {
        k = 0;
        
        for(k = 0; k < 3; k++)
        {
            if(board[k][i] != checkfor)
            {
                break;

            }
            if(k == 2)
            {
                return gameWon;

            }
        }

    }


    //then check for diagnols
    k = 0;
    i = 0;

    for(i = 0; i < 3; i++) 
    {
        if(board[i][k] != checkfor)
        {
            break;

        }
        if (k == 2)
        {
            return gameWon;
          
        }

        k++;
    }


    k = 2;
    for(i = 0; i < 3; i++) 
    {
        if(board[i][k] != checkfor)
        {
            break;

        }
        if (k == 0)
        {
            return gameWon;
          
        }
        k = k - 1;
    }

}

//checks if the game is full
int isFull(char board[][3])
{
    int i = 0;
    int k = 0;

    for(i = 0; i < 3; i++)
    {
        for(k = 0; k < 3; k++)
        {
            if(board[i][k] == '0')
            {
                //not full therefore return 0
                return 0;

            }//endif
        }//end inner for

    }//end for
    
    //game is full therefore return 1
    printf("isFull=1");
    return 1;

}//end if full


//count amount of spaces left
int spacesLeft(char board[][3])
{
    int counter = 0;
    int i;
    int k;

    for(i = 0; i < 3; i++)
    {
        for(k = 0; k < 3;k++)
        {
            if(board[i][k] == '0')
            {
                counter++;

            }

        }

    }

    return counter;

}//end spacesLeft

//checks if we can win in our current move (1 if true)
int winOnTurn(char board[][3], char sym, int *x, int *y)
{
    int i;
    int k;
    int counter;
    int isEmpty; //this would +1 every empty space

    int winX; //these are our potential winning cords
    int winY;

    //this checks for horizontal 2 with same symbol and an empty space
    for(i = 0; i < 3; i++)
    {
        counter = 0;
        isEmpty = 0;

        for(k = 0; k < 3; k++)
        {
            if(board[i][k] == sym)
            {
                counter++;

            }
            else if(board[i][k] == '0')
            {
                isEmpty++;
                winX = i;
                winY = k;

            }

            if(isEmpty == 1 && counter == 2)
            {
                *x = winX;
                *y = winY; 
                return 1;

            }
        }

    }

    //then check for verticle matches
    for(i = 0; i < 3; i++)
    {
        counter = 0;
        isEmpty = 0;

        for(k = 0; k < 3; k++)
        {
            if(board[k][i] == sym)
            {
                counter++;

            }
            else if(board[k][i] == '0')
            {
                isEmpty++;
                winX = k;
                winY = i;
            }

            if(isEmpty == 1 && counter == 2)
            {
                *x = winX;
                *y = winY; 
                return 1;

            }
        }

    }


    counter = 0;
    isEmpty = 0;
    k = 0;
    for(i = 0; i < 3;i++)
    {
        if(board[i][k] == sym)
        {
            counter++;

        }
        else if(board[i][k] == '0')
        {
            isEmpty++;
            winX = i;
            winY = k;

        }

        if(isEmpty == 1 && counter == 2) 
        {
            *x = winX;
            *y = winY; 
            return 1;

        }

        k++;
    }
 
    
    counter = 0;
    isEmpty = 0;
    k = 2;
    for(i = 0; i < 3; i++)
    {
        if(board[i][k] == sym)
        {
            counter++;

        }
        else if(board[i][k] == '0')
        {
            isEmpty++;
            winX = i;
            winY = k;

        }

        if(isEmpty == 1 && counter == 2) 
        {
            *x = winX;
            *y = winY; 
            return 1;

        }

        k--;
    }

    //no sign of winning on the current turn therefore return 0
    return 0;

}

int value(char board[][3], char max)
{
    int i;
    int k;

    for(i = 0; i < 3; i++)
    {
        for(k = 0; k < 3; k++)
        {


        }
    }
}

char whoTurn(char board[][3], char startingChar)
{
    int startCount = 0;
    int secondCount = 0;
    int i;
    int k;

    char secondChar = ' ';

    if(startingChar == 'X')
    {
        secondChar = 'O';

    }

    else
    {
        secondChar = 'X';

    }

    //this counts how many times a char has been repeated
    for(i = 0; i < 3; i++)
    {
        for(k = 0; k < 3; k++)
        {
            if(board[i][k] == startingChar)
            {
                startCount++;
            }

            else if(board[i][k] == secondChar)
            {
                secondCount++;
            }

        }
    }

    //then simply if the the counts are matching it would be the starting players turn
    //else it would be second players turn
    if(startCount == secondCount)
    {
        return startingChar;
    }

    else
    {
        return secondChar;
    }
}

int max(int var1, int var2)
{
    if(var1 < var2)
    {
        return var2;
    }
    else
    {
        return var1;
    }

}

int min(int var1, int var2)
{
    if(var1 < var2)
    {
        return var1;
    }
    else
    {
        return var2;
    }

}