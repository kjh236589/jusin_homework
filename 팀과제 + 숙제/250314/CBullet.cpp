#include "pch.h"
#include "CBullet.h"
#include "CMap.h"
#include "CMonster.h"
#include "CPlayer.h"

CBullet::CBullet() : angle(0), /*monster(nullptr),*/ i_Damage(1)
{
}

CBullet::~CBullet()
{
}

void CBullet::Initialize()
{
	m_tInfo.fCX = 10.f;
	m_tInfo.fCY = 10.f;
	m_tdiagram = CIRCLE;
}

int CBullet::Update()
{
	if (m_bDead)
		return DEAD;

	__super::Update_Rect();

	//if (0 < monsterList->size()) {
	//	for (CObj* _monster : *monsterList) {
	//		if (monster != nullptr) {
	//			if (Get_Line(monster) > Get_Line(_monster)) {
	//				monster = _monster;
	//			}
	//		}
	//		else {
	//			monster = _monster;
	//		}
	//	}
	//}
	//else {
	//	monster = nullptr;
	//}
	//
	//if (monster != nullptr) {
	//	float z = Get_Line(monster);
	//	float theta = acosf((monster->Get_Info()->fX- m_tInfo.fX) / z);
	//	if (0 > monster->Get_Info()->fY - m_tInfo.fY) {
	//		theta *= -1;
	//	}
	//	m_fSpeed = cosf(theta) * 5.f;
	//	m_fYSpeed = sinf(theta) * 5.f;
	//}

	m_tInfo.fX += m_fSpeed;
	m_tInfo.fY += m_fYSpeed;
	return NOEVENT;
}

void CBullet::Late_Update()
{
	if (0 >= m_tRect.left || WINCX <= m_tRect.right
		|| 0 >= m_tRect.top || WINCY <= m_tRect.bottom)
	{
		m_bDead = true;
	}
}



//void CBullet::Render(HDC hDC)
//{
//	//float s, x, y;
//	//s = angle * (PI / 180);
//	//x = Get_Info()->fX + ((cosf(s)) * 50);
//	//y = Get_Info()->fY - ((sinf(s)) * 50);
//	//Ellipse(hDC,
//	//	x - 10.f, y - 10.f,
//	//	x + 10.f, y + 10.f);
//	Ellipse(hDC,
//		m_tRect.left, m_tRect.top,
//		m_tRect.right, m_tRect.bottom);
//}

void CBullet::Release()
{
}

void CBullet::SetSpeed(float _x, float _y)
{
	m_fSpeed = _x;
	m_fYSpeed = _y;
}

void CBullet::Set_Collision(CObj* p_obj)
{
	if (nullptr != dynamic_cast<CMap*>(p_obj)) {
		if (!dynamic_cast<CMap*>(p_obj)->Get_Pass()) {
			m_bDead = true;
		}
		else if (0.f < m_fYSpeed && m_tRect.bottom >= p_obj->Get_Rect()->top) {
			m_bDead = true;
		}
	}
	else if(nullptr != dynamic_cast<CMonster*>(p_obj) && 0 < i_Damage){
		m_bDead = true;
	}
	else if (nullptr != dynamic_cast<CPlayer*>(p_obj) && 0 > i_Damage) {
		m_bDead = true;
	}
}

//void CBullet::SetMonsterList(list<CObj*>* _monsterList)
//{
//	monsterList = _monsterList;
//}

//float CBullet::Get_Line(CObj* _monster)
//{
//	return sqrtf(pow(m_tInfo.fX - _monster->Get_Info()->fX, 2) + pow(m_tInfo.fY - _monster->Get_Info()->fY, 2));
//}
