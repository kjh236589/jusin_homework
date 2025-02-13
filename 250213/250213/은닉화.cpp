#include "pch.h"

struct tagInfo {				// struct 기본적으로 public
	int iA;					// 멤버 변수
	void Draw() {			// 멤버 함수
		iA = 200;			// 내부 접근
		cout << iA << endl;
	}
};

class CObj {					// class 기본적으로 private
private:						// private으로 선언하면 외부에서 접근 불가
	int iA;					// 멤버 변수
public:						// public으로 선언하면 외부에서 접근 가능
	void Draw() {			// 멤버 함수
		iA = 200;			// 내부 접근
		cout << iA << endl;
	}
};

int main()
{
	// 1. 은닉화 : 데이터의 보호를 하기 위한 문법적인 수단
	//	- 접근 제어 지시자
	//	- acess method	: GET, SET 함수를 이용하여 멤버 변수의 읽기 및 쓰기를 허용

	tagInfo tInfo;

	tInfo.iA = 100;			// 외부 접근
	cout << tInfo.iA << endl;

	tInfo.Draw();

	return 0;
}

/*
	- 클래스를 이용하여 성적표 만들기(동적 배열을 이용하여 만들기)
		1. 입력 2. 출력 3. 검색 4. 종료
		- 최초 입력 시 몇명인지 입력
		- 두 번째 입력부터는 기존 입력 인원 + 새롭게 추가하는 인원의 형태가 되도록 구현
*/