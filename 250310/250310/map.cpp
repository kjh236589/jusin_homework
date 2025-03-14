// 250310.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"

struct tagFinder
{
	tagFinder(const char* pTag) : m_pTag(pTag) {}

	template<typename T>
	bool operator()(T& MyPair)
	{
		return !strcmp(MyPair.first, m_pTag);
	}

	const char* m_pTag;
};

int main()
{
	//map<int, int, less<int>>		mapInt;
	//
	//mapInt.insert({ 1, 100 });
	//mapInt.insert({ 2, 200 });
	//mapInt.insert({ 3, 300 });
	//mapInt.insert({ 4, 400 });
	//mapInt.insert({ 5, 500 });
	//mapInt.insert({ 6, 600 }); 
	//mapInt.insert({ 7, 700 });
		
	// map<int, int>::iterator		iter = mapInt.begin();
	// 
	// ++iter;
	// ++iter;
	// 
	// // 연관 컨테이너는 중간 삽입이 사실상 의미가 없다
	// mapInt.insert(iter, { 9, 999999 });

	// map<int, int>::iterator			iter = mapInt.find(5);
	// 
	// cout << iter->first << "\t" << iter->second << endl;

	//for( iter = mapInt.begin(); iter != mapInt.end(); ++iter)
	//	cout << iter->first << "\t" << iter->second << endl;

	////////////////////////////////////////////////////////////////

	// map<const char*, int>			mapCmp;
	// 
	// mapCmp.insert({ "AAA", 100 });
	// mapCmp.insert({ "BBB", 200 });
	// mapCmp.insert({ "CCC", 300 });

	// map<const char*, int>::iterator	iter = mapCmp.find("BBB");

	// if (iter == mapCmp.end())
	// {
	// 	cout << "원소가 없음" << endl;
	// }

	// map<const char*, int>::iterator	iter = find_if(mapCmp.begin(), mapCmp.end(), tagFinder("BBB"));
	// 
	// if (iter == mapCmp.end())
	// {
	// 	cout << "원소가 없음" << endl;
	// }
	// else
	// {
	// 	cout << iter->first << "\t" << iter->second << endl;
	// }
	
	// cout << mapCmp["BBB"] << endl;

	//////////////////////////////////////////////////////////////////
	// 키 값이 문자열일 때, 알파벳 정렬은 어떻게 할 것인가?

	// 1. char(단일 문자)가 key 일 때 : 알파벳 정렬 가능
	// 2. char*(문자열 포인터)가 key 일 때 : 주소를 대소 비교하여 정렬
	// 3. string이 key 일 때 : 알파벳 정렬(문자열 관련 대소 비교 조건자가 삽입)

	// multimap<int, int>		multiInt;
	// 
	// multiInt.insert({ 1, 100 });
	// multiInt.insert({ 1, 200 });
	// multiInt.insert({ 1, 300 });
	// multiInt.insert({ 1, 400 });
	// 
	// multimap<int, int>::iterator			iter = multiInt.begin();
	// 
	// for (; iter != multiInt.end(); ++iter)
	// 	cout << iter->first << "\t" << iter->second << endl;

	return 0;
}
