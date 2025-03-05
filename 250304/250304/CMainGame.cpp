#include "pch.h"
#include "CMainGame.h"

CMainGame::CMainGame()
{
	m_pPlayer = nullptr;
	m_pMonster = nullptr;
	Game = HOME;
}

CMainGame::~CMainGame()
{
}


void CMainGame::Initialize()
{
	int iInput(0);
	while (true) {
		system("cls");
		cout << "1. 전사 2. 마법사 3. 도적 4. 불러오기 5. 종료 : ";
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			m_pPlayer = new CPlayer("전사", 100, 10);
			m_pPlayer->Initialize();
			break;
		case 2:
			m_pPlayer = new CPlayer("마법사", 50, 20);
			m_pPlayer->Initialize();
			break;
		case 3:
			m_pPlayer = new CPlayer("도적", 75, 15);
			m_pPlayer->Initialize();
			break;
		case 4:
			break;
		case 5:
			Game = END;
			break;
		default:
			continue;
		}
		break;
	}
}

void CMainGame::Update()
{
	while (Game != END) {
		system("cls");
		m_pPlayer->Print();
		switch (Game) {
		case HOME:
			Start();
			break;
		case ADVENTURE:
			Adventure();
			break;
		case SHOP:
			Shop();
			break;
		case INVENTORY:
			m_pPlayer->OpenInventory();
			Game = HOME;
			break;
		case FIGHT:
			Fight();
			break;
		}
	}
}

void CMainGame::Release()
{
	SAFE_DELETE(m_pPlayer);
	SAFE_DELETE(m_pMonster);
}

void CMainGame::Start()
{
	int iInput(0);
	cout << "1. 모험 2. 상점 3. 인벤토리 4. 종료 : ";
	cin >> iInput;
	switch (iInput)
	{
	case 1:
		Game = ADVENTURE;
		break;
	case 2:
		Game = SHOP;
		break;
	case 3:
		Game = INVENTORY;
		break;
	case 4:
		Game = END;
		break;
	default:
		cout << "잘못된 입력입니다.";
		system("pause");
		break;
	}
}

void CMainGame::Adventure()
{
	int iInput(0);
	SAFE_DELETE(m_pMonster);
	Game = FIGHT;
	cout << "1. 초급 2. 중급 3. 고급 4. 나가기 : ";
	cin >> iInput;
	switch (iInput)
	{
	case 1:
		m_pMonster = new CMonster("초급", 30, 3);
		break;
	case 2:
		m_pMonster = new CMonster("중급", 60, 6);
		break;
	case 3:
		m_pMonster = new CMonster("고급", 90, 9);
		break;
	case 4:
		Game = HOME;
		break;
	default:
		Game = ADVENTURE;
		cout << "잘못된 입력입니다.";
		system("pause");
		break;
	}
}

void CMainGame::Shop()
{
	int iInput(0);
	SAFE_DELETE(shop);
	shop = new CShop();
	cout << "1. 초급상점 2. 중급상점 3. 고급상점 4. 나가기 : ";
	cin >> iInput;
	shop->Initialize(m_pPlayer);
	switch (iInput)
	{
	case 1:
		shop->AddItem("초급무기", 5, WEAPONE);
		shop->AddItem("초급갑옷", 3, ARMOR);
		shop->AddItem("초급포션", 10, POTION);
		shop->Update();
		break;
	case 2:
		shop->AddItem("중급무기", 10, WEAPONE);
		shop->AddItem("중갑옷", 6, ARMOR);
		shop->AddItem("중급포션", 20, POTION);
		shop->Update();
		break;
	case 3:
		shop->AddItem("고급무기", 15, WEAPONE);
		shop->AddItem("고급갑옷", 9, ARMOR);
		shop->AddItem("고급포션", 30, POTION);
		shop->Update();
		break;
	case 4:
		Game = HOME;
		break;
	default:
		cout << "잘못된 입력입니다.";
		system("pause");
		break;
	}
}

void CMainGame::Fight()
{
	m_pMonster->Print();
	int iInput(0);
	cout << "1. 공격 2. 도망가기 : ";
	cin >> iInput;
	switch (iInput)
	{
	case 1:
		if (m_pPlayer->Damage(m_pMonster->GetObj())) {
			cout << "사망하였습니다." << endl;
			system("pause");
		}
		else if (m_pMonster->Damage(m_pPlayer->GetObj())) {
			cout << "승리하셨습니다." << endl;
			system("pause");
		}
		else {
			break;
		}
	case 2:
		Game = ADVENTURE;
		break;
	default:
		cout << "잘못된 입력입니다.";
		system("pause");
		break;
	}
}
