#include "pch.h"

int main()
{
	vector<int>			vecInt;	// 템플릿 클래스

	vecInt.push_back(10);
	vecInt.push_back(20);
	vecInt.push_back(30);
	vecInt.push_back(40);

	vecInt.clear();
	cout << vecInt.capacity() << endl;

	// vector<int>().swap(vecInt);

	vecInt.shrink_to_fit();

	cout << "--------------------------------------" << endl;

	cout << vecInt.capacity() << endl;

	//vector<int>			vecTemp;
	//
	//vecTemp.push_back(1);
	//vecTemp.push_back(2);
	//vecTemp.push_back(3);
	//vecTemp.push_back(4);
	//vecTemp.push_back(5);
	//vecTemp.push_back(6);
	//vecTemp.push_back(7);
	//vecTemp.push_back(8);
	//
	//// swap : 같은 자료를 저장하는 컨테이너의 원소와 메모리 공간 모두를 교환
	//
	//vecInt.swap(vecTemp);
	//
	//for (size_t i = 0; i < vecInt.size(); ++i)
	//{
	//	cout << vecInt[i] << endl;
	//}
	//cout << "--------------------------------------" << endl;
	//cout << vecInt.capacity() << endl;
	//cout << "--------------------------------------" << endl;
	//
	//for (size_t i = 0; i < vecTemp.size(); ++i)
	//{
	//	cout << vecTemp[i] << endl;
	//}
	//cout << "--------------------------------------" << endl;
	//cout << vecTemp.capacity() << endl;







	// for (int i = 0; i < 20; ++i)
	// {
	// 	//cout << "사이즈 : " << vecInt.size() << "\t 카파시티 : " << vecInt.capacity() << endl;
	// 	vecInt.push_back(i);
	// 
	// 	cout << vecInt[i] << endl;
	// }
	// 
	// cout << "사이즈 : " << vecInt.size() << "\t 카파시티 : " << vecInt.capacity() << endl;
	// cout << "=======================================" << endl;
	// // clear : 컨테이너 안에 있는 원소들을 모두 제거, 메모리 제거와는 관계없음
	// vecInt.clear();	
	// 
	// //empty : 컨테이너 안에 원소의 유무를 판단, bool 타입 반환
	// 
	// if (vecInt.empty())
	// {
	// 	cout << "원소 모두 삭제" << endl;
	// }
	// else
	// {
	// 	for (size_t i = 0; i < vecInt.size(); ++i)
	// 	{
	// 		cout << vecInt[i] << endl;
	// 	}
	// }
	// 
	// cout << "사이즈 : " << vecInt.size() << "\t 카파시티 : " << vecInt.capacity() << endl;
	
	// vecInt.push_back(10);
	// vecInt.push_back(20);
	// vecInt.push_back(30);
	// vecInt.push_back(40);
	// 
	// //size : 컨테이너 안에 저장된 원소의 개수를 반환
	// 
	// for (size_t i = 0; i < vecInt.size(); ++i)
	// {
	// 	cout << vecInt[i] << endl;
	// }
	// 
	// cout << "사이즈 : " << vecInt.size() << "\t 카파시티 : " << vecInt.capacity() << endl;
	// 
	// 
	// vecInt.pop_back();
	// 
	// cout << "===============================" << endl;
	// 
	// for (size_t i = 0; i < vecInt.size(); ++i)
	// {
	// 	cout << vecInt[i] << endl;
	// }
	// 
	// cout << "사이즈 : " << vecInt.size() << "\t 카파시티 : " << vecInt.capacity() << endl;


   
	return 0;
}
