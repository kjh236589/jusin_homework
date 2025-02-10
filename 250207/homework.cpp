#include<iostream>

using namespace std;

typedef struct INFO {
	char szName[32];
	int iHp;
	int iAtk;
}INFO;

INFO* InputJob();

void Main_Game(INFO* pPlayer);

void Print(INFO* pInfo);

void ChoiseMonster(INFO* pPlayer);

void CreateMonster(INFO** pMonster, int iInput);

void Fight(INFO* pPlayer, INFO* pMonster);

int main() {
	INFO* pPlayer = InputJob();
	if (nullptr == pPlayer) {
		return -1;
	}
	Main_Game(pPlayer);
	if (nullptr != pPlayer) {
		delete pPlayer;
		pPlayer = nullptr;
	}
	return 0;
}

INFO* InputJob() {
	int iInput(0);
	INFO* pPlayer = new INFO;
	while (0 >= iInput || 3 < iInput) {
		system("cls");
		cout << "������ �����ϼ��� : ������ �����ϼ���(1. ���� 2. ������ 3. ����) : ";
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			strcpy_s(pPlayer->szName, sizeof(pPlayer->szName), "����");
			pPlayer->iHp = 100;
			pPlayer->iAtk = 10;
			break;
		case 2:
			strcpy_s(pPlayer->szName, sizeof(pPlayer->szName), "������");
			pPlayer->iHp = 100;
			pPlayer->iAtk = 10;
			break;
		case 3:
			strcpy_s(pPlayer->szName, sizeof(pPlayer->szName), "����");
			pPlayer->iHp = 100;
			pPlayer->iAtk = 10;
			break;
		default:
			cout << "�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���." << endl;
			system("pause");
			break;
		}
	}
	return pPlayer;
}

void Main_Game(INFO* pPlayer) {
	int iInput(0);
	while (1) {
		system("cls");
		Print(pPlayer);
		cout << "1. ����� 2. ���� : ";
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			ChoiseMonster(pPlayer);
			break;
		case 2:
			return;
		}
	}
}

void Print(INFO* pInfo) {
	cout << "==================================" << endl;
	cout << "�̸� : " << pInfo->szName << endl;
	cout << "ü�� : " << pInfo->iHp << "\t���ݷ� : " << pInfo->iAtk << endl;
}

void ChoiseMonster(INFO* pPlayer) {
	int iInput(0);
	INFO* pMonster = nullptr;
	while (1) {
		system("cls");
		Print(pPlayer);
		cout << "1. �ʱ� 2. �߱� 3. ��� 4. �� �ܰ� : ";
		cin >> iInput;
		switch (iInput)
		{
		case 1:
		case 2:
		case 3:
			CreateMonster(&pMonster, iInput);
			Fight(pPlayer, pMonster);
			break;
		case 4:
			return;
		default:
			cout << "�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���." << endl;
			system("pause");
			break;
		}
	}
}

void CreateMonster(INFO** pMonster, int iInput) {
	*pMonster = new INFO;
	switch (iInput)
	{
	case 1:
		strcpy_s((*pMonster)->szName, sizeof((*pMonster)->szName), "�ʱ�");
		(*pMonster)->iHp = 30;
		(*pMonster)->iAtk = 3;
		break;
	case 2:
		strcpy_s((*pMonster)->szName, sizeof((*pMonster)->szName), "�߱�");
		(*pMonster)->iHp = 60;
		(*pMonster)->iAtk = 6;
		break;
	case 3:
		strcpy_s((*pMonster)->szName, sizeof((*pMonster)->szName), "���");
		(*pMonster)->iHp = 90;
		(*pMonster)->iAtk = 9;
		break;
	}
}

void Fight(INFO* pPlayer, INFO* pMonster) {
	int iInput(0);
	while (1) {
		system("cls");
		Print(pPlayer);
		Print(pMonster);
		cout << "1. ���� 2. ���� : ";
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			pPlayer->iHp -= pMonster->iAtk;
			pMonster->iHp -= pPlayer->iAtk;
			if (0 >= pPlayer->iHp) {
				cout << "�÷��̾� ���" << endl;
				pPlayer->iHp = 100;
				system("pause");
			}
			else if (0 >= pMonster->iHp) {
				cout << "�¸�" << endl;
				system("pause");
			}
			else {
				break;
			}
		case 2:
			delete pMonster;
			pMonster = nullptr;
			return;
		}
	}

}