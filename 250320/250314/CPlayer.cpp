#include "pch.h"
#include "CPlayer.h"
#include "CBullet.h"
#include "CAbstractFactory.h"

CPlayer::CPlayer() : m_pBullet(nullptr)
{
	ZeroMemory(&m_tPosin, sizeof(POINT));
}

CPlayer::~CPlayer()
{
	Release();
}

void CPlayer::Initialize()
{
	m_tInfo = { WINCX / 2.f, WINCY / 2.f, 100.f, 100.f };
	m_fSpeed = 10.f;
	m_fDistance = 100.f;
}

int CPlayer::Update()
{

	__super::Update_Rect();

	Key_Input();

	return NOEVENT;
}
void CPlayer::Late_Update()
{
	m_tPosin.x = long(m_tInfo.fX + (m_fDistance * cosf(m_fAngle * (PI / 180.f))));
	m_tPosin.y = long(m_tInfo.fY - (m_fDistance * sinf(m_fAngle * (PI / 180.f))));
}



void CPlayer::Render(HDC hDC)
{
	Rectangle(hDC, 
		m_tRect.left, m_tRect.top, 
		m_tRect.right, m_tRect.bottom );


	MoveToEx(hDC, (int)m_tInfo.fX, (int)m_tInfo.fY, nullptr);
	LineTo(hDC, m_tPosin.x, m_tPosin.y);

}

void CPlayer::Release()
{
}

void CPlayer::Key_Input()
{
	if (GetAsyncKeyState(VK_RIGHT))
	{
		//m_tInfo.fX += m_fSpeed;

		m_fAngle += 5.f;
	}

	if (GetAsyncKeyState(VK_LEFT))
	{
// 		m_tInfo.fX -= m_fSpeed;

		m_fAngle -= 5.f;
	}

	 if (GetAsyncKeyState(VK_UP))
	 {
		m_tInfo.fX += m_fSpeed * cosf(m_fAngle * (PI / 180.f));
	 	m_tInfo.fY -= m_fSpeed * sinf(m_fAngle * (PI / 180.f));
	 }
	 
	 if (GetAsyncKeyState(VK_DOWN))
	 {
		 m_tInfo.fX += -m_fSpeed * cosf(m_fAngle * (PI / 180.f));
		 m_tInfo.fY -= -m_fSpeed * sinf(m_fAngle * (PI / 180.f));
	 }
	 
	 if (GetAsyncKeyState(VK_SPACE))
	 {
	 	m_pBullet->push_back(Create_Bullet(m_fAngle));
	 
	 }
	// 
	// if (GetAsyncKeyState('W'))
	// {
	// 	m_pBullet->push_back(CAbstractFactory<CBullet>
	// 		::Create_Obj(m_tInfo.fX, m_tInfo.fY, DIR_UP));	
	// }
	// 
	// if (GetAsyncKeyState('A'))
	// {
	// 	m_pBullet->push_back(Create_Bullet(DIR_LEFT));
	// }
	// 
	// if (GetAsyncKeyState('D'))
	// {
	// 	m_pBullet->push_back(Create_Bullet(DIR_RIGHT));
	// }
	// 
	// if (GetAsyncKeyState('S'))
	// {
	// 	m_pBullet->push_back(Create_Bullet(DIR_DOWN));
	// }

}

CObj* CPlayer::Create_Bullet(float fAngle)
{
	CObj* pBullet = new CBullet;

	pBullet->Initialize();
	pBullet->Set_Pos((float)m_tPosin.x, (float)m_tPosin.y);
	pBullet->Set_Angle(fAngle);

	return pBullet;
}

