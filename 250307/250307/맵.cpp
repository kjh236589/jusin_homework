#include "pch.h"

int main()
{
	map<int, int>		mapInt;

	// 1. pair ��ü�� �̿��� ���� �߰�
	pair<int, int>		MyPair;

	MyPair.first = 1;
	MyPair.second = 100;
	mapInt.insert(MyPair);
		
	// 2.pair �ӽ� ��ü�� �̿��� ���� �߰�
	mapInt.insert(pair<int, int>(2, 200));

	// 3. make_pair �Լ��� �̿��� ���� �߰�
	mapInt.insert(make_pair(3, 300));

	// 4. value_type ��ü�� �̿��� ���� �߰�
	map<int, int>::value_type		MyValue(4, 400);

	// MyValue.first = 4;
	// MyValue.second = 400;
	mapInt.insert(MyValue);

	// 5. value_type �ӽ� ��ü�� �̿��� ���� �߰�
	mapInt.insert(map<int, int>::value_type(5, 500));

	// 6. []�� �̿��� ���� �߰�
	mapInt[6] = 600;

	// 7. ������ �ʱ�ȭ�� �̿��� ���� �߰�
	mapInt.insert({ 7, 700 });

	// 8. emplace �Լ��� �̿��� ���� �߰�
	mapInt.emplace(8, 800);

	//for (map<int, int>::iterator iter = mapInt.begin();
	//	iter != mapInt.end(); ++iter)
	//{
	//	// cout << (*iter) << endl;
	//
	//	cout << iter->first << "\t" << iter->second << endl;
	//}

	cout << mapInt[3] << endl;



	return 0;
}