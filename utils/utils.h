#ifndef UTILS_H
#define UTILS_H

void printBoard(char[][3]); //print the current score/board
void bestMove(char[][3], char); //yea idk

int winCheck(char[][3], char); //returns 1 if someone has won
int checkAll(char[][3], char);

int isFull(char[][3]); //returns 0 or 1, 1 if full

int spacesLeft(char[][3]); //returns how many 0s there are 
int winOnTurn(char[][3], char, int*, int*); //if we can win on the current turn we change the x and y cords


char whoTurn(char[][3], char); //finds whos turn it is by simply counting the X's and the O's (requires to know who started)

int max(int, int);
int min(int, int);

#endif