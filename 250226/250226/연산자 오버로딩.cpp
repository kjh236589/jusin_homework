#include "pch.h"

class CObj
{
public:
	CObj() : m_iX(0), m_iY(0) { }
	CObj(int _iX, int _iY) : m_iX(_iX), m_iY(_iY) { cout << "생성자 호출" << endl; }
	CObj(const CObj& rhs) : m_iX(rhs.m_iX), m_iY(rhs.m_iY) { cout << "복사 생성자 호출" << endl; }
	CObj& operator=(CObj& rObj)
	{
		m_iX = rObj.m_iX;
		m_iY = rObj.m_iY;	

		cout << "default 대입 연산자 호출" << endl;

		return *this;
	}

	~CObj() {}

public:
	void	Render() { cout << m_iX << "\t" << m_iY << endl; }

	CObj	operator +(CObj& rObj)
	{
		CObj	Temp(m_iX + rObj.m_iX, m_iY + rObj.m_iY);

		return Temp;
	}

	CObj	operator +(int iData)
	{
		CObj	Temp(m_iX + iData, m_iY + iData);

		return Temp;
	}

	CObj& operator++()
	{
		m_iX += 1;
		m_iY += 1;

		return *this;
	}

	CObj operator++( int)		// 후위 연산자 구현 임을 알리는 문법
	{
		CObj	Result(*this);

		m_iX += 1;
		m_iY += 1;

		return Result;
	}

private:
	int		m_iX;
	int		m_iY;
};

// 전역 함수
CObj	operator +(int iData, CObj& rObj)
{
	CObj	Result(rObj + iData);

	return Result;
}


int main()
{
	// 연산자 오버로딩 : 함수 오버로딩의 규칙을 연산자에게 적용하는 문법
	// 연산자 오버로딩은 연산자 기준, '좌측에 객체를 배치'하여 수행

	// 연산자 오버로딩은 operator 키워드를 이용하여 제작 가능
	// - 기존의 연산자의 개념을 바꾸는 행위는 할 수 없음( + -> - 의미로 만들겠다)

	// 클래스 멤버로만 오버로딩이 가능한 연산자
	// '=', '()', '[]', '->'



	// void operator + (CObj& rObj);

	//CObj	Temp(10, 20);
	//CObj	Sour(30, 40);
		
	//Temp = Temp + Sour;

	// Temp = Temp + 100;

	//Temp = 100 + Temp;

	//Temp = Sour;

	//Temp++;

	//Temp.Render();

	return 0;
}