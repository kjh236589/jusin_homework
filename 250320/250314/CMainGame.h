#pragma once

#include "Define.h"
#include "CPlayer.h"

class CMainGame
{
public:
	CMainGame();
	~CMainGame();

public:
	void		Initialize();
	void		Update();
	void		Late_Update();
	void		Render();
	void		Release();

private:
	HDC		m_hDC;

	// CObj*			m_pPlayer;
	// list<CObj*>		m_BulletList;

	list<CObj*>		m_ObjList[OBJ_END];

	ULONGLONG		m_dwTime;
	int			m_iFPS;
	TCHAR		m_szFPS[32];

};

// 1. 플레이어를 중심으로 공전하는 쉴드를 구현해라
// 2. 스크류 총알 구현해라
// 3. 플레이어를 따라다니는 몬스터를 구현하라(역함수를 이용할 것 : acos, acos y 치역 0~180도)

// 디자인 패턴 : 코드의 구조들을 일정한 형태로 만들어 재사용하기 편리하도록 만드는 패턴

//https://refactoring.guru/ko/design-patterns

// 1. 추상 팩토리 패턴 : 생성 패턴의 한 방법으로 인스턴스를 만드는 절차를 추상화시킨 패턴, 객체 생성 시 동반되는 작업을 공통적인 형태로 만드는 방식

// 2. 반복자(이터레이터) 패턴 : 내부 표현 방식은 공개하지 않고 순차적인 접근 방법을 제공하는 패턴