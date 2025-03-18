#include "pch.h"
#include "CMainGame.h"
#include "CMonster.h"

CMainGame::CMainGame() : m_pPlayer(nullptr), m_pMonster(nullptr), rc({})
{
}

CMainGame::~CMainGame()
{
	Release();
}

void CMainGame::Initialize()
{
	m_hDC = GetDC(g_hWnd);

	if (!m_pPlayer)
	{
		m_pPlayer = new CPlayer;
		m_pPlayer->Initialize();
		dynamic_cast<CPlayer*>(m_pPlayer)->SetList(&m_BulletList);
	}
	if (!m_pMonster) {
		m_pMonster = new CMonster;
		m_pMonster->Initialize();
	}

}

void CMainGame::Update()
{
	m_pPlayer->Update();
	if (m_pMonster) {
		m_pMonster->Update();
		float x = pow(m_pPlayer->Get_Info()->fX - m_pMonster->Get_Info()->fX , 2);
		float y = pow(m_pPlayer->Get_Info()->fY - m_pMonster->Get_Info()->fY, 2);
		float z = sqrtf(x + y);
		if (z <= (m_pPlayer->Get_Info()->fCX / 2) + (m_pMonster->Get_Info()->fCX / 2)) {
			Safe_Delete<CObj*>(m_pMonster);
		}
	}
	for (auto& Bullet : m_BulletList) {
		Bullet->Update();
		if (m_pMonster && IntersectRect(&rc, m_pMonster->Get_RECT(), Bullet->Get_RECT())) {
			Safe_Delete<CObj*>(m_pMonster);
			Bullet->SetRemove();
		}
	}
	m_BulletList.remove_if([](CObj* Bullet)->bool {
		if (Bullet->GetRemove()) {
			Safe_Delete<CObj*>(Bullet);
			return true;
		}return false; });
}

void CMainGame::Render()
{
	Rectangle(m_hDC, 0, 0, WINCX, WINCY);
	Rectangle(m_hDC, 100, 100, WINCX - 100, WINCY - 100);

	for (auto Bullet : m_BulletList) {
		Bullet->Render(m_hDC);
	}
	m_pPlayer->Render(m_hDC);
	if (m_pMonster) {
		m_pMonster->Render(m_hDC);
	}
}

void CMainGame::Release()
{

	Safe_Delete<CObj*>(m_pPlayer);
	Safe_Delete<CObj*>(m_pMonster);
	for_each(m_BulletList.begin(), m_BulletList.end(), Safe_Delete<CObj*>);
	m_BulletList.clear();
	ReleaseDC(g_hWnd, m_hDC);
}
