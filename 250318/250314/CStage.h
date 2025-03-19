#pragma once
#include "CObj.h"
class CStage : public CObj
{
public:
	CStage();
	virtual ~CStage();

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

