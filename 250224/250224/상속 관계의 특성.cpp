#include "pch.h"

class CBase
{
public:
	void		Render_Base() { cout << "Base" << endl; }
};

class CDerived : public CBase
{
public:
	void		Render_Derived() { cout << "Derived" << endl; }
};

class CTemp : public CDerived
{
public:
	void		Render_Temp() { cout << "Temp" << endl; }
};

int main()
{

	// ��ü �����ʹ� ������ Ÿ�ӿ� �ڷ����� ���� � �Լ��� ȣ�� �� �� ���� �Ǿ��ִ�.

	// ���� ���ε� : ������ Ÿ�ӿ� ��ü�� ���¿� ���� ȣ�� �� �� �ִ� �Լ��� ���°� ����

	//CDerived* pDerived = &Temp;
	//
	//pDerived->Render_Base();
	//pDerived->Render_Derived();
	//
	//pDerived->Render_Temp();


	// 1. 1���� �ȴ� : �Ѽ�, ����
	// 2. 2���� �ȴ� : 
	// 3. 3���� �ȴ� : 
	// 4. 1, 2���� �ȴ� : ����, ��ȯ, ����, ��ȣ, ����, �ؼ�, ����, ����, ����, ����(?)
	// 5. 1, 3���� �ȴ� : 
	// 6. 2, 3���� �ȴ� : 
	// 7. 1, 2, 3�� �� �ȴ� : ����, �μ�, �μ�, ��ȣ, ����
	// 8. �� �ȴ�(������ ����) : 


	return 0;
}
