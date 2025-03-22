#pragma once

#include "CObj.h"

class CCollisionMgr
{
public:
	static bool	Collision_Rect(list<CObj*> DstList, list<CObj*> SrcList);
	static bool	Collision_Circle(list<CObj*> DstList, list<CObj*> SrcList);
	static bool Check_Circle(CObj* pDst, CObj* pSrc);

};

