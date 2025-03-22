#include "pch.h"
#include "CObj.h"

CObj::CObj() : m_fSpeed(0.f), m_fGravity(0.f), m_bDead(false), m_tdiagram(RECTANGLE)
{
	ZeroMemory(&m_tInfo, sizeof(INFO));
	ZeroMemory(&m_tRect, sizeof(RECT));
}

CObj::~CObj()
{
}

void CObj::Render(HDC hDC)
{
	switch (m_tdiagram) {
	case CIRCLE:
		Ellipse(hDC,
			m_tRect.left, m_tRect.top,
			m_tRect.right, m_tRect.bottom);
		break;
	case RECTANGLE:
		Rectangle(hDC,
			m_tRect.left, m_tRect.top,
			m_tRect.right, m_tRect.bottom);
		break;
	}
}

void CObj::Update_Rect()
{
	m_tRect.left   = long(m_tInfo.fX - m_tInfo.fCX / 2.f);
	m_tRect.top    = long(m_tInfo.fY - m_tInfo.fCY / 2.f);
	m_tRect.right  = long(m_tInfo.fX + m_tInfo.fCX / 2.f);
	m_tRect.bottom = long(m_tInfo.fY + m_tInfo.fCY / 2.f);

}
