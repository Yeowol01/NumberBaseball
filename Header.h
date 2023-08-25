#pragma once
#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>

using std::vector;
using std::string;

enum class SHOP
{
	SHOP_TOWN,
	SHOP_BUY,
	SHOP_SELL
};

enum class ITEM
{
	ITEM_EMPTY,
	ITEM_POTION
};