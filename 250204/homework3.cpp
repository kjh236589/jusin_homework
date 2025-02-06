#include<iostream>
#include<ctime>

using namespace std;

/// <summary>
/// �迭�� ����ϴ� �Լ�, 0�� *���� �����
/// </summary>
/// <param name="iBingo">�迭</param>
/// <param name="iSize">�迭�� ũ��</param>
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
/// �Էµ� ���� 0���� �ٲ��ִ� �Լ�
/// </summary>
/// <param name="iBingo">�迭</param>
/// <param name="iIndex">�Է¹޴� ��</param>
int Input(int iBingo[], int iIndex) {
	if (iBingo[iIndex - 1]) {
		iBingo[iIndex - 1] = 0;
		return 0;
	}
	return 1;
}


/// <summary>
/// ������ ������ Ȯ���ϴ� �Լ�
/// </summary>
/// <param name="iBingo">�迭</param>
/// <param name="pWin">�¸� Ƚ�� ���� ����Ʈ</param>
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
		cout << "Player" << endl << iWin << "����" << endl;
		Print(iBingo, sizeof(iBingo) / sizeof(int));
		cout << "Computer" << endl << iLose << "����" << endl;
		Print(iBingoCom, sizeof(iBingoCom) / sizeof(int));
		if (5 <= iWin || 5 <= iLose) {
			if (iWin == iLose) {
				cout << "���º�!" << endl;
			}
			else if(iWin > iLose) {
				cout << "�÷��̾� �¸�!" << endl;
			}
			else {
				cout << "��ǻ�� �¸�!" << endl;
			}
			break;
		}
		cout << "1~25�� ���ڸ� �Է����ּ��� : ";
		cin >> iInput;
		if (0 >= iInput || 25 < iInput) {
			cout << "�߸��� �Է��Դϴ�. 1~25�� ���ڸ� �Է����ּ���." << endl;
			system("pause");
		}
		else {
			if (Input(iBingo, iInput)) {
				cout << "�̹� �Է��ߴ� ���Դϴ�." << endl;
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