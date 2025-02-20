#include "pch.h"

class CObj
{
public:
	CObj(int _iA) : m_iA(_iA)
	{
		m_pA = new int(100);			// 0x10
		cout << "�Ϲ� ������ ȣ��" << endl;
	}
	CObj(const CObj& rhs)
		// : m_iA(rhs.m_iA)
	{
		// m_iA = rhs.m_iA;
		// m_pA = rhs.m_pA;				// 0x10 ������ �ּҸ� ���纻 �����Ϳ��� �����Ͽ� ����
										// ���� ����(shallow copy)�� ����


		m_iA = rhs.m_iA;
		m_pA = new int(*rhs.m_pA);		// ���� ����(deep copy)

		cout << "���� ������ ȣ��" << endl;
	}

	~CObj()
	{
		delete m_pA;
	}

public:
	void	Render() { cout << m_iA << endl; }

	void	Print(CObj Temp)		// 2. �Լ� �Ű� ������ ��ü Ÿ���� ���
	{
		Temp.Render();
	}

	CObj	Get_Obj()				// 3. �Լ� ��ȯ Ÿ���� ��ü Ÿ���� ���
	{
		return *this;
	}

	// CObj*		Clone()
	// {
	// 		return new CObj(*this);
	// }


private:
	int		m_iA;
	int*	m_pA;
};


int main()
{
	CObj		Obj(100);

	CObj		Copy(Obj);		// 1. ���� ���� ��ü�� �Ű� ������ �����Ͽ� ���ο� ��ü�� ���� �� ��
	//
	//Copy.Render();

	// CObj		Test(200);
	// 
	// Test.Print(Obj);

	// Obj.Get_Obj().Render();



	return 0;
}