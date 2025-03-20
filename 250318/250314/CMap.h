#pragma once
#include "CObj.h"
class CMap : public CObj
{
public:
	CMap();
	virtual ~CMap();

public:
	void Initialize() override;
	int Update() override;
	void Late_Update() override;
	void Render(HDC hDC) override;
	void Release() override;
	void Set_Collision(CObj* p_obj) override;
private:
	bool b_jump;
};

