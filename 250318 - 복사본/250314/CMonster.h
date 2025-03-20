#pragma once
#include "CObj.h"
#include "CPlayer.h"
class CMonster :   public CObj
{
public:
	CMonster();
	virtual ~CMonster();

public:
	void Initialize() override;
	int Update() override;
	void Late_Update() override;
	void Render(HDC hDC) override;
	void Release() override;
	void Set_Collision(CObj* p_obj) override;
	void Set_Player(CPlayer* _player);
private:
	bool b_jump;
	CPlayer* p_Player;
};

