#pragma once
#include"Header.h"

class Item
{
private:
	ITEM m_itemType;
	string m_name;
	int m_price;
	string m_description;
	int m_count;

public:
	Item(ITEM, string, int, string, int);

	ITEM GetType() { return m_itemType; }
	void SetType(const ITEM itemType) { m_itemType = itemType; }

	string GetName() { return m_name; }
	void SetType(const string name) { m_name = name; }

	int GetPrice() { return m_price; }
	void SetType(const int price) { m_price = price; }

	string GetDescription() { return m_description; }
	void SetDescription(const string description) { m_description = description; }

	int Count() { return m_count; }
	void SetCount(const int count) { m_count = count; }

	void ShowItemInfo();
};