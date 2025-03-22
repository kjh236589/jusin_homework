#include "pch.h"
#include "CMainGame.h"
#include "CMonster.h"
#include "CBoss.h"
#include "CMap.h"
#include "CItem.h"
#include "CAbstractFactory.h"
#include "CCollisionMgr.h"

CMainGame::CMainGame() :m_dwTime(GetTickCount64()), m_iFPS(0), game(0), i_Coin(3)
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
	for (size_t i = 0; i < 3; ++i)
	{
		m_ObjList[i][OBJ_PLAYER].push_back(CAbstractFactory<CPlayer>::Create_Obj(600.f, WINCY - 100.f, 100.f, 100.f, CIRCLE));

		m_ObjList[i][OBJ_MAP].push_back(Create_Map(WINCX / 2.f, WINCY - 20.f, WINCX, 40.f, false));
		//m_ObjList[i][OBJ_MAP].push_back(Create_Map(WINCX / 4.f, WINCY - 210.f, WINCX / 2.f, 20.f, true));
		//m_ObjList[i][OBJ_MAP].push_back(Create_Map(WINCX / 6.f, WINCY - 100.f, WINCX / 3.f, 20.f, true));
		//m_ObjList[i][OBJ_MAP].push_back(Create_Map(WINCX / 4.f, WINCY - 210.f, WINCX / 2.f, 20.f, true));
		m_ObjList[i][OBJ_MAP].push_back(Create_Map((WINCX / 4.f) * 3.f, WINCY - 200.f, WINCX / 2.f, 40.f, true));

		m_ObjList[i][OBJ_ITEM].push_back(CAbstractFactory<CItem>::Create_Obj(WINCX - 25.f, 100.f, 50.f, 50.f, CIRCLE));
		dynamic_cast<CPlayer*>(m_ObjList[i][OBJ_PLAYER].front())->Set_BulletList(&m_ObjList[i][OBJ_BULLET]);

		m_ObjList[i][OBJ_MONSTER].push_back(CAbstractFactory<CBoss>::Create_Obj(100.f, 150.f, 200.f, 100.f, RECTANGLE));
		dynamic_cast<CMonster*>(m_ObjList[i][OBJ_MONSTER].front())->Set_BulletList(&m_ObjList[i][OBJ_BULLET]);

		//for (int j = 0; j < 3; ++j)
		//{
		//	m_ObjList[i][OBJ_MONSTER].push_back(CAbstractFactory<CBoss>::Create_Obj((j + 1) * 150.f, (j + 1) * 140.f, 60.f, 60.f, CIRCLE));
		//}
		//dynamic_cast<CPlayer*>(m_ObjList[i][OBJ_PLAYER].front())->Set_Monster(&m_ObjList[i][OBJ_MONSTER]);

		for (auto iter = m_ObjList[i][OBJ_MONSTER].begin();
			iter != m_ObjList[i][OBJ_MONSTER].end(); ++iter)
		{
			dynamic_cast<CMonster*>(*iter)->Set_Player(dynamic_cast<CPlayer*>(m_ObjList[i][OBJ_PLAYER].front()));
		}
	}

}

