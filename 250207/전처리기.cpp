#include<iostream>

// ��ũ�� : ���� ����ϴ� �ڵ� ��
//	��� ��ũ��

#define	PI	3.14f

#define MIN_STR 32
#define MAX_STR 123

//	�Լ� ��ũ��
// 1. ���� �ӵ��� ����(�ڵ尡 �� ���� ģȯ(����))
// 2. �ڷ����� ���� ������ ����
// 
// ����
// �Լ� ��ũ�� ���� �ڵ尡 �Ͼ����� �������� ������
#define	SQUARE(X)	(X)\
*\
(X)

#define SAFE_DELETE(p)	if(p){\
delete p;\
p = nullptr;\
}

#define SAFE_DELETE_B(p)	if(p){\
delete[]p;\
p = nullptr;\
}

// ���Ǻ� ������

using namespace std;

int main() {
	// char szName[MIN_STR] = "";
	// cout << PI << endl;

	// cout << SQUARE(10) << endl;
	// cout << SQUARE(11.1f) << endl;
	// cout << SQUARE((2 + 2)) << endl;

	int* p = new int;
	cout << p << endl;
	SAFE_DELETE(p);
	cout << p << endl;
	return 0;
}