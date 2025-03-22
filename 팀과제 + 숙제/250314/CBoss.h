#pragma once
#include "CMonster.h"
class CBoss : public CMonster
{
public:
	CBoss();
	~CBoss();
	void Initialize() override;
	int Update() override;
	void Late_Update() override;
	void Render(HDC hDC) override;
	void Release() override;
private:
	CObj* Create_CircleBullet(float _fSize, float _fSpeed, int _iDamage);
};

