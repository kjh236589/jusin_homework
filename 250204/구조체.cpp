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
	// 1. c��� �������� ����ü �ڷ��� ��� ��, �ݵ�� struct�� �ٿ��߸� �ߴ�.
	// 2. c++�� ����ü�� ��� �Լ� ������ �����ϴ�.
	struct tagInfo tInfo = { 10, 3.14f };
	INFO tInfo2 = { 10, 3.14f };

	PINFO pInfo = NULL;

	printf("%d\n", tInfo.iKor);
	printf("%d\n", tInfo2.iKor);

	tInfo.Render();

	return 0;
}