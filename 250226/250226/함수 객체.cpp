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
	// �Լ� ��ü : ()������ �����ε��� �̿��Ͽ� ��ü�� �Լ�ó�� ����ϵ��� ����� ����

	CPlus		Functor;
	cout << Functor(10, 20) << endl;

	// �˰���(begin, end, Less);
	// �˰���(begin, end, Less_Functor());

	string strName;
	string strTemp = "_Ȱ���";

	strName = "ȫ�浿";
	cout << strName << endl;

	if ("ȫ�浿" == strName)
	{
		cout << "��ġ" << endl;
	}

	strName = strName + strTemp;

	cout << strName << endl;

	return 0;
}

// string Ŭ���� ���� ���� �ϱ�

// strcpy�� �̿��Ͽ� ���ڿ� ���� = �����ڷ� �����ϵ��� �����
// strcat�� �̿��Ͽ� ���ڿ� ���� + �����ڷ� �����ϵ��� �����
// strcmp�� �̿��Ͽ� ���ڿ� �� == �����ڸ� �����ϵ��� �����