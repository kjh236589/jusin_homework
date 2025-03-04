#include"pch.h"
#include<vector>

typedef struct sInfo {
	char* szName = new char[32];
	int iMath, iKor, iEng, iSum;
	float fAvg;
}INFO;

class School {
public:
	void AddStudents() {
		system("cls");
		int iInput(0);
		cout << "학생 수를 입력해주세요. : ";
		cin >> iInput;
		if (vecStudents.size() + iInput > vecStudents.capacity()) {
			vecStudents.reserve(vecStudents.size() + iInput);
		}
		system("cls");
		for (int i = 0; i < iInput; ++i) {
			INFO sInfo = {};
			cout << "이름을 입력해주세요 : ";
			cin >> sInfo.szName;
			cout << "수학 점수를 입력해주세요 : ";
			cin >> sInfo.iMath;
			cout << "국어 점수를 입력해주세요 : ";
			cin >> sInfo.iKor;
			cout << "영어 점수를 입력해주세요 : ";
			cin >> sInfo.iEng;
			sInfo.iSum = sInfo.iMath + sInfo.iKor + sInfo.iEng;
			sInfo.fAvg = sInfo.iSum / 3;
			vecStudents.push_back(sInfo);
			system("cls");
		}
	}

	void Print() {
		system("cls");
		for (vector<INFO>::iterator iter = vecStudents.begin();
			iter != vecStudents.end(); ++iter)
		{
			cout << "이름 : " << (*iter).szName << endl << "수학 : " << (*iter).iMath << endl 
				<< "국어 : " << (*iter).iKor << endl << "영어 : " << (*iter).iEng << endl 
				<< "총점 : " << (*iter).iSum << endl << "평균 : " << (*iter).fAvg << endl 
				<< "==========================" << endl;
		}
		system("pause");
	}

	void Print(vector<INFO>::iterator iter) {
		system("cls");
		cout << "이름 : " << (*iter).szName << endl << "수학 : " << (*iter).iMath << endl
			<< "국어 : " << (*iter).iKor << endl << "영어 : " << (*iter).iEng << endl
			<< "총점 : " << (*iter).iSum << endl << "평균 : " << (*iter).fAvg << endl;
		system("pause");
	}

	void Search() {
		system("cls");
		cout << "이름을 입력해주세요 : ";
		char* name = new char[32];
		cin >> name;
		system("cls");
		for (vector<INFO>::iterator iter = vecStudents.begin();
			iter != vecStudents.end(); ++iter)
		{
			if (!strcmp(name, (*iter).szName)) {
				Print(iter);
				return;
			}
		}
		cout << "해당하는 학생이 존재하지 않습니다." << endl;
	}

	void Delete() {
		system("cls");
		cout << "이름을 입력해주세요 : ";
		char* name = new char[32];
		cin >> name;
		system("cls");
		for (vector<INFO>::iterator iter = vecStudents.begin();
			iter != vecStudents.end(); ++iter)
		{
			if (!strcmp(name, (*iter).szName)) {
				vecStudents.erase(iter);
				return;
			}
		}
		cout << "해당하는 학생이 존재하지 않습니다." << endl;
	}
private :
	vector<INFO> vecStudents;
};

int main() {
	School school;
	int iInput(0);
	while (true) {
		system("cls");
		cout << "1. 입력, 2. 출력 3. 검색 4. 삭제 5. 종료 : ";
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			school.AddStudents();
			break;
		case 2:
			school.Print();
			break;
		case 3:
			school.Search();
			break;
		case 4:
			school.Delete();
			break;
		case 5:
			return 0;
		default:
			cout << "잘못된 입력입니다." << endl;
			break;
		}
	}
	return 0;
}