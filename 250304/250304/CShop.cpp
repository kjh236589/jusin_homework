#include "pch.h"
#include "CShop.h"

CShop::CShop()
{
	vecItem.reserve(3);
	m_pCopyPlayer = nullptr;
}

CShop::~CShop()
{
}

void CShop::Initialize(CPlayer* player)
{
	m_pCopyPlayer = player;
}

void CShop::Update()
{
	int iInput(0);
	while (true) {
		system("cls");
		m_pCopyPlayer->Print();
		Print();
		cin >> iInput;
		if (iInput == vecItem.size() + 1) {
			return;
		}
		else if (iInput <= vecItem.size() && 0 < iInput && Buy()) {
			if (5 <= m_pCopyPlayer->GetInventory().size()) {
				cout << "�κ��丮�� ����á���ϴ�." << endl;
				system("pause");
			}
			else {
				m_pCopyPlayer->GetInventory().push_back(vecItem[iInput - 1]);
			}
		}
	}
}

void CShop::Release()
{
}

void CShop::AddItem(string sItem, int istat, ITEM_TYPE type)
{
	ITEM item = {sItem, istat, type};
	vecItem.push_back(item);
}

void CShop::Print()
{
	int iCount(1);
	for (vector<ITEM>::iterator iter = vecItem.begin(); iter != vecItem.end(); ++iter) {
		cout << iCount++ << ". " << iter->szName << " ";
	}
	cout << iCount << ". ������ : ";
}

ITEM CShop::GetItem(int iInput)
{
	return vecItem[iInput];
}

bool CShop::Buy()
{
	int iInput(0);
	while (true) {
		system("cls");
		m_pCopyPlayer->Print();
		cout << "���� �����Ͻðڽ��ϱ�?" << endl << "1. �� 2. �ƴϿ� : ";
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			return true;
		case 2:
			return false;
		default:
			cout << "�߸��� �Է��Դϴ�." << endl;
			system("pause");
			continue;
		}
	}
	return false;
}
