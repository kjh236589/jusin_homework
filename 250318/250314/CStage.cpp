#include "pch.h"
#include "CStage.h"

CStage::CStage()
{
}

CStage::~CStage()
{
	Release();
}

void CStage::Initialize()
{
	m_tInfo.fCX = 600.f;
	m_tInfo.fCY = 40.f;
}

int CStage::Update()
{
	__super::Update_Rect();
	return 0;
}

void CStage::Late_Update()
{
}

void CStage::Render(HDC hDC)
{
	Rectangle(hDC,
		m_tRect.left, m_tRect.top,
		m_tRect.right, m_tRect.bottom);
}

void CStage::Release()
{
}

void CStage::Set_Collision(CObj* p_obj)
{
}
