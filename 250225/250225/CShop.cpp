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
		cout << "1. �ʱ� ���� 2. �߱� ���� 3. ��� ���� 4. ������";
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			m_pShopItem->AddItem("�ʱ޹���", 100);
			m_pShopItem->AddItem("�ʱ޹�", 100);
			m_pShopItem->Update();
			m_pShopItem->Release();
			break;
		case 2:
			m_pShopItem->AddItem("�߱޹���", 100);
			m_pShopItem->AddItem("�߱޹�", 100);
			m_pShopItem->Update();
			m_pShopItem->Release();
			break;
		case 3:
			m_pShopItem->AddItem("��޹���", 100);
			m_pShopItem->AddItem("��޹�", 100);
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
