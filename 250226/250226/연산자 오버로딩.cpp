#include "pch.h"

class CObj
{
public:
	CObj() : m_iX(0), m_iY(0) { }
	CObj(int _iX, int _iY) : m_iX(_iX), m_iY(_iY) { cout << "������ ȣ��" << endl; }
	CObj(const CObj& rhs) : m_iX(rhs.m_iX), m_iY(rhs.m_iY) { cout << "���� ������ ȣ��" << endl; }
	CObj& operator=(CObj& rObj)
	{
		m_iX = rObj.m_iX;
		m_iY = rObj.m_iY;	

		cout << "default ���� ������ ȣ��" << endl;

		return *this;
	}

	~CObj() {}

public:
	void	Render() { cout << m_iX << "\t" << m_iY << endl; }

	CObj	operator +(CObj& rObj)
	{
		CObj	Temp(m_iX + rObj.m_iX, m_iY + rObj.m_iY);

		return Temp;
	}

	CObj	operator +(int iData)
	{
		CObj	Temp(m_iX + iData, m_iY + iData);

		return Temp;
	}

	CObj& operator++()
	{
		m_iX += 1;
		m_iY += 1;

		return *this;
	}

	CObj operator++( int)		// ���� ������ ���� ���� �˸��� ����
	{
		CObj	Result(*this);

		m_iX += 1;
		m_iY += 1;

		return Result;
	}

private:
	int		m_iX;
	int		m_iY;
};

// ���� �Լ�
CObj	operator +(int iData, CObj& rObj)
{
	CObj	Result(rObj + iData);

	return Result;
}


int main()
{
	// ������ �����ε� : �Լ� �����ε��� ��Ģ�� �����ڿ��� �����ϴ� ����
	// ������ �����ε��� ������ ����, '������ ��ü�� ��ġ'�Ͽ� ����

	// ������ �����ε��� operator Ű���带 �̿��Ͽ� ���� ����
	// - ������ �������� ������ �ٲٴ� ������ �� �� ����( + -> - �ǹ̷� ����ڴ�)

	// Ŭ���� ����θ� �����ε��� ������ ������
	// '=', '()', '[]', '->'



	// void operator + (CObj& rObj);

	//CObj	Temp(10, 20);
	//CObj	Sour(30, 40);
		
	//Temp = Temp + Sour;

	// Temp = Temp + 100;

	//Temp = 100 + Temp;

	//Temp = Sour;

	//Temp++;

	//Temp.Render();

	return 0;
}