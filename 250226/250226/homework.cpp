#include "pch.h"
#include "String.h"

int main() {
	String a;
	a = "홍";
	cout << a() << endl;
	a = a + "길동";
	cout << a() << endl;
	if (a == "홍길동") {
		cout << "일치" << endl;
	}
	else {
		cout << "불일치" << endl;
	}
	return 0;
}