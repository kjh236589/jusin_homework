#include "pch.h"

using namespace std;

template<typename T>
void Safe_Delete(T& p)
{
	if (p) { delete p; p = nullptr; }
}


class CObj
{
public:
	CObj(int _iA) : m_iA(_iA){}

public:
	int		Get_A() { return m_iA; }

private:
	int m_iA;
};

int main()
{
	vector<CObj*>		m_vecObj;

	m_vecObj.push_back(new CObj(10));
	m_vecObj.push_back(new CObj(20));
	m_vecObj.push_back(new CObj(30));
	m_vecObj.push_back(new CObj(40));
	m_vecObj.push_back(new CObj(50));

	for (vector<CObj*>::iterator iter = m_vecObj.begin();
		iter != m_vecObj.end(); )
	{
		if (30 == (*iter)->Get_A())
		{
			Safe_Delete<CObj*>(*iter);

			iter = m_vecObj.erase(iter);
		}
		else
		{
			++iter;
		}
	}


	// vector<int>		vecInt;
	// 
	// vecInt.push_back(1);
	// vecInt.push_back(2);
	// vecInt.push_back(3);
	// vecInt.push_back(4);
	// vecInt.push_back(5);
	// 
	// // cout << vecInt.front() << endl;
	// // cout << vecInt.back() << endl;
	// 
	// // vecInt.front() = 100;		// �� ����, �б� ��� ����
	// // vecInt.back()  = 500;
	// 
	// vector<int>::iterator iter = vecInt.begin(); // +2;	// ���� ���� �ݺ����� �� 1
	// 
	// iter += 2;											// ���� ���� �ݺ����� �� 2
	// 
	// 
	// // ���Ҹ� �߰��� �����ϴ� �Լ�
	// //iter = vecInt.insert(iter, 999);
	// 
	// // ���Ҹ� �߰��� �����ϴ� �Լ�
	// iter = vecInt.erase(iter);
	// 
	// cout << (*iter) << endl;

	//for(iter = vecInt.begin(); iter != vecInt.end(); ++iter)
	//	cout << (*iter) << endl;


	// for (vector<int>::iterator iter = vecInt.begin();
	// 	iter != vecInt.end(); 
	// 	++iter)
	// {
	// 	cout << (*iter) << endl;
	// }


	//for (size_t i = 0; i < vecInt.size(); ++i)
	//{
	//	cout << vecInt[i] << endl;
	//}

	//�ݺ��� : �����̳ʿ� ����Ǿ� �ִ� ���� ������ ������ �����ϴ� ��ü

	// 1. ��� �ݺ��� 2. �Է� �ݺ��� 3. ������ �ݺ��� 4. ����� �ݺ���   5. ���� ���� �ݺ���
	// const *		 *, =		  *, =, ++	     *, =, ++, --	  *, =, ++, --, +=, -=

	return 0;
}

// 1. vector �� �̿��Ͽ� ����ǥ ���α׷� �����(����)
// 1. �Է� 2. ��� 3. �˻� 4. ���� 5. ����

// 2. TRPG ������ �����
// - �κ��丮, ������ ����
// - VECTOR�� �̿��Ͽ� �κ��丮 �����(5ĭ ����)