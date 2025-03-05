#pragma once
#include "CPlayer.h"

class CInventory
{
public:
	void Initialize(CPlayer* player);
	void Update();
	void Release();
	void Print();
	vector<ITEM>& GetInventory();
private:
	vector<ITEM> vecItem;
	CPlayer* m_pCopyPlayer;
};

