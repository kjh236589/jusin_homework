#include "pch.h"

bool	Number(int Dst)
{
	return Dst < 40;
}

int main()
{
	list<int>		intList;

	intList.push_back(10);
	intList.push_back(20);
	intList.push_back(30);
	intList.push_back(40);

	//intList.sort(greater<int>());
	//intList.reverse();		// 노드의 순서를 반대로 뒤집기
	// intList.unique();

	intList.remove_if(Number);

	for (list<int>::iterator iter = intList.begin();
		iter != intList.end(); ++iter)
	{
		cout << (*iter) << endl;
	}

	//list<int>::iterator iter = intList.begin();			// 양방향 반복자



	// iter++;
	// iter++;
	// 
	// iter += 2;

	// iter = intList.insert(iter, 50);
	// iter = intList.erase(iter);

	//cout << (*iter) << endl;

	// for (list<int>::iterator iter = intList.begin();
	// 	iter != intList.end(); ++iter)
	// {
	// 		cout << (*iter) << endl;
	// }

	//cout << intList.front() << endl;
	//cout << (*iter) << endl;
	//cout << intList.back() << endl;

	// for (size_t i = 0; i < intList.size(); ++i)
	// {
	// 	cout << intList[i] << endl;
	// }

	// for (list<int>::iterator iter = intList.begin();
	// 	iter != intList.end(); ++iter)
	// {
	// 	cout << (*iter) << endl;
	// }
	// 
	// intList.pop_front();
	// 
	// cout << "------------------------------------------" << endl;
	// 
	// for (list<int>::iterator iter = intList.begin();
	// 	iter != intList.end(); ++iter)
	// {
	// 	cout << (*iter) << endl;
	// }


	return 0;
}