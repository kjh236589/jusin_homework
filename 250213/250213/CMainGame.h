#pragma once

class CMainGame {
public:
		void Initialize();		// 멤버 변수의 초기화 또는 초기값을 설정
		void Update();			// 매 프레임마다 변경되는 값을 만드는 함수
		void Release();			// 동적 할당 메모리를 해제하는 코드들을 모아놓는 함수
};