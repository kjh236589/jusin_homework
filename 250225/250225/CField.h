#pragma once

#include "CPlayer.h"
#include "CMonster.h"

class CField
{
public:
	CField();
	~CField();

public:
	void	Set_Player(CObj* pCopyPlayer)
	{
		m_pCopyPlayer = pCopyPlayer;
	}

public:
	void	Initialize();
	void	Update();
	void	Release();

private:
	int		Fight();

private:
	CObj* m_pCopyPlayer;
	CObj* m_pMonster;
};

