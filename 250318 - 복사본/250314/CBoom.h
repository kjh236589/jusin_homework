#pragma once
#include "CBullet.h"
class CBoom : public CBullet
{
public:
	CBoom();
	virtual ~CBoom();

public:
	void Initialize() override;
	int Update() override;
	void Set_Collision(CObj* p_obj) override;
};