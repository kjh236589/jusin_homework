#include "pch.h"

// const int& Get_Number() { return 100; }

void	Render(const int& iData)
{
	// iData += 10;

	cout << iData << endl;
}

int main()
{
	int iNumber(200);

	//Render(iNumber);
	Render(200);


	//int		iData(10);

	// *(& iData) = 20;		// ���� ����

	// int* p = &iData;
	// 
	// *p = 20;		// ���� ����
	// 
	// p = new int(30);		// 0x10
	// 
	// p = new int(40);		// 0x20

	// int& r = iData;
	// 
	// r = 20;
	// 
	// cout << iData << endl;

	// cout << sizeof(short&) << endl;
	// cout << sizeof(int&) << endl;
	// cout << sizeof(long long&) << endl;

	// ���۷��� �ڷ��� ��ü�� ũ�Ⱑ �������� �ʴ´�.

	//int iData(10);

	// int* const p; // ��� ������

	//const int& r = 100;			// �б� ���� ���۷���

	// r = 200;	// ���Ⱑ �Ұ�

	//cout << r << endl;

	//int& r = iData;		// ���� ����
							// ���� : �뷮, �ӵ�
	//r = 20;				// �Ѱ� : ����� ���ÿ� �ʱ�ȭ ���·� ������ �����͸� ������ ����
	//								: l-value�� ������ �����ϴ�.
	//int	iTest(400);
	//
	//r = iTest;
	//
	//r = 500;

	//cout << iTest << endl;
	//cout << iData << endl;



	//cout << &iData << endl;
	//cout << &r << endl;
	//	
	//cout << sizeof(int&) << endl;		

	return 0;
}