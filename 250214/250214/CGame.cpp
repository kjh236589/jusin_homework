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
			cout << "1. 사냥터 2. 종료 : ";
			cin >> iInput;
			switch (iInput)
			{
			case 1:
				Game();
				break;
			case 2:
				return;
			default:
				cout << "잘못된 입력입니다." << endl;
				system("pause");
				break;
			}
		}
	}
}

void CGame::Release()
{
	cout << "게임 종료" << endl;
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
		cout << "1. 공격 2. 도망 : ";
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			if (pPlayer->Damage(pMonster->GetDamage())) {
				cout << "플레이어 사망" << endl;
				pPlayer->Reset();
				system("pause");
			}
			else if (pMonster->Damage(pPlayer->GetDamage())) {
				cout << "승리" << endl;
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
			cout << "잘못된 입력입니다." << endl;
			system("pause");
			break;
		}
	}
}
