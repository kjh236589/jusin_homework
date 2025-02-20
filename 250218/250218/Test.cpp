#include "pch.h"

#include <stdio.h>

class CName
{
public:
	CName(const char* pName)
	{
		int	iLength = strlen(pName) + 1;
		m_pName = new char[iLength];
		strcpy_s(m_pName, iLength, pName);

		//m_pName = nullptr;
	}

	CName(const CName& rhs)			// 깊은 복사 생성자 구현
	{
		int	iLength = strlen(rhs.m_pName) + 1;
		m_pName = new char[iLength];
		strcpy_s(m_pName, iLength, rhs.m_pName);

		//m_pName = rhs.m_pName;
	}


	~CName() { delete[]m_pName;	}

public:
	void		Print()	{		printf("%s\n", m_pName);	}

private:
	char* m_pName;
};

void	Draw(CName& Name)
{	
	Name.Print(); 
}

int main()
{
	CName		Name("neo-peple");
	Draw(Name);

	return 0;
}

