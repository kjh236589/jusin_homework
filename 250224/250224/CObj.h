#pragma once

#include "Define.h"

class CObj
{
public:
	CObj();
	CObj(const char* pName, int _iHp, int _iAttack);
	~CObj();

public:
	void		Set_Damage(int _iAttack) { m_tInfo.iHp -= _iAttack; }
	INFO		Get_Info() { return m_tInfo; }

public:
	void	 Render();
	virtual void Set_Hp(int _iHp);
	virtual void	 Select_Job();

protected:
	INFO	m_tInfo;

};

