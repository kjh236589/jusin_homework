#include "pch.h"
#include "CCollisionMgr.h"

bool CCollisionMgr::Collision_Rect(list<CObj*> DstList, list<CObj*> SrcList)
{
	RECT	rc{};

	for (auto& Dst : DstList)
	{
		for (auto& Src : SrcList)
		{
			if (IntersectRect(&rc, Dst->Get_Rect(), Src->Get_Rect()))
			{
				Dst->Set_Collision(Src);
				Src->Set_Collision(Dst);
			}
		}
	}




	return false;
}
