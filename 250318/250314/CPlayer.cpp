#include "pch.h"
#include "CPlayer.h"
#include "CBullet.h"
#include "CBoom.h"
#include "CStage.h"
#include "CAbstractFactory.h"

CPlayer::CPlayer() : m_pBullet(nullptr), left(false), b_jump(false), coolTime(GetTickCount64()), boomCoolTime(GetTickCount64()), item(BASIC), angle(0), boom(10), bullets(0), theta(0.f), gunX(0.f), gunY(0.f)
{
}

CPlayer::~CPlayer()
{
	Release();
}

void CPlayer::Initialize()
{
	m_tInfo = { WINCX / 2.f, WINCY / 2.f, 100.f, 100.f };
	m_fSpeed = 5.f;
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
	else if(m_fGravity > 0.f){
		m_fGravity = 0.f;
	}
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
	Ellipse(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	MoveToEx(hDC, Get_Info()->fX, Get_Info()->fY, NULL);
	LineTo(hDC, gunX, gunY);
}

void CPlayer::Release()
{
}

void CPlayer::Set_Collision(CObj* p_obj)
{
	if (nullptr != dynamic_cast<CStage*>(p_obj)) {
		if (0.f <= m_fGravity && m_tRect.bottom >= p_obj->Get_Rect()->top && (m_fGravity == 0.f || m_tRect.bottom - (m_fGravity * 2.f) <= p_obj->Get_Rect()->top)) {
			b_jump = false;
			m_tInfo.fY = (p_obj->Get_Rect()->top) - (m_tInfo.fCY / 2.f) + 1;
		}
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
	if (GetAsyncKeyState(VK_UP))
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

	if (GetAsyncKeyState(VK_DOWN) && b_jump)
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

	if (GetAsyncKeyState(VK_SPACE) && !b_jump)
	{
		if (GetAsyncKeyState(VK_DOWN))
		{
			m_tInfo.fY += 6.f;
			__super::Update_Rect();
			m_fGravity = 3.f;
		}
		else {
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
				CObj* pBullet = CAbstractFactory<CBullet>::Create_Obj(100.f * cos(theta) + Get_Info()->fX, 100 * sin(theta) + Get_Info()->fY);
				pBullet->Set_Size(5.f, 5.f);
				dynamic_cast<CBullet*>(pBullet)->SetSpeed((gunX - Get_Info()->fX) / 10.f, (gunY - Get_Info()->fY) / 10.f);
				m_pBullet->push_back(pBullet);
				coolTime = GetTickCount64();
			}
			break;
		case MACHINEGUN:
			if (coolTime + 50 <= GetTickCount64()) {
				CObj* pBullet = CAbstractFactory<CBullet>::Create_Obj(100.f * cos(theta) + Get_Info()->fX, 100 * sin(theta) + Get_Info()->fY);
				pBullet->Set_Size(20.f, 20.f);
				dynamic_cast<CBullet*>(pBullet)->SetSpeed((gunX - Get_Info()->fX) / 10.f, (gunY - Get_Info()->fY) / 10.f);
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
		CObj* pBullet = CAbstractFactory<CBoom>::Create_Obj(m_tInfo.fX, m_tInfo.fY);
		pBullet->Set_Size(50.f, 50.f);
		dynamic_cast<CBullet*>(pBullet)->SetSpeed(left?-7.f:7.f, -10.f);
		m_pBullet->push_back(pBullet);
		boomCoolTime = GetTickCount64();
		--boom;
	}

}

void CPlayer::Update_Angle()
{
	theta = angle * (PI / 180);
	gunX = Get_Info()->fX + (cos(theta) * 100.f);
	gunY = Get_Info()->fY + (sin(theta) * 100.f);
}

CObj* CPlayer::Create_Bullet()
{
	CObj* pBullet = CAbstractFactory<CBullet>::Create_Obj(100.f * cos(theta) + Get_Info()->fX, 100 * sin(theta) + Get_Info()->fY);
	return pBullet;
}

void CPlayer::Late_Update()
{
	b_jump = true;
}
