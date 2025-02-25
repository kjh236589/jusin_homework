#include "pch.h"
#include "CShop.h"
#include "CShopItem.h"

CShop::CShop()
{
	m_pShopItem = nullptr;
}

CShop::~CShop()
{
}

void CShop::Initialize()
{
	m_pShopItem = new CShopItem;
}

void CShop::Update()
{
	int iInput(0);
	while (true) {
		system("cls");
		cout << "1. 초급 상점 2. 중급 상점 3. 고급 상점 4. 나가기";
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			m_pShopItem->AddItem("초급무기", 100);
			m_pShopItem->AddItem("초급방어구", 100);
			m_pShopItem->Update();
			m_pShopItem->Release();
			break;
		case 2:
			m_pShopItem->AddItem("중급무기", 100);
			m_pShopItem->AddItem("중급방어구", 100);
			m_pShopItem->Update();
			m_pShopItem->Release();
			break;
		case 3:
			m_pShopItem->AddItem("고급무기", 100);
			m_pShopItem->AddItem("고급방어구", 100);
			m_pShopItem->Update();
			m_pShopItem->Release();
			break;
		case 4:
			return;
		default:
			break;
		}
	}
}

void CShop::Release()
{
	delete m_pShopItem;
	m_pShopItem = nullptr;
}
