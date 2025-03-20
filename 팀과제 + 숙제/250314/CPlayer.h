#pragma once
#include "CObj.h"
class CPlayer :   public CObj
{
public:
	CPlayer();
	virtual ~CPlayer();

public:
	void		Set_BulletList(list<CObj*>* pBullet)
	{
		m_pBullet = pBullet;
	}

public:
	void Initialize() override;
	int Update() override;
	void Late_Update() override;
	void Render(HDC hDC) override;
	void Release() override;
	void Set_Collision(CObj* p_obj) override;
	void Set_Item(ITEM _item, int _bullets);

private:
	void	Key_Input();
	void Update_Angle();
	CObj* Create_Bullet();
	int angle, angle2, boom, bullets;
	float theta, gunX, gunY;
	bool left, b_jump;
	ITEM item;
	ULONG64   coolTime;
	ULONG64   boomCoolTime;

private:
	list<CObj*>*			m_pBullet;
};

