// Project1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"

int main()
{
	// 입출력 : 외부의 데이터가 프로그램 안으로 흘러 들어온 것을 뜻함
	
	// 스트림 : 개울, 시냇물, 장치들을 연결해주는 가상의 통로
	// 버퍼 : 데이터 송수신의 효율성을 위해 데이터를 저장하는 임시 메모리 공간 상태
	
	///////////////////////// 콘솔 입출력 /////////////////////////////

	// 입출력 시 사용 가능한 함수 집단

	// 문자열 입출력 함수
	//		- 콘솔에서만 사용 가능한 입출력 함수
	//		- 범용적으로 사용 가능한 입출력 함수
	// 
	// 텍스트 모드와 바이너리 모드
	//		- 텍스트 모드 : 문자열을 저장하고 불러오기
	//		- 바이너리 모드 : 문자열이 아닌 형식의 데이터를 이진수로 치환하여 저장하고 불러오기
	// 
	// stdin	: 표준 입력 스트림
	// stdout	: 표준 출력 스트림
	// stderr	: 표준 에러 스트림
	//	- 단일 문자 출력 함수 : putchar, fputc
	//

	// putchar('A');
	// putchar(97);
	
	// fputc('B', stdout);
	// 
	//	- 단일 문자 입력 함수 : getchar, fgetc

	// char cName = getchar();
	// putchar(cName);

	// char cName = fgetc(stdin);
	// fputc(cName, stdout);

	// EOF : end of file의 줄임말 파일의 끝에 도달했음을 알려주는 값

	// while (true) {
	// 	char ch = getchar();
	// 	if (EOF == ch) {		// ctrl + Z를 입력버퍼에 삽입
	// 		break;
	// 	}
	// 	if ('a' <= ch && 'z' >= ch) {
	// 		ch -= 32;
	// 	}
	// 	else if ('A' <= ch && 'Z' >= ch) {
	// 		ch += 32;
	// 	}
	// 	putchar(ch);
	// }

	// 문자열 출력 함수 : puts, fputs

	// puts("hello");				// 자동 개행을 지원
	// fputs("hello", stdout);		// 자동 개행을 지원하지 않음

	// 문자열 입력 함수 : gets_s, fgets

	// char szName[32];
	// 
	// char* pName = szName;
	// cin >> pName;
	// cout << pName << endl;

	// char* pName = gets_s(szName, sizeof(szName));		// 공백은 읽을 수 있으나 enter는 읽을 수 없다
	// puts(pName);

	// char* pName = fgets(szName, sizeof(szName), stdin);		// 공백도 읽어 들이며 enter도 알앗 설정한 사이즈 만큼 읽어들임, '\0' 문자도 읽음
	// fputs(pName, stdout);

	// 출력 버퍼 비우기 : 비우다는 뜻은 삭제가 아니라 목적지로 데이터를 전송하는 행위를 말함
	// fflush(stdout)

	// char szID[9] = "";
	// char szName[16] = "";
	// fgets(szID, sizeof(szID), stdin);
	// while ('\n' != getchar());
	// fgets(szName, sizeof(szName), stdin);
	// 
	// 
	// fputs(szID, stdout);
	// fputs(szName, stdout);
	return 0;
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
