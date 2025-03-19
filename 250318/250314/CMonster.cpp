#include "pch.h"
#include "CMonster.h"
#include "CBullet.h"
#include "CStage.h"

CMonster::CMonster() : b_jump(false)
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
	if (b_jump) {
		m_fGravity += 0.1f;
	}
	else if (m_fGravity > 0.f) {
		m_fGravity = 0.f;
	}
	b_jump = true;
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

void CMonster::Set_Collision(CObj* p_obj) {
	if (nullptr != dynamic_cast<CStage*>(p_obj)) {
		if (0.f < m_fGravity && m_tRect.bottom >= p_obj->Get_Rect()->top && m_tRect.bottom - 10.f <= p_obj->Get_Rect()->top) {
			b_jump = false;
			m_tInfo.fY = (p_obj->Get_Rect()->top) - (m_tInfo.fCY / 2.f) + 1;
		}
	}else if (nullptr != dynamic_cast<CBullet*>(p_obj)) {
		m_bDead = true;
	}
}

void CMonster::Release()
{
}
