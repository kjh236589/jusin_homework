#pragma once
#include "Define.h"

class CObject;

class CPlayer
{
public:
	CPlayer();
	~CPlayer();
	void		Initialize();
	void		Update();
	void		Release();
private:
	CObject* pPlayer;
	CObject* pMonster;
};

