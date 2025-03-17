#include "pch.h"
#include "CMonster.h"

CMonster::CMonster()
{
}

CMonster::~CMonster()
{
	Release();
}

void CMonster::Initialize()
{
	m_tInfo = { WINCX / 2.f, 150.f, 50.f, 50.f };
	m_fSpeed = 3.f;
}

void CMonster::Update()
{
	__super::Update_Rect();
	if (m_tRect.left <= 100 || m_tRect.right >= WINCX - 100) {
		m_fSpeed *= -1;
	}
	m_tInfo.fX += m_fSpeed;
}

void CMonster::Render(HDC hDC)
{
	Rectangle(hDC,
		m_tRect.left, m_tRect.top,
		m_tRect.right, m_tRect.bottom);
}

void CMonster::Release()
{
}
