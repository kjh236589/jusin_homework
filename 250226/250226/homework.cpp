#include "pch.h"
#include "String.h"

int main() {
	String a;
	a = "ȫ";
	cout << a() << endl;
	a = a + "�浿";
	cout << a() << endl;
	if (a == "ȫ�浿") {
		cout << "��ġ" << endl;
	}
	else {
		cout << "����ġ" << endl;
	}
	return 0;
}