#include "pch.h"

struct tagFinder {
	tagFinder(const char* pTag) : m_pTag(pTag) {}
	
	const char* m_pTag;
};

int main()
{
	map<int, int, greater<int>> mapInt;

	mapInt.insert({ 1, 100 });
	mapInt.insert({ 2, 200 });
	mapInt.insert({ 3, 300 });
	mapInt.insert({ 4, 400 });
	mapInt.insert({ 5, 500 });
	mapInt.insert({ 6, 600 });
	mapInt.insert({ 7, 700 });

	// map<int, int>::iterator iter = mapInt.begin();
	// 
	// ++iter;
	// ++iter;
	// 연관 컨테이너는 중간 삽입이 사실상 의미가 없다
	// mapInt.insert(iter, { 9, 99999 });
	// for (iter = mapInt.begin(); iter != mapInt.end(); ++iter) {
	// 	cout << iter->first << "\t" << iter->second << endl;
	// }

	// map<int, int>::iterator iter = mapInt.find(4);
	// cout << iter->first << "\t" << iter->second << endl;

	map<const char*, int> mapCmp;
	mapCmp.insert({ "AAA", 100 });
	mapCmp.insert({ "BBB", 200 });
	mapCmp.insert({ "CCC", 300 });
	
	// map<const char*, int>::iterator iter = mapCmp.find("BBB");
	map<const char*, int>::iterator iter = find_if(mapCmp.begin(), mapCmp.end(), );
	cout << iter->first << "\t" << iter->second << endl;

	return 0;
}