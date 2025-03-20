#include "pch.h"
#include "CCollisionMgr.h"

bool CCollisionMgr::Collision_Rect(list<CObj*> DstList, list<CObj*> SrcList)
{
	RECT	rc{};

	for (auto& Dst : DstList)
	{
		for (auto& Src : SrcList)
		{
			if (Dst->Get_Diagram() == RECTANGLE) {
				if (Src->Get_Diagram() == RECTANGLE) {
					if (IntersectRect(&rc, Dst->Get_Rect(), Src->Get_Rect()))
					{
						Dst->Set_Collision(Src);
						Src->Set_Collision(Dst);
					}
				}
				else
				{
					if (IntersectRect(&rc, Dst->Get_Rect(), Src->Get_Rect()))
					{
						Dst->Set_Collision(Src);
						Src->Set_Collision(Dst);
					}
				}
			}
			else {
				if (Src->Get_Diagram() == RECTANGLE) {
					if (IntersectRect(&rc, Dst->Get_Rect(), Src->Get_Rect()))
					{
						Dst->Set_Collision(Src);
						Src->Set_Collision(Dst);
					}
				}
				else if (sqrtf(powf(Dst->Get_Info()->fX - Src->Get_Info()->fX, 2) + powf(Dst->Get_Info()->fY - Src->Get_Info()->fY, 2)) <= (Dst->Get_Info()->fCX + Src->Get_Info()->fCX) * 0.5f) {
					Dst->Set_Collision(Src);
					Src->Set_Collision(Dst);
				}
			}
		}
	}




	return false;
}
