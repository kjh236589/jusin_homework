#include "pch.h"

struct tagInfo {				// struct �⺻������ public
	int iA;					// ��� ����
	void Draw() {			// ��� �Լ�
		iA = 200;			// ���� ����
		cout << iA << endl;
	}
};

class CObj {					// class �⺻������ private
private:						// private���� �����ϸ� �ܺο��� ���� �Ұ�
	int iA;					// ��� ����
public:						// public���� �����ϸ� �ܺο��� ���� ����
	void Draw() {			// ��� �Լ�
		iA = 200;			// ���� ����
		cout << iA << endl;
	}
};

int main()
{
	// 1. ����ȭ : �������� ��ȣ�� �ϱ� ���� �������� ����
	//	- ���� ���� ������
	//	- acess method	: GET, SET �Լ��� �̿��Ͽ� ��� ������ �б� �� ���⸦ ���

	tagInfo tInfo;

	tInfo.iA = 100;			// �ܺ� ����
	cout << tInfo.iA << endl;

	tInfo.Draw();

	return 0;
}

/*
	- Ŭ������ �̿��Ͽ� ����ǥ �����(���� �迭�� �̿��Ͽ� �����)
		1. �Է� 2. ��� 3. �˻� 4. ����
		- ���� �Է� �� ������� �Է�
		- �� ��° �Էº��ʹ� ���� �Է� �ο� + ���Ӱ� �߰��ϴ� �ο��� ���°� �ǵ��� ����
*/