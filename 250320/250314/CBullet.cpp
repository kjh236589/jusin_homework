#include "pch.h"
#include "CBullet.h"

CBullet::CBullet()
{
}

CBullet::~CBullet()
{
}

void CBullet::Initialize()
{
	m_tInfo.fCX = 40.f;
	m_tInfo.fCY = 40.f;

	m_fSpeed = 5.f;
}

int CBullet::Update()
{
	if (m_bDead)
		return DEAD;

	__super::Update_Rect();

	m_tInfo.fX += m_fSpeed * cosf(m_fAngle * (PI / 180.f));
	m_tInfo.fY -= m_fSpeed * sinf(m_fAngle * (PI / 180.f));

	return NOEVENT;
}

void CBullet::Late_Update()
{
	/*if (100 >= m_tRect.left || WINCX - 100 <= m_tRect.right
		|| 100 >= m_tRect.top || WINCY - 100 <= m_tRect.bottom)
	{
		m_bDead = true;
	}*/
}



void CBullet::Render(HDC hDC)
{
	Ellipse(hDC,
		m_tRect.left, m_tRect.top,
		m_tRect.right, m_tRect.bottom);
}

void CBullet::Release()
{
}

