#pragma once
#include "CObj.h"
class CBullet :  public CObj
{
public:
	CBullet();
	virtual ~CBullet();

public:
	void Initialize() override;
	int Update() override;
	void Late_Update() override;
	//void Render(HDC hDC) override;
	void Release() override;
	void Set_Collision(CObj* p_obj) override;
	//void SetMonsterList(list<CObj*>* _monsterList);
	//float Get_Line(CObj* _monster);
	void Set_Damage(int _iDamage) { i_Damage = _iDamage; }
	virtual void SetSpeed(float _x, float _y);
	virtual int Get_Damage() { return i_Damage; }
protected:
	float m_fYSpeed;
	int angle, i_Damage;
	//list<CObj*>* monsterList;
	//CObj* monster;
};