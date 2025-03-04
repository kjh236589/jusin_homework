#include "pch.h"

int main()
{
	vector<int> vecInt;
	vecInt.push_back(10);
	vecInt.push_back(20);
	vecInt.push_back(30);
	vecInt.push_back(40);
	for (size_t i = 0; i < vecInt.size(); ++i) {
		cout << vecInt[i] << endl;
	}
	return 0;
}