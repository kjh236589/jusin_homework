#include "pch.h"
#include "CObj.h"

CObj::CObj()
{
	memset(&m_tInfo, 0, sizeof(INFO));

}

CObj::CObj(const char* pName, int _iHp, int _iAttack)
{
	strcpy_s(m_tInfo.szName, sizeof(m_tInfo.szName), pName);
	m_tInfo.iHp = _iHp;
	m_tInfo.iAttack = _iAttack;
}

CObj::~CObj()
{
}

void CObj::Render()
{
	cout << "===============================================" << endl;
	cout << "�̸� : " << m_tInfo.szName << endl;
	cout << "ü�� : " << m_tInfo.iHp << "\t���ݷ� : " << m_tInfo.iAttack << endl;
}

void CObj::Set_Hp(int _iHp)
{
}

void CObj::Select_Job()
{
}
