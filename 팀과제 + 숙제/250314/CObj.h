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
	DIAGRAM Get_Diagram() { return m_tdiagram; }

	void		Set_Pos(float _fX, float _fY)
	{
		m_tInfo.fX = _fX;
		m_tInfo.fY = _fY;
	}

	void		Set_Size(float _fCX, float _fCY)
	{
		m_tInfo.fCX = _fCX;
		m_tInfo.fCY = _fCY;
	}

	void		Set_Diag(DIAGRAM _tdiagram)
	{
		m_tdiagram = _tdiagram;
	}

public:
	virtual void		Initialize()PURE;
	virtual int		Update()PURE;
	virtual void		Late_Update()PURE;	// UPDATE 연산이 끝난 이후
	virtual void		Render(HDC hDC);
	virtual void		Release()PURE;
	virtual void		Set_Collision(CObj* p_obj) { m_bDead = true; };
public:
	void		Update_Rect();

protected:
	INFO m_tInfo;
	RECT m_tRect;
	DIAGRAM m_tdiagram;

	float m_fSpeed;
	float m_fGravity;
	bool m_bDead;

};

