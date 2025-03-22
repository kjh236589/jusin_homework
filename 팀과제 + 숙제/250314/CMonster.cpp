#include "pch.h"
#include "CMonster.h"
#include "CBullet.h"
#include "CCircleBullet.h"
#include "CMap.h"
#include "CAbstractFactory.h"

CMonster::CMonster() : b_jump(false), i_Hp(10), b_Damage(false), f_DamageTime(GetTickCount64()), f_CoolTime(GetTickCount64()), m_fAngle(90.f), m_fGunX(0.f), m_fGunY(0.f)
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

	m_fSpeed = 3.f;
}

int CMonster::Update()
{
	if (m_bDead)
		return DEAD;

	//m_tInfo.fX += m_fSpeed;
	__super::Update_Rect();
	m_tInfo.fY += m_fGravity;
	if (p_Player) {
		float x = p_Player->Get_Info()->fX - m_tInfo.fX;
		float y = p_Player->Get_Info()->fY - m_tInfo.fY;
		float z = sqrtf(pow(x, 2) + pow(y, 2));

		float theta = acos(x / z);
		//if (y < 0) {
		//	theta += (PI - theta) * 2;
		//}
		m_tInfo.fX += m_fSpeed * cos(theta);
		//m_tInfo.fY += m_fSpeed * sin(theta);
		if (b_jump) {
			m_fGravity += 0.1f;
		}
		else if (m_fGravity > 0.f) {
			m_fGravity = 0.f;
		}
		if (b_Damage && f_DamageTime + 15.f <= GetTickCount64()) {
			b_Damage = false;
		}
	}
	else {

	}
	b_jump = true;
	return NOEVENT;
}

void CMonster::Late_Update()
{
	//if ((100 >= m_tRect.left) || (WINCX - 100 <= m_tRect.right))
	//	m_fSpeed *= -1.f;
}

void CMonster::Render(HDC hDC)
{
	if (!b_Damage) {
		__super::Render(hDC);
	}
}

void CMonster::Release()
{
}

void CMonster::Set_Collision(CObj* p_obj) {
	if (nullptr != dynamic_cast<CMap*>(p_obj)) {
		if (0.f < m_fGravity && m_tRect.bottom >= p_obj->Get_Rect()->top && m_tRect.bottom - 10.f <= p_obj->Get_Rect()->top) {
			b_jump = false;
			m_tInfo.fY = (p_obj->Get_Rect()->top) - (m_tInfo.fCY / 2.f) + 1;
		}
	}else if (!b_Damage && nullptr != dynamic_cast<CBullet*>(p_obj) && 0 < dynamic_cast<CBullet*>(p_obj)->Get_Damage()) {
		i_Hp -= dynamic_cast<CBullet*>(p_obj)->Get_Damage();
		if (0 >= i_Hp) {
			m_bDead = true;
		}
		else {
			b_Damage = true;
			f_DamageTime = GetTickCount64();
		}
	}
}

void CMonster::Set_Player(CPlayer* _player)
{
	p_Player = _player;
}

CObj* CMonster::Create_Bullet(float _fSize, float _fSpeed, int _iDamage) {
	CObj* pBullet = CAbstractFactory<CBullet>::Create_Obj(m_fGunX, m_fGunY, _fSize, _fSize, CIRCLE);
	dynamic_cast<CBullet*>(pBullet)->SetSpeed((m_fGunX - m_tInfo.fX) / 100.f * _fSpeed, (m_fGunY - m_tInfo.fY) / 100.f * _fSpeed);
	dynamic_cast<CBullet*>(pBullet)->Set_Damage(_iDamage);
	return pBullet;
}