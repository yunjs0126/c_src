#include "bowling.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int frame[10][3] = {0, };
    int frame10[4] = {0, };
    int frameScore[11] = {0, };
    int i;
    //1~9프레임
    for(i = 1 ; i <= 9 ; ++i)
    {
        //보드 출력
        print_board();
        printf("\n");
        //값 입력받음
        inputScore(i, 1, &frame[i][1]);
        setScore(i, 1, frame[i][1]);
        //이전 프레임이 스페어인가?
        if(i > 1 && frame[i-1][1]+frame[i-1][2] == 10 && frame[i][1] != 10)
        {
            frameScore[i-1] = frameScore[i-2] + 10 + frame[i][1];
            setFrameScore(i-1, frameScore[i-1]);
        }
        //전전 프레임이 스트라이크이고 전프레임도 스트라이크인가?
        if(i > 2 && frame[i-2][1] == 10 && frame[i-1][1] == 10)
        {
            frameScore[i-2] = frameScore[i-3] + 20 + frame[i][1];
            setFrameScore(i-2, frameScore[i-2]);
        }

        //두번째 투구
        if(frame[i][1] != 10)
        {
            print_board();
            printf("\n");
            while(1)
            {
                inputScore(i, 2, &frame[i][2]);
                int sum = frame[i][1] + frame[i][2];
                if(sum >= 0 && sum <= 10)
                    break;
            }
            
            setScore(i, 2, frame[i][2]);

            // 전 프레임이 스트라이크인가?
            if(i > 1 && frame[i-1][1] == 10)
            {
                frameScore[i-1] = frameScore[i-2] + 10 + frame[i][1] + frame[1][2];
                setFrameScore(i-1, frameScore[i-1]);
            }
            // 지금 프레임이 스페어가 아닌가?
            if(frame[i][1] + frame[i][2] < 10)
            {
                frameScore[i] = frameScore[i-1] + frame[i][1] + frame[i][2];
                setFrameScore(i, frameScore[i]);
            }
        }
    }

    //10프레임
    print_board();
    printf("\n");

    inputScore(10, 1, &frame10[1]);
    setScore(10, 1, frame10[1]);

    //이전 프레임이 스페어인가?
    if(frame[i-1][1]+frame[i-1][2] == 10 && frame10[1] != 10)
    {
        frameScore[i-1] = frameScore[i-2] + 10 + frame10[1];
        setFrameScore(i-1, frameScore[i-1]);
    }
    //전전 프레임이 스트라이크이고 전프레임도 스트라이크인가?
    else if(frame[i-2][1] == 10 && frame[i-1][1] == 10)
    {
        frameScore[i-2] = frameScore[i-3] + 20 + frame10[1];
        setFrameScore(i-2, frameScore[i-2]);
    }

    //두번째 투구
	print_board();
	printf("\n");
	
	if(frame10[1] == 10)
		inputScore(10, 2, &frame10[2]);
	else
		while(1)
		{
			inputScore(10, 2, &frame10[2]);
			int tmp = frame10[1] + frame10[2];
			if(tmp >=0 && tmp <= 10)
				break;
		}
	setScore(10, 2, frame10[2]);
	
	if(i > 1 && frame[i-1][1] == 10) {
		frameScore[i-1] = frameScore[i-2] + 10 + frame10[1] + frame10[2];
		setFrameScore(i-1, frameScore[i-1]);
		// printf("frame : %d score : %d\n", i-1, frameScore[i-1]);
	}
	
	// first + second >= 10 third cast
	if(frame10[1] + frame10[2] >= 10) {
		print_board();
		printf("\n");
		// printf("frame : 10 3rd cast : ");
		// scanf("%d", &frame10[3]);
		
		if(frame10[2] == 10)
			inputScore(10, 3, &frame10[3]);
		else
			while(1)
			{
				inputScore(10, 3, &frame10[3]);
				int tmp = frame10[2] + frame10[3];
				if(tmp >=0 && tmp <= 10)
					break;
			}
		
		setScore(10, 3, frame10[3]);
	}
	frameScore[10] = frameScore[i-1] + frame10[1] + frame10[2] + frame10[3];
	setFrameScore(10, frameScore[10]);
	// printf("frame: 10 score : %d\n", frameScore[10]);
	
	print_board();

    return 0;
}