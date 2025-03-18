#include "pch.h"
#include "CBullet.h"

CBullet::CBullet() : m_fXSpeed(0.f)
{
}

CBullet::~CBullet()
{
	Release();
}

void CBullet::Initialize()
{
}

void CBullet::Update()
{
	__super::Update_Rect();
	m_tInfo.fX += m_fXSpeed;
	m_tInfo.fY += m_fSpeed;
	if (m_tRect.left <= 100 || m_tRect.top <= 100 || m_tRect.right >= WINCX - 100 || m_tRect.bottom >= WINCY - 100) {
		SetRemove();
	}
}

void CBullet::Render(HDC hDC)
{
	Ellipse(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CBullet::Release()
{
}

void CBullet::SetPos(float _fX, float _fY)
{
	m_tInfo = { _fX, _fY, 10, 10 };
}

void CBullet::SetSpeed(float _fX, float _fY)
{
	m_fXSpeed = _fX;
	m_fSpeed = _fY;
}
