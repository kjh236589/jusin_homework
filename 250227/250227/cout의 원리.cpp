#include "pch.h"
#include <stdio.h>

namespace MyStd
{
	class Ostream
	{
	public:
		Ostream& operator << (int iData)
		{
			printf("%d", iData);
			return *this;
		}

		Ostream& operator << (const char* pData)
		{
			printf("%s", pData);
			return *this;
		}
	};

	Ostream		COUT;
	const char* ENDL = "\n";
}


using namespace MyStd;

int main()
{
	COUT << "hello world" << ENDL;

	return 0;
}
