#include<iostream>

using namespace std;

void Rotation(int iArray[3][3]);

void Print(int iArray[3][3]);

int main() {
	int iArray[3][3] = {};
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			iArray[i][j] = ((i * 3) + j) + 1;
		}
	}
	for (int i = 0; i < 5; ++i) {
		cout << i << "È¸Àü" << endl;
		Print(iArray);
		Rotation(iArray);
		cout << endl << "==================" << endl << endl;
	}
	return 0;
}

void Rotation(int iArray[3][3]) {
	int iRotation[3][3] = {};
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			iRotation[i][j] = iArray[2 - j][i];
			// iRotation[j][2 - i] = iArray[i][j];
		}
	}
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			iArray[i][j] = iRotation[i][j];
		}
	}
}

void Print(int iArray[3][3]) {
	int iRotation[3][3] = {};
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			cout << iArray[i][j] << "\t";
		}
		cout << endl;
	}
}