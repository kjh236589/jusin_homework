#include "pch.h"
#include "CCircleBullet.h"

CCircleBullet::CCircleBullet() : info({0,0,0,0}), m_fAngle(0.f)
{
}

CCircleBullet::~CCircleBullet()
{
	Release();
}

int CCircleBullet::Update()
{
	if (m_bDead)
		return DEAD;

	info.fX += m_fSpeed;
	info.fY += m_fYSpeed;
	float theta = m_fAngle * (PI / 180);
	m_tInfo.fX = info.fX - (cosf(theta) * 15.f);
	m_tInfo.fY = info.fY - (sinf(theta) * 15.f);
	m_fAngle += 10.f;
	__super::Update_Rect();

	return NOEVENT;
}

void CCircleBullet::SetSpeed(float _x, float _y)
{
	m_fSpeed = _x;
	m_fYSpeed = _y;
	info.fX = m_tInfo.fX + (_x * 8.f);
	info.fY = m_tInfo.fY + (_y * 8.f);
	float theta = acosf(_x / sqrtf(pow(_x, 2) + pow(_y, 2)));
	if (0 > _y) {
		theta *= -1;
	}
	m_fAngle = theta / (PI / 180);
}
