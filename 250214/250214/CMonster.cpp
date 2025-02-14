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
		default:
			cout << "잘못된 입력입니다." << endl;
			system("pause");
			continue;
		}
		return;
	}

}

void CObject::Release()
{
	SAFE_DELETE_ARRAY(pObject);
}

bool CObject::Damage(int iDmg)
{
	pObject->iHp -= iDmg;
	if (0 >= pObject->iHp) {
		return true;
	}
	return false;
}
