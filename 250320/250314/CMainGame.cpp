#include "pch.h"
#include "CMainGame.h"
#include "CMonster.h"
#include "CAbstractFactory.h"
#include "CCollisionMgr.h"
#include "CMouse.h"

CMainGame::CMainGame() :m_dwTime(GetTickCount64()), m_iFPS(0)
{
	ZeroMemory(m_szFPS, sizeof(m_szFPS));
}

CMainGame::~CMainGame()
{
	Release();
}

void CMainGame::Initialize()
{
	m_hDC = GetDC(g_hWnd);

	m_ObjList[OBJ_PLAYER].push_back(CAbstractFactory<CPlayer>::Create_Obj());
	dynamic_cast<CPlayer*>(m_ObjList[OBJ_PLAYER].front())->Set_BulletList(&m_ObjList[OBJ_BULLET]);

	// m_pPlayer = CAbstractFactory<CPlayer>::Create_Obj();
	// dynamic_cast<CPlayer*>(m_pPlayer)->Set_BulletList(&m_BulletList);

	for (int i = 0; i < 3; ++i)
	{
		m_ObjList[OBJ_MONSTER].push_back(CAbstractFactory<CMonster>::Create_Obj(150.f, (i + 1) * 140.f));
	}

	m_ObjList[OBJ_MOUSE].push_back(CAbstractFactory<CMouse>::Create_Obj());
}

void CMainGame::Update()
{
	// m_pPlayer->Update();
	// 
	// for (auto& pBullet : m_BulletList)
	// 	pBullet->Update();

	for (size_t i = 0; i < OBJ_END; ++i)
	{
		for (auto iter = m_ObjList[i].begin();
			iter != m_ObjList[i].end(); )
		{
			int iResult = (*iter)->Update();

			if (DEAD == iResult)
			{
				Safe_Delete<CObj*>(*iter);
				iter = m_ObjList[i].erase(iter);
			}
			else
			{
				++iter;
			}
		}
	}


}

void CMainGame::Late_Update()
{
	for (size_t i = 0; i < OBJ_END; ++i)
	{
		for (auto iter = m_ObjList[i].begin();
			iter != m_ObjList[i].end(); ++iter)
		{
			(*iter)->Late_Update();
		}
	}
	CCollisionMgr::Collision_Circle(m_ObjList[OBJ_MOUSE], m_ObjList[OBJ_MONSTER]);
	CCollisionMgr::Collision_Rect(m_ObjList[OBJ_BULLET], m_ObjList[OBJ_MONSTER]);

}

void CMainGame::Render()
{
	m_iFPS++;

	if (m_dwTime + 1000 < GetTickCount64())
	{
		swprintf_s(m_szFPS, L"FPS : %d", m_iFPS);
		
		SetWindowText(g_hWnd, m_szFPS);

		m_iFPS = 0;
		m_dwTime = GetTickCount64();
	}



	//////////////////////////////////////
	Rectangle(m_hDC, 0, 0, WINCX, WINCY);
	Rectangle(m_hDC, 100, 100, WINCX - 100, WINCY - 100);

	for (size_t i = 0; i < OBJ_END; ++i)
	{
		for (auto iter = m_ObjList[i].begin();
			iter != m_ObjList[i].end(); ++iter)
		{
			(*iter)->Render(m_hDC);
		}
	}

	//m_pPlayer->Render(m_hDC);
	//
	//for (auto& pBullet : m_BulletList)
	//	pBullet->Render(m_hDC);

	// 문자열 출력

	TCHAR	szName[32] = L"";

	// wsprintf(szName, L"Bullet : %d", m_BulletList.size()); // 정수만 출력 가능

	swprintf_s(szName, L"Bullet : %f", 3.14f);
	TextOut(m_hDC, 100, 100, szName, lstrlen(szName));

	//RECT	rc{ 300, 300, 350, 350 };
	//
	//DrawText(m_hDC, szName, lstrlen(szName), &rc, DT_CENTER);

}

void CMainGame::Release()
{

	//for (size_t i = 0; i < OBJ_END; ++i)Safe_Delete<CObj*>(m_pPlayer);
	//	{
	//		for (auto iter = m_ObjList[i].begin();for_each(m_BulletList.begin(), m_BulletList.end(), Safe_Delete<CObj*>);
	//			iter != m_ObjList[i].end(); ++iter)m_BulletList.clear();


	for (size_t i = 0; i < OBJ_END; ++i)
	{
		for_each(m_ObjList[i].begin(), m_ObjList[i].end(), Safe_Delete<CObj*>);
		m_ObjList[i].clear();
	}


	ReleaseDC(g_hWnd, m_hDC);
}
