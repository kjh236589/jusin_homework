#include "pch.h"
#include "CObject.h"

CObject::CObject()
{
	pObject = nullptr;
}

CObject::~CObject()
{
	Release();
}

void CObject::Initialize()
{
	pObject = new INFO();
}

void CObject::Update()
{
}

void CObject::Release()
{
	SAFE_DELETE(pObject);
}
void CObject::Reset()
{
	pObject->iHp = pObject->iMaxHp;
}

void CObject::Print()
{
	cout << "==================================" << endl;
	cout << "이름 : " << pObject->szName << endl;
	cout << "체력 : " << pObject->iHp << "\t공격력 : " << pObject->iAtk << endl;
}

void CObject::Save()
{
	FILE* pSaveFile = NULL;
	errno_t errSave = fopen_s(&pSaveFile, "../Data/Save.dat", "wb");
	if (0 == errSave)
	{
		fwrite(pObject, sizeof(*pObject), 1, pSaveFile);
		fclose(pSaveFile);
	}
	else {
		cout << "세이브 실패" << endl;
	}
}

bool CObject::Load()
{
	FILE* pLoadSave = NULL;
	errno_t errLoad = fopen_s(&pLoadSave, "../Data/Save.dat", "rb");
	if (0 == errLoad)
	{
		fread(pObject, sizeof(*pObject), 1, pLoadSave);
		fclose(pLoadSave);
		return true;
	}
	else {
		cout << "세이브 로드 실패" << endl;
		system("pause");
		return false;
	}
}

bool CObject::CreatePlayer()
{
	int iInput(0);
	while (1) {
		system("cls");
		cout << "1. 전사 2. 마법사 3. 도적 4. 불러오기 5. 종료 : ";
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			strcpy_s(pObject->szName, sizeof(pObject->szName), "전사");
			pObject->iMaxHp = 100;
			pObject->iAtk = 10;
			break;
		case 2:
			strcpy_s(pObject->szName, sizeof(pObject->szName), "마법사");
			pObject->iMaxHp = 40;
			pObject->iAtk = 20;
			break;
		case 3:
			strcpy_s(pObject->szName, sizeof(pObject->szName), "도적");
			pObject->iMaxHp = 70;
			pObject->iAtk = 15;
			break;
		case 4:
			if (Load()) {
				return true;
			}
			else {
				continue;
			}
		case 5:
			return false;
		default:
			cout << "잘못된 입력입니다." << endl;
			system("pause");
			continue;
		}
		Reset();
		return true;
	}
}

bool CObject::CreateMonster()
{
	int iInput(0);
	while (1) {
		cout << "1. 초급 2. 중급 3. 고급 4. 나가기 : ";
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			strcpy_s(pObject->szName, sizeof(pObject->szName), "초급");
			pObject->iHp = 30;
			pObject->iAtk = 3;
			break;
		case 2:
			strcpy_s(pObject->szName, sizeof(pObject->szName), "중급");
			pObject->iHp = 60;
			pObject->iAtk = 6;
			break;
		case 3:
			strcpy_s(pObject->szName, sizeof(pObject->szName), "고급");
			pObject->iHp = 90;
			pObject->iAtk = 9;
			break;
		case 4:
			Release();
			return false;
		default:
			cout << "잘못된 입력입니다." << endl;
			system("pause");
			continue;
		}
		return true;
	}
}

bool CObject::Damage(int iDmg)
{
	pObject->iHp -= iDmg;
	if (0 >= pObject->iHp) {
		return true;
	}
	return false;
}

int CObject::GetDamage()
{
	return pObject->iAtk;
}
