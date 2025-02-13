#include "pch.h"

class Object
{
public:
	char szName[32];
	int iMaxHp;
	int iHp;
	int iAtk;

	void CreateObject(char szname[32], int imaxhp, int iatk) {
		strcpy_s(szName, sizeof(szName), szname);
		iMaxHp = imaxhp;
		iAtk = iatk;
		Reset();
	}

	void Reset() {
		iHp = iMaxHp;
	}

	void Damage(Object oObject) {
		iHp -= oObject.iAtk;
	}
};

Object* CreatePlayer();

Object* CreateMonster(int iInput);

void Print(Object* oObject);

void PlayGame(Object* oPlayer);

void Choise(Object* oPlayer);

void Fight(Object* oPlayer, Object* oMonster);

int main()
{
	Object* oPlayer = CreatePlayer();
	if ((*oPlayer).iHp != 0) {
		PlayGame(oPlayer);
	}
	cout << "게임 종료" << endl;
	FILE* pSaveFile = NULL;
	errno_t errSave = fopen_s(&pSaveFile, "../Data/Save.dat", "wb");
	if (0 == errSave)
	{
		fwrite(oPlayer, sizeof(*oPlayer), 1, pSaveFile);
	}
	else {
		cout << "세이브 실패" << endl;
	}
	if (NULL != pSaveFile) {
		fclose(pSaveFile);
	}
	delete oPlayer;
	oPlayer = nullptr;
	return 0;
}

Object* CreatePlayer() {
	Object* oPlayer = new Object();
	int iInput(0);
	char szName[32] = {};
	FILE* pLoadSave = NULL;
	errno_t errLoad = fopen_s(&pLoadSave, "../Data/Save.dat", "rb");
	while (true)
	{
		system("cls");
		cout << "직업을 선택하세요(1. 전사 2. 마법사 3. 도적 4. 불러오기 5. 나가기) : ";
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			strcpy_s(szName, sizeof(szName), "전사");
			oPlayer->CreateObject(szName, 100, 10);
			break;
		case 2:
			strcpy_s(szName, sizeof(szName), "마법사");
			oPlayer->CreateObject(szName, 100, 10);
			break;
		case 3:
			strcpy_s(szName, sizeof(szName), "도적");
			oPlayer->CreateObject(szName, 100, 10);
			break;
		case 4:
			if (0 == errLoad)
			{
				fread(oPlayer, sizeof(*oPlayer), 1, pLoadSave);
			}
			else {
				cout << "세이브 로드 실패" << endl;
				system("pause");
				continue;
			}
			break;
		case 5:
			break;
		default:
			cout << "잘못된 입력입니다. 다시 입력해주세요." << endl;
			system("pause");
			continue;
		}
		if (NULL != pLoadSave) {
			fclose(pLoadSave);
		}
		return oPlayer;
	}
}

void Print(Object* oObject) {
	cout << "==================================" << endl;
	cout << "이름 : " << oObject->szName << endl;
	cout << "체력 : " << oObject->iHp << "\t공격력 : " << oObject->iAtk << endl;
}

void PlayGame(Object* oPlayer) {
	int iInput(0);
	while (true)
	{
		system("cls");
		Print(oPlayer);
		cout << "1. 사냥터 2. 종료 : ";
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			Choise(oPlayer);
			break;
		case 2:
			return;
		}
	}
}

void Choise(Object* oPlayer) {
	int iInput(0);
	Object* oMonster;
	while (true)
	{
		system("cls");
		Print(oPlayer);
		cout << "1. 초급 2. 중급 3. 고급 4. 전 단계 : ";
		cin >> iInput;
		if (0 < iInput && 3 >= iInput) {
			oMonster = CreateMonster(iInput);
			Fight(oPlayer, oMonster);
			delete oMonster;
			oMonster = nullptr;
		}
		else if (iInput == 4) {
			return;
		}
	}
}

Object* CreateMonster(int iInput) {
	char szName[32] = {};
	Object* oMonster = new Object();
	switch (iInput)
	{
	case 1:
		strcpy_s(szName, sizeof(szName), "초급");
		oMonster->CreateObject(szName, 30, 3);
		break;
	case 2:
		strcpy_s(szName, sizeof(szName), "중급");
		oMonster->CreateObject(szName, 60, 6);
		break;
	case 3:
		strcpy_s(szName, sizeof(szName), "고급");
		oMonster->CreateObject(szName, 90, 9);
		break;
	}
	return oMonster;
}

void Fight(Object* oPlayer, Object* oMonster) {
	int iInput(0);
	while (1) {
		system("cls");
		Print(oPlayer);
		Print(oMonster);
		cout << "1. 공격 2. 도망 : ";
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			oPlayer->Damage(*oMonster);
			oMonster->Damage(*oPlayer);
			if (0 >= oPlayer->iHp) {
				cout << "플레이어 사망" << endl;
				oPlayer->Reset();
				system("pause");
			}
			else if (0 >= oMonster->iHp) {
				cout << "승리" << endl;
				system("pause");
			}
			else {
				break;
			}
		case 2:
			return;
		}
	}
}