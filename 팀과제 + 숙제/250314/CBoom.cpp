#include "pch.h"
#include "CBoom.h"
#include "CMap.h"
#include "CMonster.h"
#include "CPlayer.h"

CBoom::CBoom()
{
}

CBoom::~CBoom()
{
}

void CBoom::Initialize()
{
	m_fGravity = -10.f;
	i_Damage = 5;
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

void CBoom::Set_Collision(CObj* p_obj)
{
	if (nullptr != dynamic_cast<CMap*>(p_obj)) {
		if (0.f < m_fGravity && m_tRect.bottom >= p_obj->Get_Rect()->top) {
			m_bDead = true;
		}
	}
	else  if (nullptr != dynamic_cast<CMonster*>(p_obj) && 0 < i_Damage) {
		i_Damage = 0;
		m_bDead = true;
	}
	else if (nullptr != dynamic_cast<CPlayer*>(p_obj) && 0 > i_Damage) {
		m_bDead = true;
	}
}

int CBoom::Get_Damage()
{
	return i_Damage;
}
