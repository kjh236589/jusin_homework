#include "pch.h"

class CBase
{
public:
	void		Render_Base() { cout << "Base" << endl; }
};

class CDerived : public CBase
{
public:
	void		Render_Derived() { cout << "Derived" << endl; }
};

class CTemp : public CDerived
{
public:
	void		Render_Temp() { cout << "Temp" << endl; }
};

int main()
{

	// 객체 포인터는 컴파일 타임에 자료형에 따라 어떤 함수를 호출 할 지 결정 되어있다.

	// 정적 바인딩 : 컴파일 타임에 객체의 형태에 따라 호출 할 수 있는 함수의 상태가 결정

	//CDerived* pDerived = &Temp;
	//
	//pDerived->Render_Base();
	//pDerived->Render_Derived();
	//
	//pDerived->Render_Temp();


	// 1. 1번만 된다 : 한성, 찬빈
	// 2. 2번만 된다 : 
	// 3. 3번만 된다 : 
	// 4. 1, 2번만 된다 : 서영, 정환, 현빈, 진호, 혜연, 준석, 선우, 재훈, 누리, 진우(?)
	// 5. 1, 3번만 된다 : 
	// 6. 2, 3번만 된다 : 
	// 7. 1, 2, 3번 다 된다 : 인혁, 민수, 민석, 선호, 진성
	// 8. 안 된다(컴파일 에러) : 


	return 0;
}
