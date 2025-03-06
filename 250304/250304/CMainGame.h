#pragma once
#include "CPlayer.h"
#include "CMonster.h"
#include "CShop.h"

class CMainGame
{
public:
	CMainGame();
	~CMainGame();
	void Initialize();
	void Update();
	void Release();
	void Start();
	void Adventure();
	void Shop();
	void Fight();
private:
	CPlayer* m_pPlayer;
	CMonster* m_pMonster;
	CShop* m_pShop;
	GAME Game;
};