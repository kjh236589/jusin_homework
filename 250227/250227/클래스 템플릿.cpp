#include "pch.h"

// Ŭ���� ���ø�

template<typename T>
class CTest
{
public:
	CTest();
	CTest(T Sum) : m_Sum(Sum) {}
	~CTest() {}

public:
	T	Add(T Dst, T Src);	

	T	Func(T Number)
	{
		m_Sum += Number;

		return m_Sum;
	}

private:
	static T		m_Sum;
};

template<typename T>
T		CTest<T>::m_Sum = 0;

template<typename T>
T	CTest<T>::Add(T Dst, T Src)
{
	return Dst + Src;
}

template<typename T>
CTest<T>::CTest() 
{

}



// ���ø� Ư��ȭ�� ����� Ŭ���� ���ø�
template<>
class CTest<const char*>
{
public:
	const char* Add(const char* Dst, const char* Src)
	{
		size_t iLength = strlen(Dst) + strlen(Src);

		char* pString = new char[iLength + 1];

		strcpy_s(pString, iLength + 1, Dst);
		strcat_s(pString, iLength + 1, Src);

		return pString;
	}
};

// Ŭ���� ���ø��� �κ� Ư��ȭ
template<typename T1, typename T2>
class CObj {};

// �κ� Ư��ȭ �� 1
template<>
class CObj<int, char*> {};

// �κ� Ư��ȭ�� �� 2
template<typename T>
class CObj<T, char*> {};


int main()
{
	// ���ø� Ŭ����
	CTest<int>		Test;

	//cout << Test.Add(10, 20) << endl;

	Test.Func(10);
	cout << Test.Func(20) << endl;

	CTest<int>			Sour;

	cout << Sour.Func(30) << endl;

	return 0;
}