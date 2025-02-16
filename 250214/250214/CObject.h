#pragma once
#include "Define.h"

class CObject
{
public:
	CObject();
	~CObject();
	void Initialize();
	void Update();
	void Release();
	void Reset();
	void Print();
	void Save();
	bool Load();
	bool CreatePlayer();
	bool CreateMonster();
	bool Damage(int iDmg);
	int GetDamage();
private:
	INFO* pObject;
};

