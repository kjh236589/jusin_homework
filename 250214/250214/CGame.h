#pragma once
#include "Define.h"

class CObject;

class CGame
{
public:
	CGame();
	~CGame();
	void		Initialize();
	void		Update();
	void		Release();
	void		Game();
	void		Fight();
private:
	CObject* pPlayer;
	CObject* pMonster;
};

