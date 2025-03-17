#pragma once

#include "Define.h"
#include "CPlayer.h"

class CMainGame
{
public:
	CMainGame();
	~CMainGame();

public:
	void		Initialize();
	void		Update();
	void		Render();
	void		Release();

private:
	HDC		m_hDC;
	CObj* m_pPlayer;
	list<CObj*> m_BulletList;
	CObj* m_pMonster;
	RECT rc;
};

// GetAsyncKeyState() 키 처리 함수