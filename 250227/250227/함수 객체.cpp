#include "pch.h"

#pragma region ÇÔ¼ö °´Ã¼
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

#pragma region ÀÓ½Ã °´Ã¼

//class CTest
//{
//public:
//	CTest(const char* pStr)
//	{
//		strcpy_s(m_szName, sizeof(m_szName), pStr);
//		cout << m_szName << " »ý¼ºÀÚ" << endl;
//	}
//	~CTest()
//	{
//		cout << m_szName << " ¼Ò¸êÀÚ" << endl;
//	}
//
//private:
//	char		m_szName[32];
//};
//
//int main()
//{
//	CTest	Test("ÀÏ¹Ý °´Ã¼");
//
//	cout << "----------------------------------" << endl;
//
//	CTest("ÀÓ½Ã °´Ã¼");
//
//	cout << "----------------------------------" << endl;
//
//	return 0;
//}




#pragma endregion



