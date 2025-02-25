#include "pch.h"

class CObj2
{
public:
	virtual void	Render() { cout << "Obj" << endl; }		// 가상 함수
	virtual void	Draw() {}
};

class CPlayer2 : public CObj2
{
public:
	void	Render() { cout << "Player" << endl; }
};

int main()
{
	// 다형성 : 객체 다른 성질의 객체의 형태로 변환하여 메소드 사용 권하는 얻는 문법

	// - 부모 타입의 객체가 자식 객체에 있는 메소드를 사용 할 수 있도록 만드는 문법

	// 1. 오버라이딩	: 자식 자료형들이 동일하게 지니고 있는 메소드를 호출하기 위한 문법
	// 
	// 1 조건 : 부모와 자식 간의 상속 관계
	// 2 조건 : 부모와 자식 클래스의 완전히 동일한 형태의 함수가 존재
	// 3 조건 : 부모 클래스에 있는 함수 앞에 virtual를 반드시 삽입
	// 
	// 2. 다운 캐스팅	: 자식 자료형 중 개별적인 메소드를 호출하기 위한 문법

	// CObj2		Obj;
	// Obj.Render();

	// CPlayer2	Player;
	// Player.Render();
	// 
	// Player.CObj2::Render();

	CPlayer2		Player2;
	//
	CObj2* pObj = new CPlayer2;	// 동적 바인딩으로 동작(포인터가 어떤 객체의 주소를 참조하는지에 따라 호출되는 함수가 결정)
	
	// __vfptr = 0x00007ff6ed8acc20 {250224.exe!void(*CObj2::`vftable'[2])()} { 0x00007ff6ed8a15af {250224.exe!CObj2::Render(void)} }

	// __vfptr = 0x00007ff75148cc98 {
	// 	250224.exe!
	// 		void(*CPlayer2::`vftable'[2])()}
	// { 0x00007ff7514815c3 {250224.exe!CPlayer2::Render(void)} }

	pObj->Render();

	//CObj2	Obj;			// 정적 바인딩 그대로 동작
	//Obj.Render();


	return 0;
}