#include "pch.h"
#include "String.h"


char* operator+(const char* pString, String& str) {
	int iCount(0);
	iCount = (int)strlen(pString) + (int)strlen(str()) + 1;
	char* cStr = new char[iCount];
	strcpy_s(cStr, iCount, pString);
	strcat_s(cStr, iCount, str());
	return cStr;
}

int main() {
	String a, b;
	a = "홍";
	b = "길동";
	cout << a() << endl;
	a = "홍" + b;
	cout << a() << endl;
	if (a == "홍길동") {
		cout << "일치" << endl;
	}
	else {
		cout << "불일치" << endl;
	}
	if (a == "이순신") {
		cout << "일치" << endl;
	}
	else {
		cout << "불일치" << endl;
	}
	return 0;
}