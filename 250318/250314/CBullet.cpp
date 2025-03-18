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
	m_tInfo.fCX = 10.f;
	m_tInfo.fCY = 10.f;
}

int CBullet::Update()
{
	if (m_bDead)
		return DEAD;

	__super::Update_Rect();

	m_tInfo.fX += m_fSpeed;
	m_tInfo.fY += m_fYSpeed;

	return NOEVENT;
}

void CBullet::Late_Update()
{
	if (0 >= m_tRect.left || WINCX <= m_tRect.right
		|| 0 >= m_tRect.top || WINCY <= m_tRect.bottom)
	{
		m_bDead = true;
	}
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

void CBullet::SetSpeed(float _x, float _y)
{
	m_fSpeed = _x;
	m_fYSpeed = _y;
}