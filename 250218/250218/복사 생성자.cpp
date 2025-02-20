#include "pch.h"

class CObj
{
public:
	CObj(int _iA) : m_iA(_iA)
	{
		m_pA = new int(100);			// 0x10
		cout << "일반 생성자 호출" << endl;
	}
	CObj(const CObj& rhs)
		// : m_iA(rhs.m_iA)
	{
		// m_iA = rhs.m_iA;
		// m_pA = rhs.m_pA;				// 0x10 번지의 주소를 복사본 포인터에게 복사하여 전달
										// 얕은 복사(shallow copy)의 문제


		m_iA = rhs.m_iA;
		m_pA = new int(*rhs.m_pA);		// 깊은 복사(deep copy)

		cout << "복사 생성자 호출" << endl;
	}

	~CObj()
	{
		delete m_pA;
	}

public:
	void	Render() { cout << m_iA << endl; }

	void	Print(CObj Temp)		// 2. 함수 매개 변수가 객체 타입인 경우
	{
		Temp.Render();
	}

	CObj	Get_Obj()				// 3. 함수 반환 타입이 객체 타입인 경우
	{
		return *this;
	}

	// CObj*		Clone()
	// {
	// 		return new CObj(*this);
	// }


private:
	int		m_iA;
	int*	m_pA;
};


int main()
{
	CObj		Obj(100);

	CObj		Copy(Obj);		// 1. 먼저 만든 객체를 매개 변수로 전달하여 새로운 객체를 생성 할 때
	//
	//Copy.Render();

	// CObj		Test(200);
	// 
	// Test.Print(Obj);

	// Obj.Get_Obj().Render();



	return 0;
}