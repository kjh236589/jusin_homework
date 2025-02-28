#include "pch.h"

// �Լ� ���ø�(���� ���ø�)

template<typename T>
T	Add(T Dst, T Src)
{
	return Dst + Src;
}

// ���ø� Ư��ȭ(Ư�� �ڷ����� ���� Ư���ϰ� �����Ű�� ����>
// - �⺻���� ���ø��� ���� ������� �־�� ��
template<>
char* Add(char* Dst, char* Src)
{
	size_t iLength = strlen(Dst) + strlen(Src);

	char* pString = new char[iLength + 1];

	strcpy_s(pString, iLength + 1, Dst);
	strcat_s(pString, iLength + 1, Src);

	return pString;
}

// Ư��ȭ�� ����� ���ø��� const�� ���� �Լ� �����ε��� ����
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

// ���� �ڷ� Ÿ���� ���ø� �Լ����� static �޸� ������ ����
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
	// ���ø� : ����� ���� �Ǿ� ������ �ڷ����� ���� �Ǿ� ���� ����(��� �ڷ����� ȣȯ�� �����ؾ� ��) ������ ����

	// �Լ�   ���ø� : �Լ��� ���¸� �� ���ø�, �Լ��� �����ϴ� ��
	// Ŭ���� ���ø� : Ŭ������ ���¸� �� ���ø�, Ŭ������ �����ϴ� ��

	// cout << Add<int>(10, 20) << endl;			// ���ø� �Լ�
	// cout << Add<float>(1.1f, 2.2f) << endl;		// ���ø� �Լ�

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