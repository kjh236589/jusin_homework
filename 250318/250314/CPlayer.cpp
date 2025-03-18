#include "pch.h"
#include "CPlayer.h"
#include "CBullet.h"
#include "CBoom.h"
#include "CAbstractFactory.h"

CPlayer::CPlayer() : m_pBullet(nullptr), left(false), coolTime(GetTickCount64()), boomCoolTime(GetTickCount64()), item(MACHINEGUN)
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
	theta = angle * 2 * PI / 360;
	m_tInfo.fY += m_fGravity;
	if (Get_Rect()->bottom <= WINCY) {
		m_fGravity += 0.1f;
	}
	else if(m_fGravity > 0.f){
		m_tInfo.fY = WINCY - (m_tInfo.fCY / 2.f) + 1;
		m_fGravity = 0.f;
	}
	return NOEVENT;
}

void CPlayer::Render(HDC hDC)
{
	Ellipse(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	MoveToEx(hDC, Get_Info()->fX, Get_Info()->fY, NULL);
	LineTo(hDC, 100.f * cos(theta) + Get_Info()->fX, 100 * sin(theta) + Get_Info()->fY);

}

void CPlayer::Release()
{
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

	if (GetAsyncKeyState(VK_DOWN) && Get_Rect()->bottom <= WINCY)
	{
		if (270 >= angle && 90 < angle) {
			angle -= 10;
		}
		else if (-90 < angle && 90 > angle) {
			angle += 10;
		}
	}
	else {
		if (180 > angle && 90 <= angle && left) {
			angle += 10;
		}
		else if (0 < angle && 90 >= angle) {
			angle -= 10;
		}
	}

	if (GetAsyncKeyState(VK_SPACE) && Get_Rect()->bottom >= WINCY)
	{
		m_fGravity = -6.f;
	}

	if (GetAsyncKeyState('Z'))
	{
		switch (item)
		{
		case BASIC:
			if (coolTime + 200 <= GetTickCount64()) {
				CObj* pBullet = CAbstractFactory<CBullet>::Create_Obj(100.f * cos(theta) + Get_Info()->fX, 100 * sin(theta) + Get_Info()->fY);
				pBullet->Set_Size(5.f, 5.f);
				dynamic_cast<CBullet*>(pBullet)->SetSpeed(((100.f * cos(theta) + Get_Info()->fX) - Get_Info()->fX) / 10.f, ((100 * sin(theta) + Get_Info()->fY) - Get_Info()->fY) / 10.f);
				m_pBullet->push_back(pBullet);
				coolTime = GetTickCount64();
			}
			break;
		case MACHINEGUN:
			if (coolTime + 50 <= GetTickCount64()) {
				CObj* pBullet = CAbstractFactory<CBullet>::Create_Obj(100.f * cos(theta) + Get_Info()->fX, 100 * sin(theta) + Get_Info()->fY);
				pBullet->Set_Size(20.f, 20.f);
				dynamic_cast<CBullet*>(pBullet)->SetSpeed(((100.f * cos(theta) + Get_Info()->fX) - Get_Info()->fX) / 10.f, ((100 * sin(theta) + Get_Info()->fY) - Get_Info()->fY) / 10.f);
				m_pBullet->push_back(pBullet);
				coolTime = GetTickCount64();
			}
			break;
		case SHOTGUN:
			break;
		default:
			break;
		}
	}
	if (GetAsyncKeyState('X') && boomCoolTime + 300 <= GetTickCount64()) {
		CObj* pBullet = CAbstractFactory<CBoom>::Create_Obj(m_tInfo.fX, m_tInfo.fY);
		pBullet->Set_Size(50.f, 50.f);
		dynamic_cast<CBullet*>(pBullet)->SetSpeed(left?-7.f:7.f, -10.f);
		m_pBullet->push_back(pBullet);
		boomCoolTime = GetTickCount64();
	}

}

CObj* CPlayer::Create_Bullet()
{

	CObj* pBullet = CAbstractFactory<CBullet>::Create_Obj(100.f * cos(theta) + Get_Info()->fX, 100 * sin(theta) + Get_Info()->fY);
	return pBullet;
}

void CPlayer::Late_Update()
{
}
