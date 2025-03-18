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
	void Late_Update() override;
	void Render(HDC hDC) override;
	void Release() override;
	void SetSpeed(float _x, float _y);
};