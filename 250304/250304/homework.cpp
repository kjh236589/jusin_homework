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
		cout << "�л� ���� �Է����ּ���. : ";
		cin >> iInput;
		if (vecStudents.size() + iInput > vecStudents.capacity()) {
			vecStudents.reserve(vecStudents.size() + iInput);
		}
		system("cls");
		for (int i = 0; i < iInput; ++i) {
			INFO sInfo = {};
			cout << "�̸��� �Է����ּ��� : ";
			cin >> sInfo.szName;
			cout << "���� ������ �Է����ּ��� : ";
			cin >> sInfo.iMath;
			cout << "���� ������ �Է����ּ��� : ";
			cin >> sInfo.iKor;
			cout << "���� ������ �Է����ּ��� : ";
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
			cout << "�̸� : " << (*iter).szName << endl << "���� : " << (*iter).iMath << endl 
				<< "���� : " << (*iter).iKor << endl << "���� : " << (*iter).iEng << endl 
				<< "���� : " << (*iter).iSum << endl << "��� : " << (*iter).fAvg << endl 
				<< "==========================" << endl;
		}
		system("pause");
	}

	void Print(vector<INFO>::iterator iter) {
		system("cls");
		cout << "�̸� : " << (*iter).szName << endl << "���� : " << (*iter).iMath << endl
			<< "���� : " << (*iter).iKor << endl << "���� : " << (*iter).iEng << endl
			<< "���� : " << (*iter).iSum << endl << "��� : " << (*iter).fAvg << endl;
		system("pause");
	}

	void Search() {
		system("cls");
		cout << "�̸��� �Է����ּ��� : ";
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
		cout << "�ش��ϴ� �л��� �������� �ʽ��ϴ�." << endl;
	}

	void Delete() {
		system("cls");
		cout << "�̸��� �Է����ּ��� : ";
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
		cout << "�ش��ϴ� �л��� �������� �ʽ��ϴ�." << endl;
	}
private :
	vector<INFO> vecStudents;
};

int main() {
	School school;
	int iInput(0);
	while (true) {
		system("cls");
		cout << "1. �Է�, 2. ��� 3. �˻� 4. ���� 5. ���� : ";
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
			cout << "�߸��� �Է��Դϴ�." << endl;
			break;
		}
	}
	return 0;
}