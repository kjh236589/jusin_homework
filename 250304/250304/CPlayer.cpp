#include "pch.h"
#include "CPlayer.h"
#include "CInventory.h"

CPlayer::CPlayer(string szName, int iHp, int iAtk) : CObj(szName, iHp, iAtk)
{
	iMaxHp = iHp;
	iDef = 0;
	iWeapone = nullptr;
	iArmor = nullptr;
	m_pInventory = nullptr;
}

CPlayer::~CPlayer()
{
}

void CPlayer::Initialize()
{
	m_pInventory = new CInventory();
	m_pInventory->Initialize(this);
}

void CPlayer::Print() {
	cout << "이름 : " << obj.szName << endl << "HP : " << obj.iHp << endl << "공격력 : " << obj.iAtk << endl << "방어력 : " << iDef << endl << "==================================" << endl;
}

bool CPlayer::Damage(OBJ enemy) {
	int iDamage(enemy.iAtk - iDef);
	if (0 < iDamage) {
		obj.iHp -= enemy.iAtk;
		if (0 >= obj.iHp) {
			Reset();
			return true;
		}
	}
	return false;
}

void CPlayer::Reset()
{
	obj.iHp = iMaxHp;
}

void CPlayer::OpenInventory()
{
	m_pInventory->Update();
}

void CPlayer::Heal(int iHeal)
{
	if (obj.iHp + iHeal >= iMaxHp) {
		Reset();
	}
	else {
		obj.iHp += iHeal;
	}
}

void CPlayer::SetWeapone(vector<ITEM>::iterator iter)
{
	if (iWeapone != nullptr) {
		obj.iAtk -= iWeapone->iStat;
		swap(*iWeapone, *iter);
	}
	else {
		iWeapone = new ITEM;
		*iWeapone = *iter;
		GetInventory().erase(iter);
	}
	obj.iAtk += iWeapone->iStat;
}

void CPlayer::SetArmor(vector<ITEM>::iterator iter)
{
	if (iArmor != nullptr) {
		iDef -= iArmor->iStat;
		swap(*iArmor, *iter);
	}
	else {
		iArmor = new ITEM;
		*iArmor = *iter;
		GetInventory().erase(iter);
	}
	iDef += iArmor->iStat;
}

vector<ITEM>& CPlayer::GetInventory()
{
	return m_pInventory->GetInventory();
}
