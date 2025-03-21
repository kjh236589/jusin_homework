#include "pch.h"

int main()
{
	map<int, int>		mapInt;

	// 1. pair 객체를 이용한 원소 추가
	pair<int, int>		MyPair;

	MyPair.first = 1;
	MyPair.second = 100;
	mapInt.insert(MyPair);
		
	// 2.pair 임시 객체를 이용한 원소 추가
	mapInt.insert(pair<int, int>(2, 200));

	// 3. make_pair 함수를 이용한 원소 추가
	mapInt.insert(make_pair(3, 300));

	// 4. value_type 객체를 이용한 원소 추가
	map<int, int>::value_type		MyValue(4, 400);

	// MyValue.first = 4;
	// MyValue.second = 400;
	mapInt.insert(MyValue);

	// 5. value_type 임시 객체를 이용한 원소 추가
	mapInt.insert(map<int, int>::value_type(5, 500));

	// 6. []를 이용한 원소 추가
	mapInt[6] = 600;

	// 7. 유니폼 초기화를 이용한 원소 추가
	mapInt.insert({ 7, 700 });

	// 8. emplace 함수를 이용한 원소 추가
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