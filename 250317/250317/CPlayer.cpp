#include "pch.h"
#include "CPlayer.h"

CPlayer::CPlayer() : m_pBulletList(nullptr), m_dwTime(GetTickCount64())
{
}

CPlayer::~CPlayer()
{
	Release();
}

void CPlayer::Initialize()
{
	m_tInfo = { WINCX / 2.f, WINCY / 2.f, 100.f, 100.f };
	m_fSpeed = 10.f;
}

void CPlayer::Update()
{

	__super::Update_Rect();

	Key_Input();

}

void CPlayer::Render(HDC hDC)
{
	Rectangle(hDC, 
		m_tRect.left, m_tRect.top, 
		m_tRect.right, m_tRect.bottom );
}

void CPlayer::Release()
{
}

void CPlayer::SetList(list<CObj*>* _bulletList)
{
	m_pBulletList = _bulletList;
}

void CPlayer::Key_Input()
{
	if (GetAsyncKeyState(VK_RIGHT))
	{
		m_tInfo.fX += m_fSpeed;
	}

	if (GetAsyncKeyState(VK_LEFT))
	{
		m_tInfo.fX -= m_fSpeed;
	}

	if (GetAsyncKeyState(VK_UP))
	{
		m_tInfo.fY -= m_fSpeed;
	}

	if (GetAsyncKeyState(VK_DOWN))
	{
		m_tInfo.fY += m_fSpeed;
	}
	if (m_dwTime + 500 < GetTickCount64()) {
		if (GetAsyncKeyState('A')) {
			m_pBulletList->push_back(Create_Bullet(-10.f, 0.f));
		}
		else if (GetAsyncKeyState('D')) {
			m_pBulletList->push_back(Create_Bullet(10.f, 0.f));
		}
		else if (GetAsyncKeyState('W')) {
			m_pBulletList->push_back(Create_Bullet(0.f, -10.f));
		}
		else if (GetAsyncKeyState('S')) {
			m_pBulletList->push_back(Create_Bullet(0.f, 10.f));
		}
	}

}

CObj* CPlayer::Create_Bullet(float _fX, float _fY)
{

	m_dwTime = GetTickCount64();
	CObj* pBullet = new CBullet;

	pBullet->Initialize();
	dynamic_cast<CBullet*>(pBullet)->SetPos(m_tInfo.fX, m_tInfo.fY);
	dynamic_cast<CBullet*>(pBullet)->SetSpeed(_fX, _fY);

	return pBullet;
}

