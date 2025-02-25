#pragma once

#include "CObj.h"

class CPlayer : public CObj
{
public:
	enum JOBINDEX { WARRIOR = 1, MAGE, THIEF, JOB_END };

public:
	CPlayer();
	virtual ~CPlayer();

public:
	void		Set_Hp(int _iHp) { m_tInfo.iHp = _iHp; }
	void		Select_Job();
};

