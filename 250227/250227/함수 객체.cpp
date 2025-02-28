#include "pch.h"

#pragma region �Լ� ��ü
class CSourRule
{
public:
	virtual bool operator()(int Dst, int Src) = 0;
};

class CAscendingSort : public CSourRule
{
public:
	virtual bool operator()(int Dst, int Src)
	{
		return Dst > Src;
	}
};

class CDescendingSort : public CSourRule
{
public:
	virtual bool operator()(int Dst, int Src)
	{
		return Dst < Src;
	}
};


void Bubble_Sort(int pArray[], int iSize, CSourRule&& Functor)
{
	for (int i = 0; i < iSize; ++i)
	{
		for (int j = 0; j < iSize - 1; ++j)
		{
			if (Functor(pArray[j], pArray[j + 1]))
			{
				swap(pArray[j], pArray[j + 1]);
			}
		}
	}
}

bool Less(int Dst, int Src)
{
	return Dst < Src;
}

int main()
{
	int		iArray[5] = { 5, 1, 3, 2, 4 };
 
	//CDescendingSort		Desce;

	Bubble_Sort(iArray, 5, CDescendingSort());

	for (int i = 0; i < 5; ++i)
	{
		cout << iArray[i] << endl;
	}
 

	return 0;
}
#pragma endregion

#pragma region �ӽ� ��ü

//class CTest
//{
//public:
//	CTest(const char* pStr)
//	{
//		strcpy_s(m_szName, sizeof(m_szName), pStr);
//		cout << m_szName << " ������" << endl;
//	}
//	~CTest()
//	{
//		cout << m_szName << " �Ҹ���" << endl;
//	}
//
//private:
//	char		m_szName[32];
//};
//
//int main()
//{
//	CTest	Test("�Ϲ� ��ü");
//
//	cout << "----------------------------------" << endl;
//
//	CTest("�ӽ� ��ü");
//
//	cout << "----------------------------------" << endl;
//
//	return 0;
//}




#pragma endregion



