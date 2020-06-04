#ifndef BOWLING_H
#define BOWLING_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char board[][48] = {
    "+===+===+===+===+===+===+===+===+===+=====+",
    "| 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 1 0 |",
    "+---+---+---+---+---+---+---+---+---+-----+",
    "| | | | | | | | | | | | | | | | | | | | | |",
    "+---+---+---+---+---+---+---+---+---+-----+",
    "|   |   |   |   |   |   |   |   |   |     |",
    "+===+===+===+===+===+===+===+===+===+=====+"
};

void print_board()
{
    system("clear");
    for(int i = 0 ; i < 7 ; i++)
        printf("%s\n", board[i]);
}

void inputScore(int frameNumber, int castNumber, int *score)
{
    const char* castcase[4] = {"----", "1st", "2nd", "3rd"};
    while(1)
    {
        printf("frame %d's %s cast : ", frameNumber, castcase[castNumber]);
        scanf("%d", score);

        if(*score >=0 && *score <= 10)
            break;
        else
            printf("You have entered an invalid value. Please re-enter.\n");
    }
}

void setScore(int frameNumber, int castNumber, int score)
{
    char ch;
    if(score == 10)
    {
        if(frameNumber == 10 || castNumber == 1)
            ch = 'x';
    }
    else if(castNumber == 2 && score + (board[3][4*(frameNumber-1)+1] - '0') == 10)
        ch = '/';
    else
        ch = score + '0';
    board[3][4*(frameNumber-1) + 2*castNumber - 1] = ch;
}

void setFrameScore(int frameNumber, int frameScore)
{
    // char buf[4];
    // int offset;

    // sprintf(buf, "%3d", frameScore);
    // if(frameNumber == 10)
    //     offset = 1;
    // else
    //     offset = 0;

    // strncpy(&board[5][4*(frameNumber-1) + 1 + offset], buf, 3);

    char buf[4];
	sprintf(buf, "%3d", frameScore);
	int offset = (frameNumber == 10) ? 1 : 0;
	strncpy(&board[5][4*(frameNumber-1) + 1 + offset], buf, 3);
}

#endif