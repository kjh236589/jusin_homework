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

	list<CObj*>		m_ObjList[3][OBJ_END];

	ULONGLONG		m_dwTime;
	int			m_iFPS, game;
	TCHAR		m_szFPS[32];

};

// 1. 피타고라스의 정리를 읽어와라
// 2. 피타고라스의 정리를 이용하여 원 충돌을 구현해라
// 3. 삼각 함수가 무엇인지 알아와라
// 4. 플레이어 중심으로 회전하는 포신을 만들어와라.


// RECT	rc{};
// IntersectRect(충돌로 인해 발생한 렉트 정보를 저장하기 위한 렉트 주소, 충돌렉트 1의 주소, 충돌 렉트 2의 주소)
// IntersectRect(&rc, , )


// 디자인 패턴 : 코드의 구조들을 일정한 형태로 만들어 재사용하기 편리하도록 만드는 패턴

//https://refactoring.guru/ko/design-patterns

// 1. 추상 팩토리 패턴 : 생성 패턴의 한 방법으로 인스턴스를 만드는 절차를 추상화시킨 패턴, 객체 생성 시 동반되는 작업을 공통적인 형태로 만드는 방식

// 2. 반복자(이터레이터) 패턴 : 내부 표현 방식은 공개하지 않고 순차적인 접근 방법을 제공하는 패턴