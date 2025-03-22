#pragma once

#include "CObj.h"

template<typename T>
class CAbstractFactory
{
public:
	CAbstractFactory() {}
	~CAbstractFactory(){}

public:
	static CObj* Create_Obj(float _fX, float _fY, float _fCX, float _fCY, DIAGRAM _tDiag)
	{
		CObj* pObj = new T;
		pObj->Initialize();
		pObj->Set_Pos(_fX, _fY);
		pObj->Set_Size(_fCX, _fCY);
		pObj->Set_Diag(_tDiag);
		return pObj;
	}
};

