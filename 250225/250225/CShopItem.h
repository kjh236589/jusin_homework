#pragma once
#include "Define.h"
class CShopItem
{
public:
	CShopItem();
	virtual ~CShopItem();

	void		Initialize();
	virtual void	 Update();
	void		Release();
	void AddItem(const char* szName, int iPrice);
private:
	ITEM* m_pItems;
	int iSize;
};

