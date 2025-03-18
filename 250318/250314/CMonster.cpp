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
	m_tInfo.fCX = 40.f;
	m_tInfo.fCY = 40.f;

	m_fSpeed = 2.f;
}

int CMonster::Update()
{
	if (m_bDead)
		return DEAD;

	m_tInfo.fX += m_fSpeed;
	__super::Update_Rect();
	m_tInfo.fY += m_fGravity;
	if (Get_Rect()->bottom <= WINCY) {
		m_fGravity += 0.1f;
	}
	else if (m_fGravity > 0.f) {
		m_tInfo.fY = WINCY - (m_tInfo.fCY / 2.f) + 1;
		m_fGravity = 0.f;
	}

	return NOEVENT;
}

void CMonster::Late_Update()
{
	if ((100 >= m_tRect.left) || (WINCX - 100 <= m_tRect.right))
		m_fSpeed *= -1.f;
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
