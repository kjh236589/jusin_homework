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

private:
	void	Key_Input();
	CObj* Create_Bullet(float fAngle);

private:
	list<CObj*>*			m_pBullet;
	POINT					m_tPosin;
};

