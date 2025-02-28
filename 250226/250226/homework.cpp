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
	a = "ȫ";
	b = "�浿";
	cout << a() << endl;
	a = "ȫ" + b;
	cout << a() << endl;
	if (a == "ȫ�浿") {
		cout << "��ġ" << endl;
	}
	else {
		cout << "����ġ" << endl;
	}
	if (a == "�̼���") {
		cout << "��ġ" << endl;
	}
	else {
		cout << "����ġ" << endl;
	}
	return 0;
}