#include<stdio.h>

#include "game.h"
#include "../ai/ai.h"
#include "../utils/utils.h"

//main game logic is run through here
void startGame(char board[][3], char start)
{
    //if x we are first
    if(start == 'X')
    {
        printBoard(board);
        while(isFull(board) == 0 && winCheck(board, '0') == 0)
        {
            printf("\nYour turn! Chose cordinates (X O): ");
            makeAmove(board, start);
            printBoard(board);

            if(winCheck(board,'0') == 1)
            {
                printf("game is won");
                break;

            }

            printf("\nThe robots turn\n");
            botMove(board, start);
            printBoard(board);
            

        }

    }
    //else robot would start as X and us second as O
    else
    {
        while(isFull(board) == 0 && winCheck(board, '0') == 0)
        {
            printf("\nThe robots turn\n");
            botMove(board, start);
            printBoard(board);

            if(winCheck(board, 0) == 1)
            {   
                printf("game is won");
                break;

            }

            printf("\nYour turn! Chose cordinates (X O): ");
            makeAmove(board, start);
            printBoard(board);

        }

    }

}//end, game func

//player makes a move and checks if its valid
void makeAmove(char board[][3], char userSym)
{
    int xcord;
    int ycord;

    
    int valid = 1;
    do 
    {
        scanf("%d %d", &xcord, &ycord);
        if(board[xcord][ycord] == '0')
        {
            valid = 1;
            board[xcord][ycord] = userSym;

        }
        else
        {
            printf("\nInvalid Option, Choose again (X/Y): ");
            valid = 0;

        }
    }
    while(valid == 0);
}//end user moves

//bot moves
void botMove(char board[][3], char userSym)
{
    int xcord;
    int ycord;
    char botSym;

    if(userSym == 'O')
    {
        botSym = 'X';
    }
    else 
    {
        botSym = 'O';
    }


    if(winOnTurn(board, botSym, &xcord, &ycord) == 1)
    {
        printf("\nwinOnTurn called, our cords are %d %d", xcord, ycord);
        board[xcord][ycord] = botSym;
        return;
    }
    else
    {
        evaluate(board, botSym, &xcord, &ycord);
        board[xcord][ycord] = botSym;

    }


    return;
}


//prints the current board
void printBoard(char board[][3])
{
    int i = 0;
    int k = 0;
    
    printf("\n\n\n\n");
    
    printf("%c | %c | %c\n"
            "---------\n"
            "%c | %c | %c\n"
            "---------\n"
            "%c | %c | %c\n",    board[0][0], board[0][1], board[0][2],
                                board[1][0], board[1][1], board[1][2],
                                board[2][0], board[2][1], board[2][2] );

}
//end board print 