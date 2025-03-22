#pragma once

#include "Define.h"

class CObj
{
public:
	CObj();
	virtual ~CObj();

public:
	const INFO* Get_Info() { return &m_tInfo; }
	const RECT* Get_Rect() { return &m_tRect; }

	void		Set_Pos(float _fX, float _fY)
	{
		m_tInfo.fX = _fX;
		m_tInfo.fY = _fY;
	}

	void		Set_Direction(DIRECTION eDir) { m_eDir = eDir; }
	void		Set_Dead() { m_bDead = true; }
	void		Set_Angle(float _fAngle) { m_fAngle = _fAngle; }

public:
	virtual void	Initialize()PURE;
	virtual int		Update()PURE;
	virtual void	Late_Update()PURE;	// UPDATE 연산이 끝난 이후
	virtual void	Render(HDC hDC)PURE;
	virtual void	Release()PURE;

public:
	void		Update_Rect();

protected:
	INFO		m_tInfo;
	RECT		m_tRect;
	DIRECTION	m_eDir;

	float		m_fSpeed;
	float		m_fDistance;
	float		m_fAngle;
	bool		m_bDead;

};

