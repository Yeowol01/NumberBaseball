#pragma once
#include"Header.h"
#include"Item.h"

class Shop
{
private:
	vector<Item> m_vItem; // ������ ������ ������ ����
	vector<Item>::iterator m_viItem; // �� vector �ݺ�
	int m_itemCount; // ������ ������ ���� ����
	int m_shopSelectNum; // ���� Ŭ���� �Լ� �� ������ ������ ����
public:
	Shop();

	void ShowShopItem();
	void ShopBuyItemPage();
	
	void BuyItem();
};  