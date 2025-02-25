#include "pch.h"

// 추상 클래스 : 오로지 자식 클래스에게 메소드를 제공하는 용도로 전락된 일종의 인터페이스 클래스
// 순수 가상 함수가 한 개라도 존재하면 추상 클래스로 변함, 추상 클래스는 자체적인 객체 생성이 불가
// 부모 클래스에 순수 가상함수가 존재할 경우, 그 클래스에 상속을 받는 모든 자식 클래스는 반드시 순수 가상함수의 몸체를 구현해야한다

class CBase
{
public:
	virtual void	Render() = 0;				// 순수 가상 함수 : 오버라이딩을 하기 위한 용도로 부모 클래스의 선언하는 문법
	void	Draw() { cout << "Base" << endl; }
};

class CDerived : public CBase
{
public:
	void	Render() { cout << "hello world" << endl; }
};

class CTemp : public CBase
{
public:
	void	Render() {}
};


int main()
{

	// CBase* pBase = new CDerived;
	// 
	// pBase->Render();

	// CBase	Base;		// 추상 클래스는 자신의 타입으로 객체 생성이 불가능하다.
	// Base.Draw();

	CBase* pTemp = new CTemp;

	pTemp->Draw();

	


	return 0;
}