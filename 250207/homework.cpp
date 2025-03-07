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
		cout << "직업을 선택하세요 : 직업을 선택하세요(1. 전사 2. 마법사 3. 도적) : ";
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			strcpy_s(pPlayer->szName, sizeof(pPlayer->szName), "전사");
			pPlayer->iHp = 100;
			pPlayer->iAtk = 10;
			break;
		case 2:
			strcpy_s(pPlayer->szName, sizeof(pPlayer->szName), "마법사");
			pPlayer->iHp = 100;
			pPlayer->iAtk = 10;
			break;
		case 3:
			strcpy_s(pPlayer->szName, sizeof(pPlayer->szName), "도적");
			pPlayer->iHp = 100;
			pPlayer->iAtk = 10;
			break;
		default:
			cout << "잘못된 입력입니다. 다시 입력해주세요." << endl;
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
		cout << "1. 사냥터 2. 종료 : ";
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
	cout << "이름 : " << pInfo->szName << endl;
	cout << "체력 : " << pInfo->iHp << "\t공격력 : " << pInfo->iAtk << endl;
}

void ChoiseMonster(INFO* pPlayer) {
	int iInput(0);
	INFO* pMonster = nullptr;
	while (1) {
		system("cls");
		Print(pPlayer);
		cout << "1. 초급 2. 중급 3. 고급 4. 전 단계 : ";
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
			cout << "잘못된 입력입니다. 다시 입력해주세요." << endl;
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
		strcpy_s((*pMonster)->szName, sizeof((*pMonster)->szName), "초급");
		(*pMonster)->iHp = 30;
		(*pMonster)->iAtk = 3;
		break;
	case 2:
		strcpy_s((*pMonster)->szName, sizeof((*pMonster)->szName), "중급");
		(*pMonster)->iHp = 60;
		(*pMonster)->iAtk = 6;
		break;
	case 3:
		strcpy_s((*pMonster)->szName, sizeof((*pMonster)->szName), "고급");
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
		cout << "1. 공격 2. 도망 : ";
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			pPlayer->iHp -= pMonster->iAtk;
			pMonster->iHp -= pPlayer->iAtk;
			if (0 >= pPlayer->iHp) {
				cout << "플레이어 사망" << endl;
				pPlayer->iHp = 100;
				system("pause");
			}
			else if (0 >= pMonster->iHp) {
				cout << "승리" << endl;
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