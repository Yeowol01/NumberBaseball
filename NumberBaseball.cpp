#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <iostream>
#include <map>
#include <vector>

#define FG FOREGROUND_GREEN

using namespace std;

struct items
{
	map<const char*, int> itemMap;
	map<const char*, int>::iterator mItemMap;
	int myGold;
	int itemCount;
};

void SetColorOne(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void MainGame()
{
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

}

int main()
{
	SetColorOne(FG);

	items shop;
	items inventory;

	shop.itemMap.insert(pair<const char*, int>("힌트 돋보기", 1500));
	shop.itemMap.insert(pair<const char*, int>("힌트 돋보기2", 1500));
	shop.itemMap.insert(pair<const char*, int>("힌트 돋보기3", 1500));

	shop.myGold = 999999;
	inventory.myGold = 10000;

	int selectWay;
	int selectItem;
	int sellItem;

	while (true)
	{
		system("cls");

		cout << "어디로 이동하시겠습니까?" << endl;
		cout << "1.게임시작 2.상점 3.인벤토리 4.게임종료" << endl;

		cin >> selectWay;
		if (cin.fail() || selectWay > 4 || selectWay < 1)
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "잘못된 입력입니다. 다시 입력해주세요" << endl;
			cout << "1.게임시작 2.상점 3.인벤토리 4.게임종료" << endl;
			cin >> selectWay;
		}
		else if (selectWay == 4)
		{
			break;
		}

		cout << endl << endl;
		if (selectWay == 1)
		{
			cout << "게임을 시작합니다." << endl;
		}
		else if (selectWay == 2)
		{
			cout << "상점으로 이동합니다." << endl;
		}
		else if (selectWay == 3)
		{
			cout << "인벤토리로 이동합니다." << endl;
		}
		else if(selectWay == 4)
		{
			cout << "게임을 종료합니다." << endl;
		}

		Sleep(1000);

		system("cls");



		int i = 1;
		switch (selectWay)
		{
		case 1:
			MainGame();
			break;

		case 2:
			for (shop.mItemMap = shop.itemMap.begin(); shop.mItemMap != shop.itemMap.end(); ++shop.mItemMap)
			{
				cout << i << ". " << shop.mItemMap->first << " : " << shop.mItemMap->second << endl;
				i++;
			}
			cout << "현재 소지금 : " << inventory.myGold << endl;
			cout << "구입하실 아이템을 선택해주세요." << endl;
			cin >> selectItem;

			while (true)
			{
				if (cin.fail() || selectItem > shop.itemMap.size())
				{
					cin.clear();
					cin.ignore(INT_MAX, '\n');
					cout << "아이템을 다시 선택해주세요." << endl;
					cin >> selectItem;
					continue;
				}
				else break;
			}

			switch (selectItem)
			{
			case 1:
				shop.mItemMap = shop.itemMap.find("힌트 돋보기");
				if (inventory.myGold >= shop.mItemMap->second)
				{
					cout << shop.mItemMap->first << " 이/가 구매 되었습니다." << endl;
					inventory.itemMap.insert(pair<const char*, int>("힌트 돋보기", 1500));
					inventory.myGold -= shop.mItemMap->second;
				}
				else cout << "소지금이 부족합니다." << endl;
				break;
			case 2:
				shop.mItemMap = shop.itemMap.find("힌트 돋보기2");
				if (inventory.myGold >= shop.mItemMap->second)
				{
					cout << shop.mItemMap->first << " 이/가 구매 되었습니다." << endl;
					inventory.itemMap.insert(pair<const char*, int>("힌트 돋보기2", 1500));
					inventory.myGold -= shop.mItemMap->second;
				}
				else cout << "소지금이 부족합니다." << endl;
				break;
			case 3:
				shop.mItemMap = shop.itemMap.find("힌트 돋보기3");
				if (inventory.myGold >= shop.mItemMap->second)
				{
					cout << shop.mItemMap->first << " 이/가 구매 되었습니다." << endl;
					inventory.itemMap.insert(pair<const char*, int>("힌트 돋보기3", 1500));
					inventory.myGold -= shop.mItemMap->second;
				}
				else cout << "소지금이 부족합니다." << endl;
				break;
			default:
				break;
			}

			// shop.mItemMap = shop.itemMap.find(selectItem);
			// if (shop.mItemMap != shop.itemMap.end())
			// {
			//      cout << shop.mItemMap->first << " 를 선택하셨습니다." << endl;
			//	
			//	    if (shop.mItemMap->second > inventory.myGold)
			//      {
			//	    	cout << "소지금이 모자랍니다." << endl;
			//	    }
			//	    else
			//      {
			//	    	cout << "구매가 완료되었습니다." << endl;
			//	    }
			// }

			break;

		case 3:
			for (inventory.mItemMap = inventory.itemMap.begin(); inventory.mItemMap != inventory.itemMap.end(); ++inventory.mItemMap)
			{
				cout << i << ". " << inventory.mItemMap->first << ", " << inventory.mItemMap->second << endl;
				i++;
			}

			cout << endl;
			cout << "현재 소지금 : " << inventory.myGold << endl;

			cout << "파실 아이템이 있으시면 골라주세요. (없으면 0을 입력)" << endl;
			cin >> sellItem;

			if (sellItem == 0)
			{
				cout << "인벤토리를 빠져 나갑니다." << endl;
			}
			else
			{
				cout << "아직 미구현 입니다..." << endl;
			}

			break;
		default:
			break;
		}

		i = 1;

		cout << endl;
		cout << endl;

		Sleep(1000);
	}

	return 0;
}