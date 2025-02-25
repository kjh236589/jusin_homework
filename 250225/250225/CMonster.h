#pragma once

#include "CObj.h"

class CMonster : public CObj
{
public:
	virtual void		Set_Hp(int _iHp) {}
	virtual void		Select_Job() {}

public:
	CMonster();
	CMonster(const char* pName, int _iHp, int _iAttack);
	virtual~CMonster();
};

