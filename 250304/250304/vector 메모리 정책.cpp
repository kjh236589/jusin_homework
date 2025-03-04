#include "pch.h"

int main()
{
	vector<int>		vecInt;	// 자동으로 0 초기화된 배열 10개 생성

	vecInt.reserve(10);

	cout << "사이즈 : " << vecInt.size() << "\t 카파시티 : " << vecInt.capacity() << endl;

	vecInt.push_back(10);

	cout << "사이즈 : " << vecInt.size() << "\t 카파시티 : " << vecInt.capacity() << endl;

	//cout << "사이즈 : " << vecInt.size() << "\t 카파시티 : " << vecInt.capacity() << endl; 
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
	// cout << "사이즈 : " << vecInt.size() << "\t 카파시티 : " << vecInt.capacity() << endl;
	// 
	// for (size_t i = 0; i < vecInt.size(); ++i)
	// {
	// 	cout << vecInt[i] << endl;
	// }
	return 0;
}