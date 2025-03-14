#include "pch.h"
#include "CMainGame.h"

CMainGame::CMainGame()
{
}

CMainGame::~CMainGame()
{
	Release();
}

void CMainGame::Initialize()
{
	m_hDC = GetDC(g_hWnd);
	rc = { 100, 100, 200, 200 };
	Rectangle(m_hDC, rc.left, rc.top, rc.right, rc.bottom);
}

void CMainGame::Update()
{
	Rectangle(m_hDC, -1, -1, WINCX + 1, WINCY + 1);
	if (GetAsyncKeyState(VK_LEFT) && 0 < rc.left) {
		rc.left -= 10;
		rc.right -= 10;
	}
	if (GetAsyncKeyState(VK_RIGHT) && rc.right < WINCX) {
		rc.left += 10;
		rc.right += 10;
	}
	if (GetAsyncKeyState(VK_UP) && 0 < rc.top) {
		rc.top -= 10;
		rc.bottom -= 10;
	}
	if (GetAsyncKeyState(VK_DOWN) && rc.bottom < WINCY) {
		rc.top += 10;
		rc.bottom += 10;
	}
	if (GetAsyncKeyState(VK_SPACE)) {
		BulletList.push_back({ rc.left + 40, rc.top - 20, rc.right - 40, rc.top });
	}
	for (auto& Bullet : BulletList) {
		Ellipse(m_hDC, Bullet.left, Bullet.top, Bullet.right, Bullet.bottom);
		Bullet.top -= 20;
		Bullet.bottom -= 20;
	}
	Rectangle(m_hDC, rc.left, rc.top, rc.right, rc.bottom);
}

void CMainGame::Render()
{
}

void CMainGame::Release()
{
	ReleaseDC(g_hWnd, m_hDC);
}
