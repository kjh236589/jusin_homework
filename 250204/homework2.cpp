#include<iostream>

using namespace std;

int main() {
	char cString[100] = {};
	cout << "문자열을 입력해주세요 : ";
	cin >> cString;
	for (int i = 0; i < sizeof(cString) / sizeof(char); ++i) {
		if (!cString[i]) {	// 문자열이 끝났는지 확인합니다.
			cout << "반전된 문자열 : ";
			for (int j = i; j >= 0; --j) {	// 문자열의 끝부터 거꾸로 출력합니다.
				cout << cString[j];
			}
			break;
		}
	}
	return 0;
}