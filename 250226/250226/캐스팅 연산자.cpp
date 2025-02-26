// 250226.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"

int main()
{
#pragma region const_cast

	// const_cast : 포인터 또는 레퍼런스 형만 사용이 가능, 본래 지니고 있는 const의 성격을 벗겨내기 위한 도구

	// int	iNumber(100);
	// 
	// const int* p = &iNumber;
	// 
	// int* p2 = const_cast<int*>(p);
	// 
	// *p2 = 200;
	// 
	// cout << iNumber << endl;

#pragma endregion

#pragma region reinterpret_cast

	// reinterpret_cast : const 포인터를 제외한 모든 포인터의 형 변환을 허용, 논리적으로 맞지 않는 형 변환마저 허용
	// 예측 할 수 없는 결과를 초래할 수 있기 때문에 사용하지 않을 것을 권장

	// int		iNumber(65);
	//
	// char* ptr = reinterpret_cast<char*>(&iNumber);
	//
	// cout << ptr << endl;

	// int* p = reinterpret_cast<int*>(malloc(4));

#pragma endregion

	return 0;
}

