#include "pch.h"


int main()
{
	// 경로 
	// 
	// - 절대 경로 : 드라이브명부터 현재 파일의 위치까지 모든 경로를 표현한 상태
	// - 상대 경로 : 프로젝트 파일을 기준으로 모든 경로를 표현한 상태

	// 파일 입출력의 순서

	// 1. 파일을 개방(스트림 생성)
	// 
	// 2. 입, 출력 함수 호출
	// 
	// 3. 개방 시킨 파일을 소멸


	// 1. 파일 개방 함수

	// 핸들 : 운영체제가 리소스(프로세스, 쓰레드, 파일)를 알아보기 위한 고유한 식별 번호(정수)

	//FILE* pFile = NULL;

	// (개방한 스트림을 저장할 포인터, 파일 이름을 포함한 경로, 입출력 모드)
	// errno_t  fopen_s(FILE**_Stream, char const* _FileName, char const* _Mode);

	// errno_t  err = fopen_s(&pFile, "../Data/Test.txt", "wt");
	// 
	// if (0 == err)
	// {
	// 	// 2. 입 출력 함수 호출
	// 			
	// 	fputs("world", pFile);
	// 
	// 	cout << "저장 성공" << endl;
	// 
	// 	// 3. 개방한 파일 소멸
	// 	fclose(pFile);
	// }
	// else
	// {
	// 	cout << "파일 개방 실패" << endl;
	// }

	// FILE* pLoadFile = NULL;
	// 
	// errno_t  err = fopen_s(&pLoadFile, "../Data/Test.txt", "rt");
	// 
	// char	szName[32] = "";
	// 
	// if (0 == err)
	// {
	// 
	// 	fgets(szName, sizeof(szName), pLoadFile);
	// 
	// 	fputs(szName, stdout);
	// 
	// 	cout << "불러오기 성공" << endl;
	// 	fclose(pLoadFile);
	// }
	// 
	// else
	// {
	// 	cout << "파일 개방 실패" << endl;
	// }


#pragma region 파일 함수

	// fseek : 파일 지시자(커서)의 위치를 원하는 위치로 변경시키는 함수

	// fseek(파일 스트림, 이동할 바이트 수, 커서의 시작 지점)
	// int fseek(FILE * _Stream, long  _Offset, int   _Origin)

	// ftell : 현재 파일 지시사의 위치를 알려주는 함수, 첫 시작 위치는 0부터 시작

	// feof : 파일 지시자가 eof의 위치에 도달했는지 검사하는 함수, 파일 끝에 도달한 경우 0이 아닌 값을 반환

	// FILE* pFile = NULL;
	// 
	// errno_t  err = fopen_s(&pFile, "../Data/Test.txt", "rt");
	// 
	// if (0 == err)
	// {
	// 	// fseek(pFile, 3, SEEK_SET);
	// 	// 
	// 	// char cName = fgetc(pFile);
	// 	// 
	// 	// cout << "현재 지시자 위치 : " << ftell(pFile) << endl;
	// 	// cout << "현재 위치의 글자 : " << cName << endl;
	// 
	// 	while (0 == feof(pFile))
	// 	{
	// 		fputc(fgetc(pFile), stdout);
	// 	}
	// 
	// 	fclose(pFile);
	// }
	// else
	// 	cout << "개방 실패" << endl;



#pragma endregion







	return 0;
}