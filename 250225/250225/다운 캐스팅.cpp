#include "pch.h"

class CObj3
{
public:
	virtual ~CObj3() {}

public:
	void	Output() { cout << "Obj" << endl; }
};

class CPlayer3 : public CObj3
{
public:
	~CPlayer3() {}

public:
	void	Render() { cout << "Player" << endl; }
};

class CMonster3
{
public:
	CMonster3() { cout << "생성자 호출" << endl; }

public:
	void	Print() { cout << "Monster" << endl; }
};

int main()
{
	//CObj3* pPlayer = new CPlayer3;
	// ((CPlayer3*)pPlayer)->Render();

	//((CMonster3*)pPlayer)->Print();

	////////////////////////////////////////////////////////////

	// c++ 캐스팅 연산자
	// 
	// static_cast, dynamic_cast(다형성), const_cast, reinterpret_cast

#pragma region static_cast

	// static_cast : c 스타일의 캐스팅과 같은 역할, 정적 캐스팅이라고도 부름, 컴파일 타임에 캐스팅
	// 비 논리(클래스의 상속 유무)적인 형 변환을 허용하지 않음
	// 런 타임 시, 논리적인 형 변환에 대한 판단을 불가능하기 때문에 변환의 위험성을 감지 할 수 없다.

	// int	iNumber = (int)3.14f;
	// int	iNumber = static_cast<int>(3.14f);
	// cout << iNumber << endl;

	// CMonster3* pMonster = new CMonster3;

	// CObj3* pObj = (CObj3*)pMonster;		// 비 논리적인 형 변환을 제공
	// pObj->Output();

	// CObj3* pObj = static_cast<CObj3*>(pMonster);	// 컴파일 에러(비 논리적인 형 변환을 허용하지 않음)
	// pObj->Output();

	//CObj3*	pObj		= new	CPlayer3;
	// CPlayer3* pPlayer	= static_cast<CPlayer3*>(pObj);
	// pPlayer->Render();

	//static_cast<CPlayer3*>(pObj)->Render();		// 논리적인 형 태의 down casting 코드(다형성은 아님)
	
#pragma endregion

#pragma region dynamic_cast

	// 1. 클래스의 down 캐스팅만 허용
	// 2. 상속 관계의 클래스가 있어야 함
	// 3. 부모 클래스의 반드시 한 개 이상의 virtual 키워드가 붙은 가상 함수가 있어야 함
	// 4. 일반 자료형이나 일반 포인터를 대상으로는 동작하지 않으며 런 타임 시, 안전 검사를 수행한다.

	// CObj3* pObj = new	CPlayer3;	
	// dynamic_cast<CPlayer3*>(pObj)->Render();			// 안전한 다운 캐스팅의 예

	CObj3* pObj = new CObj3;

	CPlayer3* pPlayer = dynamic_cast<CPlayer3*>(pObj);

	// 비 논리적인 형 변환을 수행할 경우, 런 타임 때 nullptr을 반환
	// 형 변환을 안하는 것은 아님
	
	if (nullptr == pPlayer)
		cout << "비 논리적인 형 변환" << endl;

	else
		pPlayer->Render();

#pragma endregion

	

	return 0;
}