#include "pch.h"
#include "CBoss.h"
#include "CAbstractFactory.h"
#include "CBullet.h"
#include "CCircleBullet.h"

CBoss::CBoss()
{
}

CBoss::~CBoss()
{
	Release();
}

void CBoss::Initialize()
{
	i_Hp = 100;
	m_fSpeed = 0.5f;
}

int CBoss::Update()
{
	if (m_bDead)
		return DEAD;

	//m_tInfo.fY += m_fSpeed;
	__super::Update_Rect();
	//if (m_tRect.left <= 0 || m_tRect.right >= WINCX) {
	//	m_fSpeed *= -1;
	//}
	if (p_Player) {
		if (120.f <= m_fAngle || 0 >= m_fAngle) {
			m_fSpeed *= -1.f;
		}
		m_fAngle += m_fSpeed;
		float theta = m_fAngle * (PI / 180.f);
		m_fGunX = m_tInfo.fX + (cos(theta) * 100.f);
		m_fGunY = m_tInfo.fY + (sin(theta) * 100.f);
		if (f_CoolTime +200.f <= GetTickCount64()) {
			if (70 < i_Hp) {
				m_pBullet->push_back(Create_Bullet(10.f, 5.f, -1));
				f_CoolTime = GetTickCount64();
			}
			else if(40 < i_Hp){
				m_pBullet->push_back(Create_CircleBullet(10.f, 3.f, -1));
				f_CoolTime = GetTickCount64();
			}
			else {
				m_pBullet->push_back(Create_CircleBullet(10.f, 3.f, -1));
				theta = (m_fAngle - 15.f) * (PI / 180.f);
				m_fGunX = m_tInfo.fX + (cos(theta) * 100.f);
				m_fGunY = m_tInfo.fY + (sin(theta) * 100.f);
				m_pBullet->push_back(Create_CircleBullet(10.f, 3.f, -1));
				theta = (m_fAngle + 15.f) * (PI / 180.f);
				m_fGunX = m_tInfo.fX + (cos(theta) * 100.f);
				m_fGunY = m_tInfo.fY + (sin(theta) * 100.f);
				m_pBullet->push_back(Create_CircleBullet(10.f, 3.f, -1));
				float theta = m_fAngle * (PI / 180.f);
				m_fGunX = m_tInfo.fX + (cos(theta) * 100.f);
				m_fGunY = m_tInfo.fY + (sin(theta) * 100.f);
				f_CoolTime = GetTickCount64() - 50.f;
			}
		}
		//if (b_jump) {
		//	m_fGravity += 0.1f;
		//}
		//else if (m_fGravity > 0.f) {
		//	m_fGravity = 0.f;
		//}
	}
	if (b_Damage && f_DamageTime + 15.f <= GetTickCount64()) {
		b_Damage = false;
	}
	b_jump = true;
	return NOEVENT;
}

void CBoss::Late_Update()
{
	//if ((100 >= m_tRect.left) || (WINCX - 100 <= m_tRect.right))
	//	m_fSpeed *= -1.f;
}

void CBoss::Render(HDC hDC)
{
	if (!b_Damage) {
		__super::Render(hDC);
		MoveToEx(hDC, m_tInfo.fX, m_tInfo.fY, NULL);
		LineTo(hDC, m_fGunX, m_fGunY);
		TCHAR	szName[32] = L"";
		swprintf_s(szName, L"Boss Hp : %d", i_Hp);
		TextOut(hDC, 10, 70, szName, lstrlen(szName));
	}
}

void CBoss::Release()
{
}

CObj* CBoss::Create_CircleBullet(float _fSize, float _fSpeed, int _iDamage) {
	CObj* pBullet = CAbstractFactory<CCircleBullet>::Create_Obj(m_fGunX, m_fGunY, _fSize, _fSize, CIRCLE);
	dynamic_cast<CBullet*>(pBullet)->SetSpeed((m_fGunX - m_tInfo.fX) / 100.f * _fSpeed, (m_fGunY - m_tInfo.fY) / 100.f * _fSpeed);
	dynamic_cast<CBullet*>(pBullet)->Set_Damage(_iDamage);
	return pBullet;
}
