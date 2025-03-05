#pragma once
#include "CPlayer.h"
#include<vector>

class CShop
{
public:
	CShop();
	~CShop();
	void Initialize(CPlayer* player);
	void Update();
	void Release();
	void AddItem(string sItem, int istat, ITEM_TYPE type);
	void Print();
	ITEM GetItem(int iInput);
	bool Buy();
private:
	vector<ITEM> vecItem;
	CPlayer* m_pCopyPlayer;
};