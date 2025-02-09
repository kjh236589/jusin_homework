#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
	// 메모리 함수 : 메모리 대 메모리로 동작을 수행하는 함수

	// int		iArray[5] = { 1, 2, 3, 4, 5 };
	// 
	// ZeroMemory
	// 
	// // memset : 메모리 초기화 함수(초기화를 수행할 메모리 공간의 주소, 바이트 단위로 채울 값, 초기화를 수행할 메모리의 크기)
	// memset(iArray, 0, sizeof(iArray));
	// 
	// for (int i = 0; i < 5; ++i)
	// {
	// 	cout << iArray[i] << endl;
	// }

	// int		iArray[5] = { 1, 2, 3, 4, 5 };
	// int		iTemp[5] = {};
	// 
	// //memcpy(iTemp, iArray, sizeof(iTemp));
	// memmove(iTemp, iArray, sizeof(iTemp));
	// 
	// for (int i = 0; i < 5; ++i)
	// {
	// 	cout << iTemp[i] << endl;
	// }



	return 0;
}