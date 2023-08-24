#pragma once
#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>

using std::vector;
using std::string;

enum class LOCATION
{
	LOCATION_TOWN,
	LOCATION_SHOP,
	LOCATION_INVENTORY
};

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

enum class INVENTORY
{
	INVENTORY_TOWN,
	INVENTORY_SHOWBAG
};