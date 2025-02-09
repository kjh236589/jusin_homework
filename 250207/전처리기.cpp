#include <iostream>

// 매크로 : 자주 사용하는 코드 블럭

// 상수 매크로(단순 치환)

#define		PI		3.14f

#define		MIN_STR		32
#define		MAX_STR		128

// 함수 매크로
// 1. 동작 속도가 빠름(코드가 그 삽입 치환(삽입))
// 2. 자료형에 따른 제한이 없음

// 단점 
// 함수 매크로 안의 코드가 길어지면 가독성이 떨어짐
#define		SQUARE(X)		((X) * (X))

#define		SAFE_DELETE(p)			if(p){ 	delete p ;	p = nullptr; }
#define		SAFE_DELETE_ARRAY(p)		if(p){ 	delete []p ;	p = nullptr; }

// 조건부 컴파일

using namespace std;

int main()
{

	// char	szName[MIN_STR] = "";
	// cout << 3.14f << endl;

	// cout << SQUARE(10) << endl;
	// cout << SQUARE(11.1f) << endl;

	// cout << SQUARE(2 + 2) << endl;

	int iInput(0);

	cin >> iInput;

	int* p = new int[iInput];

	SAFE_DELETE_ARRAY(p);




	return 0;
}