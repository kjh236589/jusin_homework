#include "pch.h"]
#include "CPlayer.h"

// extern : 외부에 표기한 형태의 전역 변수가 존재하는 것을 알려주는 프로그램 키워드
// 실제 메메로 할당은 되지 않는다,(extern을 붙여서 표기한 자료는 크기가 존재하지 않으며 값을 대입할 수 없음)

extern int g_iNumber;

extern void Draw();

void CPlayer::Render()
{
	Draw();
	g_iNumber = 500;
	cout << g_iNumber << endl;
}