#include "pch.h"
#include "CObj.h"

CObj::CObj()
{
}

CObj::CObj(string szName, int iHp, int iAtk)
{
	obj.szName = szName;
	obj.iHp = iHp;
	obj.iAtk = iAtk;
}

CObj::~CObj()
{
}

void CObj::Print(){
	cout << "�̸� : " << obj.szName << endl << "HP : " << obj.iHp << endl << "���ݷ� : " << obj.iAtk << endl;
}

bool CObj::Damage(OBJ enemy) {
	obj.iHp -= enemy.iAtk;
	if (0 >= obj.iHp) {
		return true;
	}
	return false;
}

OBJ& CObj::GetObj()
{
	return obj;
}
