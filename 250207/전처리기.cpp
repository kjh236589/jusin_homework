#include <iostream>

// ��ũ�� : ���� ����ϴ� �ڵ� ��

// ��� ��ũ��(�ܼ� ġȯ)

#define		PI		3.14f

#define		MIN_STR		32
#define		MAX_STR		128

// �Լ� ��ũ��
// 1. ���� �ӵ��� ����(�ڵ尡 �� ���� ġȯ(����))
// 2. �ڷ����� ���� ������ ����

// ���� 
// �Լ� ��ũ�� ���� �ڵ尡 ������� �������� ������
#define		SQUARE(X)		((X) * (X))

#define		SAFE_DELETE(p)			if(p){ 	delete p ;	p = nullptr; }
#define		SAFE_DELETE_ARRAY(p)		if(p){ 	delete []p ;	p = nullptr; }

// ���Ǻ� ������

using namespace std;

int main()
{

	// char	szName[MIN_STR] = "";
	// cout << 3.14f << endl;

	// cout << SQUARE(10) << endl;
	// cout << SQUARE(11.1f) << endl;

	// cout << SQUARE(2 + 2) << endl;

	int iInput(0);

	cin >> iInput;

	int* p = new int[iInput];

	SAFE_DELETE_ARRAY(p);




	return 0;
}