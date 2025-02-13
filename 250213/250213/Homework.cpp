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
		cout << "성적을 입력하세요(이름, 국어, 수학, 영어) : ";
		cin >> szName >> iKor >> iMath >> iEng;
		iTotal = iKor + iMath + iEng;
		fAvg = (float)iTotal / 3.f;
	}

	void Print() {
		cout << "이름 : " << szName << endl;
		cout << "국어 : " << iKor << endl;
		cout << "수학 : " << iMath << endl;
		cout << "영어 : " << iEng << endl;
		cout << "총점 : " << iTotal << endl;
		cout << "평균 : " << fAvg << endl;
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
			cout << "학생이 몇명인지 입력하시오 : ";
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
		cout << "검색할 이름을 입력해주세요 : ";
		cin >> szName;
		for (int i = 0; i < iSize; i++) {
			if (pStudents[i].Search(szName)) {
				system("pause");
				return;
			}
		}
		cout << "해당되는 이름이 존재하지 않습니다." << endl;
		system("pause");
	}
};

int main() {
	CStudents cStudents;
	int iInput(0);
	while (1) {
		system("cls");
		cout << "1. 입력 2. 출력 3. 검색 4. 종료 : ";
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
			cout << "종료합니다." << endl;
			return 0;
		default:
			cout << "잘못된 입력입니다." << endl;
			system("pause");
			break;
		}
	}
	return 0;
}

/*
	- 클래스를 이용하여 성적표 만들기(동적 배열을 이용하여 만들기)
		1. 입력 2. 출력 3. 검색 4. 종료
		- 최초 입력 시 몇명인지 입력
		- 두 번째 입력부터는 기존 입력 인원 + 새롭게 추가하는 인원의 형태가 되도록 구현
*/