#include "pch.h"
#include "CGame.h"
#include "CObject.h"

CGame::CGame()
{
	pPlayer = nullptr;
	pMonster = nullptr;
}

CGame::~CGame()
{
	Release();
}

void CGame::Initialize()
{
	pPlayer = new CObject();
	pMonster = new CObject();
}

void CGame::Update()
{
	pPlayer->Initialize();
	if (pPlayer->CreatePlayer()) {
		int iInput(0);
		while (true) {
			system("cls");
			pPlayer->Print();
			cout << "1. ����� 2. ���� : ";
			cin >> iInput;
			switch (iInput)
			{
			case 1:
				Game();
				break;
			case 2:
				return;
			default:
				cout << "�߸��� �Է��Դϴ�." << endl;
				system("pause");
				break;
			}
		}
	}
}

void CGame::Release()
{
	cout << "���� ����" << endl;
	pPlayer->Save();
	SAFE_DELETE(pPlayer);
	SAFE_DELETE(pMonster);
}

void CGame::Game()
{
	while (true) {
		pMonster->Initialize();
		if (pMonster->CreateMonster()) {
			Fight();
		}
		else {
			pMonster->Release();
			return;
		}
	}
}

void CGame::Fight()
{
	int iInput(0);
	while (true) {
		system("cls");
		pPlayer->Print();
		pMonster->Print();
		cout << "1. ���� 2. ���� : ";
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			if (pPlayer->Damage(pMonster->GetDamage())) {
				cout << "�÷��̾� ���" << endl;
				pPlayer->Reset();
				system("pause");
			}
			else if (pMonster->Damage(pPlayer->GetDamage())) {
				cout << "�¸�" << endl;
				system("pause");
			}
			else {
				break;
			}
		case 2:
			system("cls");
			pPlayer->Print();
			return;
		default:
			cout << "�߸��� �Է��Դϴ�." << endl;
			system("pause");
			break;
		}
	}
}
