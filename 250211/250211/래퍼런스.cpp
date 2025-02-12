#include "pch.h"

// const int& Get_Number() { return 100; }

void	Render(const int& iData)
{
	// iData += 10;

	cout << iData << endl;
}

int main()
{
	int iNumber(200);

	//Render(iNumber);
	Render(200);


	//int		iData(10);

	// *(& iData) = 20;		// 직접 참조

	// int* p = &iData;
	// 
	// *p = 20;		// 간접 참조
	// 
	// p = new int(30);		// 0x10
	// 
	// p = new int(40);		// 0x20

	// int& r = iData;
	// 
	// r = 20;
	// 
	// cout << iData << endl;

	// cout << sizeof(short&) << endl;
	// cout << sizeof(int&) << endl;
	// cout << sizeof(long long&) << endl;

	// 레퍼런스 자료형 자체는 크기가 존재하지 않는다.

	//int iData(10);

	// int* const p; // 상수 포인터

	//const int& r = 100;			// 읽기 전용 레퍼런스

	// r = 200;	// 쓰기가 불가

	//cout << r << endl;

	//int& r = iData;		// 직접 참조
							// 장점 : 용량, 속도
	//r = 20;				// 한계 : 선언과 동시에 초기화 형태로 참조한 데이터만 접근이 가능
	//								: l-value만 참조가 가능하다.
	//int	iTest(400);
	//
	//r = iTest;
	//
	//r = 500;

	//cout << iTest << endl;
	//cout << iData << endl;



	//cout << &iData << endl;
	//cout << &r << endl;
	//	
	//cout << sizeof(int&) << endl;		

	return 0;
}