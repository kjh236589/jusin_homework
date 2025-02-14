#pragma once
#include "Define.h"
#include "CPlayer.h"

class CObject
{
public:
	CObject();
	~CObject();
	void Initialize();
	void Update();
	void Release();
	bool Damage(int iDmg);
private:
	INFO* pObject;
};

