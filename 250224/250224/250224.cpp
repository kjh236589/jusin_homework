#include "pch.h"
#include "CMainGame.h"

int main()
{
	CMainGame		MainGame;

	MainGame.Initialize();
	MainGame.Update();

	return 0;
}


// UML 기호

/*
					사람	 - 밥을 먹다
일반화↑	구체화↓		학생 - 공부를 하다
					학생회 - 축제를 준비하다

일반화(객관화)	: 부모로 올라갈 수록 일반화 됨
구체화			: 자식개체로 내려갈수록 구체화 됨
*/