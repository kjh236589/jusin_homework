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
	cout << "���� ����" << endl;
	FILE* pSaveFile = NULL;
	errno_t errSave = fopen_s(&pSaveFile, "../Data/Save.dat", "wb");
	if (0 == errSave)
	{
		fwrite(oPlayer, sizeof(*oPlayer), 1, pSaveFile);
	}
	else {
		cout << "���̺� ����" << endl;
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
		cout << "������ �����ϼ���(1. ���� 2. ������ 3. ���� 4. �ҷ����� 5. ������) : ";
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			strcpy_s(szName, sizeof(szName), "����");
			oPlayer->CreateObject(szName, 100, 10);
			break;
		case 2:
			strcpy_s(szName, sizeof(szName), "������");
			oPlayer->CreateObject(szName, 100, 10);
			break;
		case 3:
			strcpy_s(szName, sizeof(szName), "����");
			oPlayer->CreateObject(szName, 100, 10);
			break;
		case 4:
			if (0 == errLoad)
			{
				fread(oPlayer, sizeof(*oPlayer), 1, pLoadSave);
			}
			else {
				cout << "���̺� �ε� ����" << endl;
				system("pause");
				continue;
			}
			break;
		case 5:
			break;
		default:
			cout << "�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���." << endl;
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
	cout << "�̸� : " << oObject->szName << endl;
	cout << "ü�� : " << oObject->iHp << "\t���ݷ� : " << oObject->iAtk << endl;
}

void PlayGame(Object* oPlayer) {
	int iInput(0);
	while (true)
	{
		system("cls");
		Print(oPlayer);
		cout << "1. ����� 2. ���� : ";
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
		cout << "1. �ʱ� 2. �߱� 3. ��� 4. �� �ܰ� : ";
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
		strcpy_s(szName, sizeof(szName), "�ʱ�");
		oMonster->CreateObject(szName, 30, 3);
		break;
	case 2:
		strcpy_s(szName, sizeof(szName), "�߱�");
		oMonster->CreateObject(szName, 60, 6);
		break;
	case 3:
		strcpy_s(szName, sizeof(szName), "���");
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
		cout << "1. ���� 2. ���� : ";
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			oPlayer->Damage(*oMonster);
			oMonster->Damage(*oPlayer);
			if (0 >= oPlayer->iHp) {
				cout << "�÷��̾� ���" << endl;
				oPlayer->Reset();
				system("pause");
			}
			else if (0 >= oMonster->iHp) {
				cout << "�¸�" << endl;
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