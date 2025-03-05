#pragma once
#include "CObj.h"
class CMonster : public CObj
{
public:
	CMonster(const char* sName, int iHp, int iAtk);
	~CMonster();
};

