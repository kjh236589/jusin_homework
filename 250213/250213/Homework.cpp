#include "pch.h"

class CStudent {
private:
	char szName[32] = {};
	int iKor, iMath, iEng, iTotal;
	float fAvg;
public:
	CStudent() {
		iKor = iMath = iEng = iTotal = 0;
		fAvg = 0.f;
	}

	void InputStudent() {
		system("cls");
		cout << "������ �Է��ϼ���(�̸�, ����, ����, ����) : ";
		cin >> szName >> iKor >> iMath >> iEng;
		iTotal = iKor + iMath + iEng;
		fAvg = (float)iTotal / 3.f;
	}

	void Print() {
		cout << "�̸� : " << szName << endl;
		cout << "���� : " << iKor << endl;
		cout << "���� : " << iMath << endl;
		cout << "���� : " << iEng << endl;
		cout << "���� : " << iTotal << endl;
		cout << "��� : " << fAvg << endl;
		cout << "==============================================" << endl;
	}

	bool Search(char szname[32]) {
		for (int i = 0; i < 32; ++i) {
			if (szName[i] != szname[i]) {
				return false;
			}
		}
		Print();
		return true;
	}
};

class CStudents {
private:
	CStudent* pStudents;
	int iSize;
public:
	CStudents() {
		iSize = 0;
		pStudents = nullptr;
	}
	~CStudents(){
		delete[] pStudents;
		pStudents = nullptr;
	}

	void InputStudents() {
		system("cls");
		if (!iSize) {
			cout << "�л��� ������� �Է��Ͻÿ� : ";
			cin >> iSize;
			pStudents = new CStudent[iSize];
			for (int i = 0; i < iSize; i++) {
				pStudents[i].InputStudent();
			}
		}
		else {
			CStudent* newStudents = new CStudent[iSize + 1];
			for (int i = 0; i < iSize; i++) {
				newStudents[i] = pStudents[i];
			}
			delete[] pStudents;
			pStudents = newStudents;
			pStudents[iSize].InputStudent();
			++iSize;
		}
	}

	void PrintStudents() {
		system("cls");
		for (int i =0; i < iSize; i++) {
			pStudents[i].Print();
		}
		system("pause");
	}
	
	void SearchStudents() {
		system("cls");
		char szName[32] = {};
		cout << "�˻��� �̸��� �Է����ּ��� : ";
		cin >> szName;
		for (int i = 0; i < iSize; i++) {
			if (pStudents[i].Search(szName)) {
				system("pause");
				return;
			}
		}
		cout << "�ش�Ǵ� �̸��� �������� �ʽ��ϴ�." << endl;
		system("pause");
	}
};

int main() {
	CStudents cStudents;
	int iInput(0);
	while (1) {
		system("cls");
		cout << "1. �Է� 2. ��� 3. �˻� 4. ���� : ";
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			cStudents.InputStudents();
			break;
		case 2:
			cStudents.PrintStudents();
			break;
		case 3:
			cStudents.SearchStudents();
			break;
		case 4:
			cout << "�����մϴ�." << endl;
			return 0;
		default:
			cout << "�߸��� �Է��Դϴ�." << endl;
			system("pause");
			break;
		}
	}
	return 0;
}

/*
	- Ŭ������ �̿��Ͽ� ����ǥ �����(���� �迭�� �̿��Ͽ� �����)
		1. �Է� 2. ��� 3. �˻� 4. ����
		- ���� �Է� �� ������� �Է�
		- �� ��° �Էº��ʹ� ���� �Է� �ο� + ���Ӱ� �߰��ϴ� �ο��� ���°� �ǵ��� ����
*/