void CMainGame::Update()
{
	if (GetAsyncKeyState('1'))
	{
		game = 0;
	}
	if (GetAsyncKeyState('2'))
	{
		game = 1;
	}
	if (GetAsyncKeyState('3'))
	{
		game = 2;
	}
	if (0 == m_ObjList[game][OBJ_PLAYER].size()) {
		if (0 < i_Coin--) {
			m_ObjList[game][OBJ_PLAYER].push_back(CAbstractFactory<CPlayer>::Create_Obj(600.f, WINCY - 100.f, 100.f, 100.f, CIRCLE));
			dynamic_cast<CPlayer*>(m_ObjList[game][OBJ_PLAYER].front())->Set_BulletList(&m_ObjList[game][OBJ_BULLET]);
			//dynamic_cast<CPlayer*>(m_ObjList[game][OBJ_PLAYER].front())->Set_Monster(&m_ObjList[game][OBJ_MONSTER]);
			for (auto iter = m_ObjList[game][OBJ_MONSTER].begin();
				iter != m_ObjList[game][OBJ_MONSTER].end(); ++iter)
			{
				dynamic_cast<CMonster*>(*iter)->Set_Player(dynamic_cast<CPlayer*>(m_ObjList[game][OBJ_PLAYER].front()));
			}
		}
		else {
			for (auto iter = m_ObjList[game][OBJ_MONSTER].begin();
				iter != m_ObjList[game][OBJ_MONSTER].end(); ++iter)
			{
				dynamic_cast<CMonster*>(*iter)->Set_Player(nullptr);
			}
		}
	}
	for (size_t i = 0; i < OBJ_END; ++i)
	{
		for (auto iter = m_ObjList[game][i].begin();
			iter != m_ObjList[game][i].end(); )
		{
			int iResult = (*iter)->Update();

			if (DEAD == iResult)
			{
				Safe_Delete<CObj*>(*iter);
				iter = m_ObjList[game][i].erase(iter);
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
		for (auto iter = m_ObjList[game][i].begin();
			iter != m_ObjList[game][i].end(); ++iter)
		{
			(*iter)->Late_Update();
		}
	}
	CCollisionMgr::Collision_Rect(m_ObjList[game][OBJ_MONSTER], m_ObjList[game][OBJ_BULLET]);
		CCollisionMgr::Collision_Rect(m_ObjList[game][OBJ_PLAYER], m_ObjList[game][OBJ_BULLET]);
	CCollisionMgr::Collision_Rect(m_ObjList[game][OBJ_PLAYER], m_ObjList[game][OBJ_MAP]);
	CCollisionMgr::Collision_Rect(m_ObjList[game][OBJ_MONSTER], m_ObjList[game][OBJ_MAP]);
	CCollisionMgr::Collision_Rect(m_ObjList[game][OBJ_BULLET], m_ObjList[game][OBJ_MAP]);
	CCollisionMgr::Collision_Rect(m_ObjList[game][OBJ_MAP], m_ObjList[game][OBJ_ITEM]);
	CCollisionMgr::Collision_Rect(m_ObjList[game][OBJ_PLAYER], m_ObjList[game][OBJ_ITEM]);

}

void CMainGame::Render()
{
	Rectangle(m_hDC, 0, 0, WINCX, WINCY);
	if (0 <= i_Coin) {
		TCHAR	szName[32] = L"";
		swprintf_s(szName, L"Coin : %d", i_Coin);
		TextOut(m_hDC, 10, 50, szName, lstrlen(szName));
	}
	else {
		TCHAR	szName[32] = L"GAMEOVER";
		TextOut(m_hDC, 10, 50, szName, lstrlen(szName));
	}
	for (size_t i = 0; i < OBJ_END; ++i)
	{
		for (auto iter = m_ObjList[game][i].begin();
			iter != m_ObjList[game][i].end(); ++iter)
		{
			(*iter)->Render(m_hDC);
		}
	}
}

void CMainGame::Release()
{
	for (size_t i = 0; i < 3; ++i)
	{
		for (size_t j = 0; j < OBJ_END; ++j)
		{
			for_each(m_ObjList[i][j].begin(), m_ObjList[i][j].end(), Safe_Delete<CObj*>);
			m_ObjList[i][j].clear();
		}
	}
	ReleaseDC(g_hWnd, m_hDC);
}

CObj* CMainGame::Create_Map(float _fX, float _fY, float _fCX, float _fCY, bool _bPass)
{
	CObj* map = CAbstractFactory<CMap>::Create_Obj(_fX, _fY, _fCX, _fCY, RECTANGLE);
	dynamic_cast<CMap*>(map)->Set_Pass(_bPass);
	return map;
}
