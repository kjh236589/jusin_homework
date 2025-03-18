#include "pch.h"
#include "CBoom.h"

CBoom::CBoom()
{
}

CBoom::~CBoom()
{
}

void CBoom::Initialize()
{
	m_tInfo.fCX = 10.f;
	m_tInfo.fCY = 10.f;
}

int CBoom::Update()
{
	if (m_bDead) {
		if (200.f > m_tInfo.fCX) {
			m_tInfo.fCX += 15.f;
			m_tInfo.fCY += 15.f;
			__super::Update_Rect();
			return NOEVENT;
		}
		else 
			return DEAD;
	}

	__super::Update_Rect();

	m_tInfo.fX += m_fSpeed;
	m_tInfo.fY += m_fYSpeed;
	m_tInfo.fY += m_fGravity;
	if (Get_Rect()->bottom <= WINCY) {
		m_fGravity += 0.3f;
	}
	else if (m_fGravity > 0.f) {
		m_tInfo.fY = WINCY - (m_tInfo.fCY / 2.f) + 1;
		m_fGravity = 0.f;
	}

	return NOEVENT;
}

void CBoom::Late_Update()
{
	if (0 >= m_tRect.left || WINCX <= m_tRect.right
		|| 0 >= m_tRect.top || WINCY <= m_tRect.bottom)
	{
		m_bDead = true;
	}
}



void CBoom::Render(HDC hDC)
{
	Ellipse(hDC,
		m_tRect.left, m_tRect.top,
		m_tRect.right, m_tRect.bottom);
}

void CBoom::Release()
{
}

void CBoom::SetSpeed(float _x, float _y)
{
	m_fSpeed = _x;
	m_fYSpeed = _y;
}