#include<iostream>;
#include<windows.h>

using namespace std;

struct tInfo {
	int iX;
	float fY;
};

union uniInfo {
	int iX;
	float fY;
};

enum NUMBER
{
	ONE = 1,			// �ʱ�ȭ ���� ���� ������ �� �ִ�
	TWO,
	THREE = 6,			// �ʱ�ȭ ���� �����ϸ� �� ���� ������ �� ������ �߰��ȴ�.
	FOUR,
	END
};

int main() {
	// tInfo tInfo = { 10, 3.14f };
	// 
	// cout << &tInfo.iX << endl;
	// cout << &tInfo.fY << endl;
	// 
	// uniInfo uInfo = { 10 };

	// cout << &uInfo.iX << endl;
	// cout << &uInfo.fY << endl;

	// cout << uInfo.iX << endl;
	// cout << uInfo.fY << endl;

	NUMBER number = ONE;
	cout << number << endl;

	int iNumber = ONE + TWO;			// �ڵ� �� ��ȯ�� �����Ͽ� ��� ������ �����ϰ� ����
	cout << iNumber << endl;
}

/*
	����ü : ��� ���� �� ���� ū �ڷ����� ũ�⸸ŭ�� �޸� ���� �Ҵ��ϰ�, �� �޸𸮸� �����Ͽ� ����Ѵ�.

	����ü : ����� �� ���� ���� �� ����� ����ϴ� ����� ���� �ڷ���

*/