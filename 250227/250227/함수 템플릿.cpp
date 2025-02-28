#include "pch.h"

// 함수 템플릿(단항 템플릿)

template<typename T>
T	Add(T Dst, T Src)
{
	return Dst + Src;
}

// 템플릿 특수화(특정 자료형에 대해 특수하게 적용시키는 문법>
// - 기본적인 템플릿이 먼저 만들어져 있어야 함
template<>
char* Add(char* Dst, char* Src)
{
	size_t iLength = strlen(Dst) + strlen(Src);

	char* pString = new char[iLength + 1];

	strcpy_s(pString, iLength + 1, Dst);
	strcat_s(pString, iLength + 1, Src);

	return pString;
}

// 특수화가 진행된 템플릿은 const에 따른 함수 오버로딩이 성립
template<>
const char* Add(const char* Dst, const char* Src)
{
	size_t iLength = strlen(Dst) + strlen(Src);

	char* pString = new char[iLength + 1];

	strcpy_s(pString, iLength + 1, Dst);
	strcat_s(pString, iLength + 1, Src);

	return pString;
}

template<typename T1, typename T2, typename T3>
T3 Add(T1 Dst, T2 Src)
{
	return Dst + Src;
}

// 같은 자료 타입의 템플릿 함수들은 static 메모리 공간을 공유
template<typename T>
T	Func(T Number)
{
	static T		Sum = 0;

	Sum += Number;

	return Sum;
}

#define SAFE_DELETE(p) if(p) { delete p; p = nullptr; }

template<typename T>
void Safe_Delete(T& p)
{
	if (p)
	{
		delete p;
		p = nullptr;
	}
}

template<typename T>
void Safe_Delete_Array(T& p)
{
	if (p)
	{
		delete [] p;
		p = nullptr;
	}
}


int main()
{
	// 템플릿 : 기능은 결정 되어 있지만 자료형은 결정 되어 있지 않은(모든 자료형에 호환이 가능해야 함) 상태의 도구

	// 함수   템플릿 : 함수의 형태를 띈 템플릿, 함수를 생성하는 것
	// 클래스 템플릿 : 클래스의 형태를 띈 템플릿, 클래스를 생성하는 것

	// cout << Add<int>(10, 20) << endl;			// 템플릿 함수
	// cout << Add<float>(1.1f, 2.2f) << endl;		// 템플릿 함수

	// const char* pStr = Add<const char*>("hello", "world");
	// 
	// cout << pStr << endl;
	// 
	// delete[]pStr;

	// double dNumber = Add<int, float, double>(10, 20.1f);
	// cout << dNumber << endl;


	// Func<int>(10);
	// Func<float>(1.1f);
	// 
	// cout << Func<int>(15) << endl;
	// cout << Func<float>(2.2f) << endl;


	int* pTemp = new int;

	Safe_Delete<int*>(pTemp);


	return 0;
}