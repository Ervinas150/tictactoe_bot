#include<stdio.h>

#include "../game/game.h"
#include "../ai/ai.h"
#include "../utils/utils.h"


int main()
{
    char board[3][3] = {'0', '0', '0',
                        '0', '0', '0', 
                        '0', '0', '0' };
    
    char start = ' ';

    printf("Welcome to a classic game of tic-tac-toe!\n");
    printf("Do you want to be X or O? :");
    
    scanf("%c", &start);
    while(getchar() != '\n');

    startGame(board, start);
    

    return 0;
}//end main

