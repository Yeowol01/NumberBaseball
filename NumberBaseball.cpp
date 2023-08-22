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

	return 0;
}