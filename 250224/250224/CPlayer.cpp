#include "pch.h"
#include "CPlayer.h"

CPlayer::CPlayer()
{
}

CPlayer::~CPlayer()
{
}

void CPlayer::Select_Job()
{
	int	iInput(0);

	cout << "1. ���� 2. ������ 3. ���� : ";
	cin >> iInput;

	switch (iInput)
	{
	case CPlayer::WARRIOR:

		strcpy_s(m_tInfo.szName, sizeof(m_tInfo.szName), "����");
		m_tInfo.iHp = 100;
		m_tInfo.iAttack = 10;		 

		break;

	case CPlayer::MAGE:
		strcpy_s(m_tInfo.szName, sizeof(m_tInfo.szName), "������");
		m_tInfo.iHp = 100;
		m_tInfo.iAttack = 10;
		break;

	case CPlayer::THIEF:

		strcpy_s(m_tInfo.szName, sizeof(m_tInfo.szName), "����");
		m_tInfo.iHp = 100;
		m_tInfo.iAttack = 10;
		break;
		
	}
}
