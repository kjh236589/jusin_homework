#pragma once
#include "CObj.h"

class CInventory;

class CPlayer : public CObj
{
public:
	CPlayer(string szName, int iHp, int iAtk);
	~CPlayer();
	void Initialize();
	void Print();
	bool Damage(OBJ enemy);
	void Reset();
	void OpenInventory();
	void Heal(int iHeal);
	void SetWeapone(vector<ITEM>::iterator iter);
	void SetArmor(vector<ITEM>::iterator iter);
	vector<ITEM>& GetInventory();
private:
	int iDef;
	int iMaxHp;
	CInventory* m_pInventory;
	ITEM* iWeapone;
	ITEM* iArmor;
};