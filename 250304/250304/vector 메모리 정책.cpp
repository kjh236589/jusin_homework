#include "pch.h"

int main()
{
	vector<int>		vecInt;	// �ڵ����� 0 �ʱ�ȭ�� �迭 10�� ����

	vecInt.reserve(10);

	cout << "������ : " << vecInt.size() << "\t ī�Ľ�Ƽ : " << vecInt.capacity() << endl;

	vecInt.push_back(10);

	cout << "������ : " << vecInt.size() << "\t ī�Ľ�Ƽ : " << vecInt.capacity() << endl;

	//cout << "������ : " << vecInt.size() << "\t ī�Ľ�Ƽ : " << vecInt.capacity() << endl; 
	//
	//for (size_t i = 0; i < vecInt.size(); ++i)
	//{
	//	cout << vecInt[i] << endl;
	//}

	// vecInt.push_back(10);
	// vecInt[0] = 10;

	// vecInt.resize(3);
	// 
	// cout << "--------------------------------" << endl;
	// 
	// cout << "������ : " << vecInt.size() << "\t ī�Ľ�Ƽ : " << vecInt.capacity() << endl;
	// 
	// for (size_t i = 0; i < vecInt.size(); ++i)
	// {
	// 	cout << vecInt[i] << endl;
	// }
	return 0;
}