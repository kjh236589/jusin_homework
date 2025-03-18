#pragma once
#include "CObj.h"
#include "CBullet.h"

class CPlayer : public CObj
{
public:
	CPlayer();
	virtual ~CPlayer();

public:
	void Initialize() override;
	void Update() override;
	void Render(HDC hDC) override;
	void Release() override;
	void SetList(list<CObj*>* _bulletList);
private:
	void	 Key_Input();
	CObj* Create_Bullet(float _fX, float _fY);
	list<CObj*>* m_pBulletList;

	ULONGLONG		m_dwTime;
};