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
		cout << "�̹��� �ε� ����" << endl;
		errno_t errSave = fopen_s(&pCopyImage, "../Data/Image_����.jpg", "wb");
		if (0 == errSave)
		{
			cout << "�̹��� ���� ����" << endl;
			char* image = new char;
			while (0 == feof(pLoadImage))
			{
				*image = fgetc(pLoadImage);
				fwrite(image, sizeof(*image), 1, pCopyImage);
			}
			delete image;
			image = nullptr;
		}
		else {
			cout << "���� ����" << endl;
		}
		if (pCopyImage) {
			fclose(pCopyImage);
		}
	}
	else {
		cout << "�̹��� �ε� ����" << endl;
	}
	if (pLoadImage) {
		fclose(pLoadImage);
	}
	return 0;
}