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
		cout << "1. ���� 2. ������ 3. ���� 4. �ҷ����� 5. ���� : ";
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			m_pPlayer = new CPlayer("����", 100, 10);
			m_pPlayer->Initialize();
			break;
		case 2:
			m_pPlayer = new CPlayer("������", 50, 20);
			m_pPlayer->Initialize();
			break;
		case 3:
			m_pPlayer = new CPlayer("����", 75, 15);
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
	cout << "1. ���� 2. ���� 3. �κ��丮 4. ���� : ";
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
		cout << "�߸��� �Է��Դϴ�.";
		system("pause");
		break;
	}
}

void CMainGame::Adventure()
{
	int iInput(0);
	SAFE_DELETE(m_pMonster);
	Game = FIGHT;
	cout << "1. �ʱ� 2. �߱� 3. ��� 4. ������ : ";
	cin >> iInput;
	switch (iInput)
	{
	case 1:
		m_pMonster = new CMonster("�ʱ�", 30, 3);
		break;
	case 2:
		m_pMonster = new CMonster("�߱�", 60, 6);
		break;
	case 3:
		m_pMonster = new CMonster("���", 90, 9);
		break;
	case 4:
		Game = HOME;
		break;
	default:
		Game = ADVENTURE;
		cout << "�߸��� �Է��Դϴ�.";
		system("pause");
		break;
	}
}

void CMainGame::Shop()
{
	int iInput(0);
	SAFE_DELETE(shop);
	shop = new CShop();
	cout << "1. �ʱ޻��� 2. �߱޻��� 3. ��޻��� 4. ������ : ";
	cin >> iInput;
	shop->Initialize(m_pPlayer);
	switch (iInput)
	{
	case 1:
		shop->AddItem("�ʱ޹���", 5, WEAPONE);
		shop->AddItem("�ʱް���", 3, ARMOR);
		shop->AddItem("�ʱ�����", 10, POTION);
		shop->Update();
		break;
	case 2:
		shop->AddItem("�߱޹���", 10, WEAPONE);
		shop->AddItem("�߰���", 6, ARMOR);
		shop->AddItem("�߱�����", 20, POTION);
		shop->Update();
		break;
	case 3:
		shop->AddItem("��޹���", 15, WEAPONE);
		shop->AddItem("��ް���", 9, ARMOR);
		shop->AddItem("�������", 30, POTION);
		shop->Update();
		break;
	case 4:
		Game = HOME;
		break;
	default:
		cout << "�߸��� �Է��Դϴ�.";
		system("pause");
		break;
	}
}

void CMainGame::Fight()
{
	m_pMonster->Print();
	int iInput(0);
	cout << "1. ���� 2. �������� : ";
	cin >> iInput;
	switch (iInput)
	{
	case 1:
		if (m_pPlayer->Damage(m_pMonster->GetObj())) {
			cout << "����Ͽ����ϴ�." << endl;
			system("pause");
		}
		else if (m_pMonster->Damage(m_pPlayer->GetObj())) {
			cout << "�¸��ϼ̽��ϴ�." << endl;
			system("pause");
		}
		else {
			break;
		}
	case 2:
		Game = ADVENTURE;
		break;
	default:
		cout << "�߸��� �Է��Դϴ�.";
		system("pause");
		break;
	}
}
