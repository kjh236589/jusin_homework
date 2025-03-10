#include "pch.h"

template<typename T>
bool IsOddNumber(T Number) {
	return 0 != Number % 2;
}

struct tagOddNumber {
	template<typename T>
	bool operator()(T Number) {
		return 0 != Number % 2;
	}
};

int main()
{
	// vector<int> vecInt{ 5, 2, 3, 1, 4 };
	// 
	// for (size_t i = 0; i < vecInt.size(); ++i) {
	// 	cout << vecInt[i] << " ";
	// }
	// 
	// sort(vecInt.begin(), vecInt.end(), greater<int>());
	// 
	// cout << endl << "-------------------------" << endl;
	// 
	// for (size_t i = 0; i < vecInt.size(); ++i) {
	// 	cout << vecInt[i] << " ";
	// }

	vector<int> vecInt{ 2, 3, 4, 6, 8 };

	size_t sCount = count_if(vecInt.begin(), vecInt.end(), IsOddNumber<int>);

	cout << sCount << endl;

	return 0;
}