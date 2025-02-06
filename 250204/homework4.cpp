#include<iostream>

using namespace std;

void Up(int iArray[], int* pZero, int iSize);

void Down(int iArray[], int* pZero, int iSize);

void Left(int iArray[], int* pZero, int iSize);

void Right(int iArray[], int* pZero, int iSize);

int main() {
	int iArray[25] = {}, iZero(0), iInput(0);
	for (int i = 0; i < 25; ++i) {
		iArray[i] = i;
	}
	while (1) {
		for (int i = 0; i < 25; ++i) {
			if (0 != i && 0 == i % 5) {
				cout << endl;
			}
			cout << iArray[i] << "\t";
		}
		cout << endl << "이동할 위치를 입력하세요 2. 아래 4. 왼쪽 6. 오른쪽 8. 위 : ";
		cin >> iInput;
		switch (iInput)
		{
		case 2:
			Down(iArray, &iZero, 5);
			break;
		case 4:
			Left(iArray, &iZero, 5);
			break;
		case 6:
			Right(iArray, &iZero, 5);
			break;
		case 8:
			Up(iArray, &iZero, 5);
			break;
		default:
			break;
		}
		system("cls");
	}
	return 0;
}

void Up(int iArray[], int* pZero, int iSize) {
	swap(iArray[(0 <= *pZero - iSize) ? *pZero - iSize : *pZero], iArray[*pZero]);
	*pZero = (0 <= *pZero - iSize) ? *pZero - iSize : *pZero;
}

void Down(int iArray[], int* pZero, int iSize) {
	swap(iArray[(iSize * iSize > *pZero + iSize) ? *pZero + iSize : *pZero], iArray[*pZero]);
	*pZero = (iSize * iSize > *pZero + iSize) ? *pZero + iSize : *pZero;
}

void Left(int iArray[], int* pZero, int iSize) {
	swap(iArray[(0 != *pZero % iSize) ? *pZero - 1 : *pZero], iArray[*pZero]);
	*pZero = (0 != *pZero % iSize) ? *pZero - 1 : *pZero;
}

void Right(int iArray[], int* pZero, int iSize) {
	swap(iArray[(4 != *pZero % iSize) ? *pZero + 1 : *pZero], iArray[*pZero]);
	*pZero = (4 != *pZero % iSize) ? *pZero + 1 : *pZero;
}