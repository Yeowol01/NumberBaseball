#pragma once
#include <iostream>
#include <map>
#include <Windows.h>
#include <vector>

using namespace std;

struct items
{
	map<char*, int> itemMap;
	map<char*, int>::iterator mItemMap;
	int myGold;
	int itemCount;
};