#include<iostream>

using namespace std;

int main() {
	char cString[100] = {};
	cout << "���ڿ��� �Է����ּ��� : ";
	cin >> cString;
	for (int i = 0; i < sizeof(cString) / sizeof(char); ++i) {
		if (!cString[i]) {	// ���ڿ��� �������� Ȯ���մϴ�.
			cout << "������ ���ڿ� : ";
			for (int j = i; j >= 0; --j) {	// ���ڿ��� ������ �Ųٷ� ����մϴ�.
				cout << cString[j];
			}
			break;
		}
	}
	return 0;
}