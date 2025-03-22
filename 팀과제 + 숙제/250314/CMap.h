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
	void Release() override;
	void Set_Pass(bool _bPass) { b_Pass = _bPass; }
	bool Get_Pass() { return b_Pass; }
private:
	bool b_Pass;
};

