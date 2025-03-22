#pragma once
#include "CObj.h"
class CItem : public CObj {
public:
	CItem();
	virtual ~CItem();

public:
	void Initialize() override;
	int Update() override;
	void Late_Update() override;
	void Release() override;
	void Set_Collision(CObj* p_obj) override;
private:
	ITEM item;
	int Bullets;
};