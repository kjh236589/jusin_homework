#include<iostream>;
#include<windows.h>

using namespace std;

struct tInfo {
	int iX;
	float fY;
};

union uniInfo {
	int iX;
	float fY;
};

enum NUMBER
{
	ONE = 1,			// 초기화 값을 직접 지정할 수 있다
	TWO,
	THREE = 6,			// 초기화 값을 지정하면 그 다음 값부턴 그 값부터 추가된다.
	FOUR,
	END
};

int main() {
	// tInfo tInfo = { 10, 3.14f };
	// 
	// cout << &tInfo.iX << endl;
	// cout << &tInfo.fY << endl;
	// 
	// uniInfo uInfo = { 10 };

	// cout << &uInfo.iX << endl;
	// cout << &uInfo.fY << endl;

	// cout << uInfo.iX << endl;
	// cout << uInfo.fY << endl;

	NUMBER number = ONE;
	cout << number << endl;

	int iNumber = ONE + TWO;			// 자동 형 변환을 지원하여 산술 연산이 가능하게 만듬
	cout << iNumber << endl;
}

/*
	공용체 : 멤버 변수 중 가장 큰 자료형의 크기만큼만 메모리 블럭을 할당하고, 그 메모리를 공유하여 사용한다.

	열거체 : 상수를 한 번에 여러 개 만들어 사용하는 사용자 정의 자료형

*/