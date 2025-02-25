#pragma once
#include"CShopItem.h"
class CShop
{
public:
	CShop();
	~CShop();
	void		Initialize();
	void		Update();
	void		Release();
private:
	CShopItem* m_pShopItem;
};

