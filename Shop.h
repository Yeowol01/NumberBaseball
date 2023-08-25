#pragma once
#include"Header.h"
#include"Item.h"

class Shop
{
private:
	vector<Item> m_vItem; // 상점에 진열된 아이템 저장
	vector<Item>::iterator m_viItem; // 위 vector 반복
	int m_itemCount; // 진열된 아이템 갯수 저장
	int m_shopSelectNum; // 상점 클래스 함수 내 선택을 저장할 변수
public:
	Shop();

	void ShowShopItem();
	void ShopBuyItemPage();
	
	void BuyItem();
};  