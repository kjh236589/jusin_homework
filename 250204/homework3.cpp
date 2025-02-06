#include<iostream>
#include<ctime>

using namespace std;

/// <summary>
/// 배열을 출력하는 함수, 0은 *으로 출력함
/// </summary>
/// <param name="iBingo">배열</param>
/// <param name="iSize">배열의 크기</param>
void Print(int iBingo[], int iSize) {
	for (int i = 0; i < iSize; ++i) {
		if (0 != i && 0 == i % 5) {
			cout << endl;
		}
		if (iBingo[i] == 0) {
			cout << '*' << "\t";
		}
		else {
			cout << iBingo[i] << "\t";
		}
	}
	cout << endl;
}

/// <summary>
/// 입력된 값을 0으로 바꿔주는 함수
/// </summary>
/// <param name="iBingo">배열</param>
/// <param name="iIndex">입력받는 값</param>
int Input(int iBingo[], int iIndex) {
	if (iBingo[iIndex - 1]) {
		iBingo[iIndex - 1] = 0;
		return 0;
	}
	return 1;
}


/// <summary>
/// 빙고의 갯수를 확인하는 함수
/// </summary>
/// <param name="iBingo">배열</param>
/// <param name="pWin">승리 횟수 변수 포인트</param>
void Bingo(int iBingo[], int* pWin) {
	int iWin(0), iCount1(0), iCount2(0);
	for (int i = 0; i < 5; ++i) {
		iCount1 = iCount2 = 0;
		for (int j = 0; j < 5; ++j) {
			iCount1 += iBingo[(i * 5) + j];
			iCount2 += iBingo[(j * 5) + i];
		}
		if (iCount1 == 0) {
			++iWin;
		}
		if (iCount2 == 0) {
			++iWin;
		}
	}
	iCount1 = iCount2 = 0;
	for (int i = 0; i < 5; ++i) {
		iCount1 += iBingo[i * 6];
		iCount2 += iBingo[(i * 4) + 4];
	}
	if (iCount1 == 0) {
		++iWin;
	}
	if (iCount2 == 0) {
		++iWin;
	}
	*pWin = iWin;
}

int main() {
	srand(time(NULL));
	int iBingo[25] = {}, iBingoCom[25] = {}, iComRand[25] = {}, iInput(0), iWin(0), iLose(0);
	for (int i = 0; i < 25; ++i) {
		iBingo[i] = i + 1;
		iBingoCom[i] = i + 1;
		iComRand[i] = i + 1;
	}
	for (int i = 0; i < 500; ++i) {
		swap(iComRand[rand() % 25], iComRand[rand() % 25]);
	}
	for (int i = 0; i < sizeof(iBingo) / sizeof(int); ++i) {
		cout << "Player" << endl << iWin << "빙고" << endl;
		Print(iBingo, sizeof(iBingo) / sizeof(int));
		cout << "Computer" << endl << iLose << "빙고" << endl;
		Print(iBingoCom, sizeof(iBingoCom) / sizeof(int));
		if (5 <= iWin || 5 <= iLose) {
			if (iWin == iLose) {
				cout << "무승부!" << endl;
			}
			else if(iWin > iLose) {
				cout << "플레이어 승리!" << endl;
			}
			else {
				cout << "컴퓨터 승리!" << endl;
			}
			break;
		}
		cout << "1~25의 숫자를 입력해주세요 : ";
		cin >> iInput;
		if (0 >= iInput || 25 < iInput) {
			cout << "잘못된 입력입니다. 1~25의 숫자를 입력해주세요." << endl;
			system("pause");
		}
		else {
			if (Input(iBingo, iInput)) {
				cout << "이미 입력했던 값입니다." << endl;
				system("pause");
			}
			else {
				Bingo(iBingo, &iWin);
				Input(iBingoCom, iComRand[i]);
				Bingo(iBingoCom, &iLose);
			}
		}
		system("cls");
	}
	return 0;
}