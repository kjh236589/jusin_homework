#pragma once
#include "CBullet.h"
class CCircleBullet : public CBullet
{
public:
	CCircleBullet();
	virtual ~CCircleBullet();
public:
	int Update() override;
	virtual void SetSpeed(float _x, float _y);
private:
	INFO info;
	float m_fAngle;
};

