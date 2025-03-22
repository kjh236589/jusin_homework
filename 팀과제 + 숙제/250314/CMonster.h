#pragma once
#include "CObj.h"
#include "CPlayer.h"
class CMonster :   public CObj
{
public:
	CMonster();
	virtual ~CMonster();

public:
	void		Set_BulletList(list<CObj*>* pBullet)
	{
		m_pBullet = pBullet;
	}
	void Initialize() override;
	int Update() override;
	void Late_Update() override;
	void Render(HDC hDC) override;
	void Release() override;
	void Set_Collision(CObj* p_obj) override;
	void Set_Player(CPlayer* _player);
	CObj* Create_Bullet(float _fSize, float _fSpeed, int _iDamage);
protected:
	bool b_jump, b_Damage;
	int i_Hp;
	float m_fAngle, m_fGunX, m_fGunY;
	list<CObj*>* m_pBullet;
	ULONGLONG f_DamageTime, f_CoolTime;
	CPlayer* p_Player;
};

