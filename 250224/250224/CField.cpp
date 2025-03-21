#include "pch.h"
#include "CField.h"

CField::CField()
{
	m_pCopyPlayer = nullptr;
	m_pMonster = nullptr;
}

CField::~CField()
{
	Release();
}

void CField::Initialize()
{
}

void CField::Update()
{
	int iInput(0);

	while (true)
	{
		system("cls");

		m_pCopyPlayer->Render();

		cout << "1. 초급 2. 중급 3. 고급 4. 전 단계 : ";
		cin >> iInput;

		switch (iInput)
		{
		case 1:
			m_pMonster = new CMonster("초급", 30, 3);
			break;

		case 2:
			m_pMonster = new CMonster("중급", 60, 6);
			break;

		case 3:
			m_pMonster = new CMonster("고급", 90, 9);
			break;

		case 4:
			return;
		}

		int iResult = Fight();

		if (1 == iResult)
		{
			m_pCopyPlayer->Set_Hp(100);
		}

		if (nullptr != m_pMonster)
		{
			SAFE_DELETE(m_pMonster);
		}

		system("pause");
	}

}

void CField::Release()
{
	SAFE_DELETE(m_pMonster);
}

int CField::Fight()
{
	int iInput(0);

	while (true)
	{
		system("cls");

		m_pCopyPlayer->Render();
		m_pMonster->Render();

		cout << "1. 공격 2. 도망 : ";
		cin >> iInput;

		if (1 == iInput)
		{
			m_pMonster->Set_Damage(m_pCopyPlayer->Get_Info().iAttack);
			m_pCopyPlayer->Set_Damage(m_pMonster->Get_Info().iAttack);

			if (0 >= m_pCopyPlayer->Get_Info().iHp)
			{
				cout << "사망" << endl;
				return 1;
			}

			if (0 >= m_pMonster->Get_Info().iHp)
			{
				cout << "승리" << endl;
				return 0;
			}
		}

		else if(2 == iInput)
			return 0;
	}
}
