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
	
	// ? 주소 malloc(heap 메모리에 할당할 메모리 크기)
	// void* : 주소이긴 하지만 어떤 자료형의 주소인지 모를 경우 사용
	// - 사용 시점에 명시적인 형 변환을 수행해야 한다.
	// void* __cdecl malloc(size_t _Size);

	int* p = (int*)malloc(sizeof(int) * 4);		// heap 영영에 4바이트 크기의 메모리 할당 후 , 그 공간의 

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