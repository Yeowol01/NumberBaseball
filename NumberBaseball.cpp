#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

#define FG FOREGROUND_GREEN

void SetColorOne(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

int main()
{
	SetColorOne(FG);

	int Computer[3] = { 0, };
	int User[3] = { 0, };
	int NumberTable[10] = { 0,1,2,3,4,5,6,7,8,9 };
	int UserInputTable[20][3] = { 0, };
	int UserInputCount = 0;

	const char* StrikeString[3] = { " ", "원 스트라이크", "투 스트라이크" };
	const char* BallString[4] = { " ", "원 볼", "투 볼", "쓰리 볼" };

	printf("숫자야구를 시작합니다\n");
	printf("....Press Any Key....");
	_getch();

	srand(time(NULL));
	system("cls");

	int Count = 3;

	while (Count > 0)
	{
		int Random = rand() % 10;

		if (NumberTable[Random] == -1) continue;

		Computer[3 - Count] = NumberTable[Random];
		NumberTable[Random] = -1;

		Count--;
	}

	while (1)
	{
		int Strike = 0;
		int Ball = 0;
		int i, j;

		system("cls");

		for (i = 0; i < UserInputCount; i++)
		{
			printf("%d %d %d\n", UserInputTable[i][0], UserInputTable[i][1], UserInputTable[i][2]);
		}

		printf("0 ~ 9 까지 숫자를 3개 입력해 주세요 ex) 1 2 3\n");
		printf("종료는 -1을 눌러주세요.\n");
		printf("기회는 20번. 남은기회 : %d번\n", 20 - UserInputCount);
		printf("입력 : ");

		for (i = 0; i < 3; i++)
		{
			scanf_s("%d", &User[i]);
			if (User[i] == -1)
			break;
		}

		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (Computer[i] == User[j])
				{
					if (i == j)
						Strike++;
					else
						Ball++;
				}
			}
		}

		if (Strike == 3)
		{
			printf("아웃! 게임을 종료합니다.\n");
			break;
		}
		else
		{
			printf("%s %s\n", StrikeString[Strike], BallString[Ball]);
		}

		UserInputTable[UserInputCount][0] = User[0];
		UserInputTable[UserInputCount][1] = User[1];
		UserInputTable[UserInputCount][2] = User[2];

		UserInputCount++;

		if (UserInputCount >= 20)
		{
			printf("모든 기회를 소진하셨습니다.\n");
			printf("정답 : %d %d %d\n", Computer[0], Computer[1], Computer[2]);
			break;
		}

		printf("....Press Any Key....");
		_getch();
	}

	return 0;
}