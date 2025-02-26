#include "pch.h"
#include <string>


class CPlus
{
public:
	int	operator()(int iDst, int iSrc)
	{
		return iDst + iSrc;
	}
};

bool		Less(int iDst, int iSrc)
{
	return iDst < iSrc;
}

class Less_Functor
{
public:
	int	operator()(int iDst, int iSrc)
	{
		return iDst + iSrc;
	}
};

int main()
{
	// 함수 객체 : ()연산자 오버로딩을 이용하여 객체를 함수처럼 사용하도록 만드는 문법

	CPlus		Functor;
	cout << Functor(10, 20) << endl;

	// 알고리즘(begin, end, Less);
	// 알고리즘(begin, end, Less_Functor());

	string strName;
	string strTemp = "_활빈당";

	strName = "홍길동";
	cout << strName << endl;

	if ("홍길동" == strName)
	{
		cout << "일치" << endl;
	}

	strName = strName + strTemp;

	cout << strName << endl;

	return 0;
}

// string 클래스 직접 구현 하기

// strcpy를 이용하여 문자열 대입 = 연산자로 구동하도록 만들기
// strcat을 이용하여 문자열 결합 + 연산자로 구동하도록 만들기
// strcmp를 이용하여 문자열 비교 == 연산자를 구동하도록 만들기