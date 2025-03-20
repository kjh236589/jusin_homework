#include "pch.h"
#include "CMap.h"

CMap::CMap()
{
}

CMap::~CMap()
{
	Release();
}

void CMap::Initialize()
{
	m_tInfo.fCX = 600.f;
	m_tInfo.fCY = 40.f;
}

int CMap::Update()
{
	__super::Update_Rect();
	return 0;
}

void CMap::Late_Update()
{
}

void CMap::Render(HDC hDC)
{
	Rectangle(hDC,
		m_tRect.left, m_tRect.top,
		m_tRect.right, m_tRect.bottom);
}

void CMap::Release()
{
}

void CMap::Set_Collision(CObj* p_obj)
{
}
