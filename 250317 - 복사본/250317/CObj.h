#pragma once

#include "Define.h"

class CObj
{
public:
	CObj();
	virtual ~CObj();

public:
	const INFO* Get_Info() { return &m_tInfo; }
	const RECT* Get_RECT() { return &m_tRect; }

public:
	virtual void	Initialize()PURE;
	virtual void	Update()PURE;
	virtual void	Render(HDC hDC)PURE;
	virtual void	Release()PURE;
	void SetRemove();
	bool GetRemove();
public:
	void		Update_Rect();

protected:
	INFO		m_tInfo;
	RECT		m_tRect;

	float		m_fSpeed;
	bool remove;
};

