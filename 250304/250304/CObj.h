#pragma once
#include "pch.h"
#include "Define.h"
class CObj
{
public:
	CObj();
	CObj(string szName, int iHp, int iAtk);
	~CObj();
	virtual void Print();
	virtual bool Damage(OBJ enemy);
	OBJ& GetObj();
protected:
	OBJ obj;
};

