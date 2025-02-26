#include "pch.h"

// int		Add(int iDst, int iSrc);

inline int Add(int iDst, int iSrc)
{
	return iDst + iSrc;
}

int main()
{
	// inline 함수 : 함수를 호출하는 위치에 코드를 그대로 구성
	// inline 결정을 컴파일러가 수행

	// 코드를 그대로 삽입하는 형식이기 때문에 동작 속도가 빠름
	// 단점은 특정 자료형에 종속되어 있음

	// cout << Add(10, 20) << endl;

	// inline 함수에서 일반 함수로 자동 변경되는 경우
	// 
	// 1. 함수 포인터에 inline 함수의 이름을 저장한 경우
	// 2. inline 함수를 재귀적으로 호출하는 경우

	return 0;
}

