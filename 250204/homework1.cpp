#include<iostream>

using namespace std;

int main() {
	char cString[100] = {};	// �� ������ NULL�� ���ϴ�. NULL�� ���� 0�Դϴ�.
	cout << "���ڿ��� �Է����ּ��� : ";
	cin >> cString;			// char �迭�� ���ڿ��� �Է¹��� �� ���� ������ ������ NULL�� ���ֽ��ϴ�..
	for (int i = 0; i < sizeof(cString) / sizeof(char); ++i) {
		if (!cString[i]) {	// ���ڿ��� ������ ���� ������ NULL�̱� ������ NULL�� ���´ٸ� ���ڿ��� �����ٴ� ���Դϴ�.
			cout << "���ڿ��� ���� : " << i;
			break;
		}
	}
	return 0;
}