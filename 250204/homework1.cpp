#include<iostream>

using namespace std;

int main() {
	char cString[100] = {};	// 빈 공간은 NULL이 들어갑니다. NULL은 숫자 0입니다.
	cout << "문자열을 입력해주세요 : ";
	cin >> cString;			// char 배열은 문자열을 입력받은 후 남는 공간은 여전히 NULL이 들어가있습니다..
	for (int i = 0; i < sizeof(cString) / sizeof(char); ++i) {
		if (!cString[i]) {	// 문자열이 끝나고 남는 공간은 NULL이기 때문에 NULL이 나온다면 문자열이 끝났다는 뜻입니다.
			cout << "문자열의 길이 : " << i;
			break;
		}
	}
	return 0;
}