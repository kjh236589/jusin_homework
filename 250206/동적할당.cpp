#include<iostream>

using namespace std;

char* Func() {
	// char szName[32] = "";
	int iInput(0);
	cin >> iInput;

	char* pSour = (char*)malloc(iInput);
	cin >> pSour;

	return pSour;
}

int main() {
	char* pName = Func();
	cout << pName << endl;

	

	///////////////////////////////////////////////////////
	
	// ? �ּ� malloc(heap �޸𸮿� �Ҵ��� �޸� ũ��)
	// void* : �ּ��̱� ������ � �ڷ����� �ּ����� �� ��� ���
	// - ��� ������ ������� �� ��ȯ�� �����ؾ� �Ѵ�.
	// void* __cdecl malloc(size_t _Size);

	int* p = (int*)malloc(sizeof(int) * 4);		// heap ������ 4����Ʈ ũ���� �޸� �Ҵ� �� , �� ������ 

	// cout << p << endl;
	// cout << *p << endl;
	p[0] = 10;
	p[1] = 20;
	p[2] = 30;
	p[3] = 40;

	for (int i = 0; i < 4; ++i) {
		cout << p[i] << endl; 
	}

	return 0;
}
/*
	
*/