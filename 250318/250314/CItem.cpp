#include "pch.h"
#include "CItem.h"
#include "CStage.h"
#include "CPlayer.h"

CItem::CItem() : item(MACHINEGUN), Bullets(200)
{
}

CItem::~CItem()
{
}

void CItem::Initialize()
{
	m_tInfo.fCX = 50.f;
	m_tInfo.fCY = 50.f;
	m_fGravity = 0.1f;
	m_tdiagram = CIRCLE;
}

int CItem::Update()
{
	if (m_bDead) {
		return DEAD;
	}

	__super::Update_Rect();

	m_tInfo.fY += m_fGravity;
	if (0.f < m_fGravity) {
		m_fGravity += 0.1f;
	}

	return NOEVENT;
}

void CItem::Late_Update()
{
}

void CItem::Render(HDC hDC)
{
	Ellipse(hDC,
		m_tRect.left, m_tRect.top,
		m_tRect.right, m_tRect.bottom);
}

void CItem::Release()
{
}

void CItem::Set_Collision(CObj* p_obj)
{
	if (nullptr != dynamic_cast<CStage*>(p_obj)) {
		if (0.f < m_fGravity && m_tRect.bottom >= p_obj->Get_Rect()->top && m_tRect.bottom - (m_fGravity * 2.f) <= p_obj->Get_Rect()->top) {
			m_tInfo.fY = (p_obj->Get_Rect()->top) - (m_tInfo.fCY / 2.f) + 1;
			m_fGravity = 0.f;
		}
	}
	else if(nullptr != dynamic_cast<CPlayer*>(p_obj)){
		m_bDead = true;
		dynamic_cast<CPlayer*>(p_obj)->Set_Item(item, Bullets);
	}
}
