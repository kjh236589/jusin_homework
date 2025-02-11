#include <iostream>

using namespace std;

#include "pch.h"

int main()
{
	FILE* pLoadImage = NULL;
	FILE* pCopyImage = NULL;
	errno_t errLoad = fopen_s(&pLoadImage, "../Data/Image.jpg", "rb");
	if (0 == errLoad)
	{
		cout << "이미지 로드 성공" << endl;
		errno_t errSave = fopen_s(&pCopyImage, "../Data/Image_복사.jpg", "wb");
		if (0 == errSave)
		{
			cout << "이미지 복사 성공" << endl;
			char image[1] = {};
			while (0 == feof(pLoadImage))
			{
				image[0] = fgetc(pLoadImage);
				fwrite(image, sizeof(image), 1, pCopyImage);
			}
		}
		else
			cout << "복사 실패" << endl;
		fclose(pCopyImage);
	}
	else
		cout << "이미지 로드 실패" << endl;
	fclose(pLoadImage);
	return 0;
}