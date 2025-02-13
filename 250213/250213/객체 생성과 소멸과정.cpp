#include "pch.h"

class CBase
{
public:
	CBase();
	~CBase();

public:
	void		Set_A(int _iA) { m_iA = _iA; }

private:
	int		m_iA;
	int* m_pB;
};

CBase::CBase()
{
	m_iA = 100;				// 대입을 통한 초기화 방식
	m_pB = nullptr;
}
CBase::~CBase()
{

}

int main()
{
	// cout << sizeof(CBase) << endl;

	//CBase	Base = { 10, nullptr };


	// 객체(클래스)의 생성 시, 자동으로 생성되는 함수 네 가지

	// 1. default 생성자 : 명시적인 생성자가 한 개라도 존재하면 컴파일러가 생성하지 않음, 생성자가 여러 개 존재 할 수 있음
	// 2. default 대입 연산자
	// 3. default 복사 생성자
	// 4. default 소멸자 : 명시적인 소멸자가 있으면 컴파일러가 생성하지 않음. 소멸자는 오로지 하나의 종류만 존재

	// 객체 생성 과정(이 두 과정은 반드시 수행되어야 함)
	// 1. 메모리 할당 2. 생성자 호출

	// 객체 소멸 과정(이 두 과정은 반드시 수행되어야 함)
	// 1. 소멸자 호출 2. 메모리 반환


	CBase	Base;


	return 0;
}