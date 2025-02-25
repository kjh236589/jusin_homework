#include "pch.h"
#include "CShopItem.h"
#include "Define.h"

CShopItem::CShopItem()
{
	m_pItems = nullptr;
	iSize = 0;
}

CShopItem::~CShopItem()
{
}

void CShopItem::Initialize()
{
}

void CShopItem::Update()
{
	int iInput(0);
	while (true) {
		system("cls");
		for (int i = 0; i < iSize; ++i) {
			cout << i + 1 << ". " << m_pItems[i].szName << " ";
		}
		cout << iSize + 1 << ". 나가기" << endl << "구입할 아이템을 입력해주세요 : ";
		cin >> iInput;
		if (iInput == iSize + 1) {
			return;
		}
	}
}

void CShopItem::Release()
{
	if (1 < iSize) {
		SAFE_DELETE_ARRAY(m_pItems);
	}
	else {
		SAFE_DELETE(m_pItems);
	}
	iSize = 0;
}

void CShopItem::AddItem(const char* szName, int iPrice)
{
	ITEM item;
	strcpy_s(item.szName, sizeof(item.szName), szName);
	item.iPrice = iPrice;
	if (0 == iSize) {
		m_pItems = new ITEM[1];
		m_pItems[0] = item;
	}
	else {
		ITEM* pItems = new ITEM[iSize + 1];
		memcpy_s(pItems, sizeof(pItems) * iSize, m_pItems, sizeof(m_pItems) * iSize);
		// for (int i = 0; i < iSize; ++i) {
		// 	pItems[i] = m_pItems[i];
		// }
		delete m_pItems;
		m_pItems = pItems;
		m_pItems[iSize] = item;
	}
	++iSize;
}