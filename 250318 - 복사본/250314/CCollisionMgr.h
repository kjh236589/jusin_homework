#pragma once

#include "CObj.h"

class CCollisionMgr
{
public:
	static bool	Collision_Rect(list<CObj*> DstList, list<CObj*> SrcList);
};