#include "pch.h"
#include "CInventory.h"

void CInventory::Initialize(CPlayer* player)
{
	m_pCopyPlayer = player;
}

void CInventory::Update()
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
		else if (iInput <= vecItem.size() && 0 < iInput) {
			vector<ITEM>::iterator iter = vecItem.begin();
			iter += iInput - 1;
			system("cls");
			m_pCopyPlayer->Print();
			cout << "1. 사용 2. 판매 : ";
			cin >> iInput;
			switch (iInput)
			{
			case 1:
				switch (iter->type)
				{
				case WEAPONE:
					m_pCopyPlayer->SetWeapone(iter);
					break;
				case ARMOR:
					m_pCopyPlayer->SetArmor(iter);
					break;
				case POTION:
					m_pCopyPlayer->Heal(iter->iStat);
					vecItem.erase(iter);
					break;
				}
				break;
			case 2:
				vecItem.erase(iter);
				break;
			default:
				break;
			}
		}
	}
}

void CInventory::Release()
{
}

void CInventory::Print()
{
	int iCount(1);
	for (vector<ITEM>::iterator iter = vecItem.begin(); iter != vecItem.end(); ++iter) {
		cout << iCount++ << ". " << iter->szName << " ";
	}
	cout << iCount << ". 나가기 : ";
}

vector<ITEM>& CInventory::GetInventory()
{
	return vecItem;
}
