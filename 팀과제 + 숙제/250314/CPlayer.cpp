#include "pch.h"
#include "CPlayer.h"
#include "CBullet.h"
#include "CBoom.h"
#include "CMap.h"
#include "CAbstractFactory.h"

CPlayer::CPlayer() : m_pBullet(nullptr), left(false), b_jump(false), b_Pass(true), coolTime(GetTickCount64()), boomCoolTime(GetTickCount64()), item(BASIC), angle(0), boom(10), bullets(0), theta(0.f), gunX(0.f), gunY(0.f)//, angle2(0)
{
}

CPlayer::~CPlayer()
{
	Release();
}

void CPlayer::Initialize()
{
	m_fSpeed = 5.f;
	Update_Angle();
}

int CPlayer::Update()
{
	__super::Update_Rect();
	Key_Input();
	Update_Angle();
	m_tInfo.fY += m_fGravity;
	if (b_jump) {
		m_fGravity += 0.1f;
	}
	if (m_bDead || WINCY <= m_tRect.top) {
		return DEAD;
	}
	//angle2 += 3.f;
	return NOEVENT;
}

void CPlayer::Render(HDC hDC)
{

	// 문자열 출력

	TCHAR	szName[32] = L"";

	// wsprintf(szName, L"Bullet : %d", m_BulletList.size()); // 정수만 출력 가능

	if (0 < bullets) {
		swprintf_s(szName, L"Bullet : %d", bullets);
	}
	else {
		swprintf_s(szName, L"Bullet : ∞");
	}
	TextOut(hDC, 10, 10, szName, lstrlen(szName));
	swprintf_s(szName, L"Boom : %d", boom);
	TextOut(hDC, 10, 30, szName, lstrlen(szName));

	//float x = Get_Info()->fX + (cosf(angle2 * (PI / 180)) * 150.f);
	//float y = Get_Info()->fY - (sinf(angle2 * (PI / 180)) * 150.f);
	//Ellipse(hDC, x-50.f, y - 50.f, x + 50.f, y + 50.f);

	Ellipse(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	MoveToEx(hDC, m_tInfo.fX, m_tInfo.fY, NULL);
	LineTo(hDC, gunX, gunY);
}

void CPlayer::Release()
{
}

void CPlayer::Set_Collision(CObj* p_obj)
{
	if (nullptr != dynamic_cast<CMap*>(p_obj)) {
		if (0.f < m_fGravity && m_tRect.bottom >= p_obj->Get_Rect()->top && m_tInfo.fX <= p_obj->Get_Info()->fX + (p_obj->Get_Info()->fCX / 2) && m_tInfo.fX >= p_obj->Get_Info()->fX - (p_obj->Get_Info()->fCX / 2) && m_tRect.bottom - (m_fGravity * 2.f) <= p_obj->Get_Rect()->top) {

				m_tInfo.fY = (p_obj->Get_Rect()->top) - (m_tInfo.fCY / 2.f) + 1;
				m_fGravity = 0.f;			b_jump = false;
		}
		if (!dynamic_cast<CMap*>(p_obj)->Get_Pass()) {
			b_Pass = false;
			if (0.f >= m_fGravity && m_tRect.top <= p_obj->Get_Rect()->bottom && m_tRect.bottom + (m_fGravity * 2.f) > p_obj->Get_Rect()->top && m_tRect.top - (m_fGravity * 2.f) > p_obj->Get_Rect()->bottom) {
				m_tInfo.fY = (p_obj->Get_Rect()->bottom) + (m_tInfo.fCY / 2.f) - 1.f;
				m_fGravity = 0.f;
			}
		}
	}

	if (nullptr != dynamic_cast<CBullet*>(p_obj) && 0 > dynamic_cast<CBullet*>(p_obj)->Get_Damage()) {
		m_bDead = true;
	}
}

void CPlayer::Set_Item(ITEM _item, int _bullets)
{
	item = _item;
	bullets = _bullets;
}

void CPlayer::Key_Input()
{
	if (GetAsyncKeyState(VK_RIGHT))
	{
		m_tInfo.fX += m_fSpeed;

		left = false;
		if (angle == 180) {
			angle = 0;
		}
		if (angle == 270) {
			angle = -90;
		}
	}
	if (GetAsyncKeyState(VK_LEFT))
	{
		m_tInfo.fX -= m_fSpeed;
		left = true;
		if (angle == 0) {
			angle = 180;
		}
		if (angle == -90) {
			angle = 270;
		}
	}
	if (GetAsyncKeyState(VK_DOWN) && b_jump && b_Pass)
	{
		if (90 >= angle && -90 < angle) {
			angle -= 10;
		}
		else if (90 < angle && 270 > angle) {
			angle += 10;
		}
	}
	else {
		if (180 < angle) {
			angle -= 10;
		}
		else if (0 > angle) {
			angle += 10;
		}
	}

	if (GetAsyncKeyState(VK_UP))
	{
		if (270 >= angle && 90 < angle) {
			angle -= 10;
		}
		else if (-90 < angle && 90 > angle) {
			angle += 10;
		}
	}
	else {
		if ((180 > angle && 90 < angle) || (90 == angle && left)) {
			angle += 10;
		}
		else if (0 < angle && 90 >= angle) {
			angle -= 10;
		}
	}

	if (GetAsyncKeyState(VK_SPACE) && !b_jump && 0.f == m_fGravity)
	{
		if (GetAsyncKeyState(VK_DOWN))
		{
			if (b_Pass) {
				m_tInfo.fY += 6.f;
				__super::Update_Rect();
				m_fGravity = 3.f;
			}
		}
		else{
			m_fGravity = -6.f;
		}
		b_jump = true;
	}

	if (GetAsyncKeyState('Z'))
	{
		switch (item)
		{
		case BASIC:
			if (coolTime + 200 <= GetTickCount64()) {
				CObj* pBullet = Create_Bullet(10.f, 10.f, 2);
				//dynamic_cast<CBullet*>(pBullet)->SetMonsterList(m_pMonster);
				m_pBullet->push_back(pBullet);
				coolTime = GetTickCount64();
			}
			break;
		case MACHINEGUN:
			if (coolTime + 50 <= GetTickCount64()) {
				CObj* pBullet = Create_Bullet(20.f, 10.f, 1);
				//dynamic_cast<CBullet*>(pBullet)->SetMonsterList(m_pMonster);
				m_pBullet->push_back(pBullet);
				coolTime = GetTickCount64();
				if (0 >= --bullets) {
					item = BASIC;
				}
			}
			break;
		case SHOTGUN:
			break;
		default:
			break;
		}
	}
	if (GetAsyncKeyState('X') && boomCoolTime + 300 <= GetTickCount64() && 0 < boom) {
		CObj* pBullet = CAbstractFactory<CBoom>::Create_Obj(m_tInfo.fX, m_tInfo.fY, 50.f, 50.f, CIRCLE);
		dynamic_cast<CBullet*>(pBullet)->SetSpeed(left?-7.f:7.f, -10.f);
		m_pBullet->push_back(pBullet);
		boomCoolTime = GetTickCount64();
		--boom;
	}

}

void CPlayer::Update_Angle()
{
	theta = angle * (PI / 180);
	gunX = m_tInfo.fX + (cosf(theta) * 100.f);
	gunY = m_tInfo.fY - (sinf(theta) * 100.f);
}

CObj* CPlayer::Create_Bullet(float _fSize, float _fSpeed, int _iDamage)
{
	CObj* pBullet = CAbstractFactory<CBullet>::Create_Obj(gunX, gunY, _fSize, _fSize, CIRCLE);
	dynamic_cast<CBullet*>(pBullet)->SetSpeed((gunX - m_tInfo.fX) / 100.f * _fSpeed, (gunY - m_tInfo.fY) / 100.f * _fSpeed);
	dynamic_cast<CBullet*>(pBullet)->Set_Damage(_iDamage);
	return pBullet;
}

void CPlayer::Late_Update()
{
	b_jump = true;
	b_Pass = true;
}
