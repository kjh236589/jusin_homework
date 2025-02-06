#include<stdio.h>

typedef int				BOOL;
typedef unsigned short	WORD;
typedef unsigned long	DWORD;

typedef int				errno_t;

typedef struct tagInfo {
	int iKor;
	float fAver;

	void Render() {
		printf("hello world\n");
	}
} INFO, * PINFO;

int main() {
	// 1. c언어 시절에는 구조체 자료형 사용 시, 반드시 struct를 붙여야만 했다.
	// 2. c++의 구조체는 멤버 함수 소유가 가능하다.
	struct tagInfo tInfo = { 10, 3.14f };
	INFO tInfo2 = { 10, 3.14f };

	PINFO pInfo = NULL;

	printf("%d\n", tInfo.iKor);
	printf("%d\n", tInfo2.iKor);

	tInfo.Render();

	return 0;
}