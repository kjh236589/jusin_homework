#include "pch.h"

int main()
{
	// 바이너리 입출력 모드

	// c언어 사용하는 바이너리 모드 출력 함수
	// fwrite(출력할 메모리의 시작 주소, 출력할 메모리의 사이즈, 출력할 메모리의 개수, 개방 스트림)
	// size_t fwrite(void const* _Buffer, size_t _ElementSize,size_t _ElementCount, FILE * _Stream    )

	//FILE* pSaveFile = NULL;

	//int	iArray[5] = { 1, 2, 3 ,4, 5 };

	//errno_t errSave = fopen_s(&pSaveFile, "../Data/Array.dat", "wb");

	//if (0 == errSave)
	//{
	//	//fwrite(iArray, sizeof(int), 5, pSaveFile);
	//	fwrite(iArray, sizeof(iArray), 1, pSaveFile);
	//}
	//else
	//	cout << "개방 실패" << endl;


	// fread(입력할 메모리의 시작 주소, 입력할 메모리의 사이즈, 입력할 메모리의 개수, 개방 스트림)
	// size_t fread(void const* _Buffer, size_t _ElementSize,size_t _ElementCount, FILE * _Stream    )

	FILE* pLoadFile = NULL;

	int	iTemp[5] = {  };

	errno_t errLoad = fopen_s(&pLoadFile, "../Data/Array.dat", "rb");

	if (0 == errLoad)
	{
		//fread(iTemp, sizeof(int), 5, pSaveFile);
		fread(iTemp, sizeof(iTemp), 1, pLoadFile);
	}
	else
		cout << "개방 실패" << endl;

	for (int i = 0; i < 5; ++i)
		cout << iTemp[i] << " ";

	cout << endl;


	return 0;
}