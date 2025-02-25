#include "pch.h"

// �߻� Ŭ���� : ������ �ڽ� Ŭ�������� �޼ҵ带 �����ϴ� �뵵�� ������ ������ �������̽� Ŭ����
// ���� ���� �Լ��� �� ���� �����ϸ� �߻� Ŭ������ ����, �߻� Ŭ������ ��ü���� ��ü ������ �Ұ�
// �θ� Ŭ������ ���� �����Լ��� ������ ���, �� Ŭ������ ����� �޴� ��� �ڽ� Ŭ������ �ݵ�� ���� �����Լ��� ��ü�� �����ؾ��Ѵ�

class CBase
{
public:
	virtual void	Render() = 0;				// ���� ���� �Լ� : �������̵��� �ϱ� ���� �뵵�� �θ� Ŭ������ �����ϴ� ����
	void	Draw() { cout << "Base" << endl; }
};

class CDerived : public CBase
{
public:
	void	Render() { cout << "hello world" << endl; }
};

class CTemp : public CBase
{
public:
	void	Render() {}
};


int main()
{

	// CBase* pBase = new CDerived;
	// 
	// pBase->Render();

	// CBase	Base;		// �߻� Ŭ������ �ڽ��� Ÿ������ ��ü ������ �Ұ����ϴ�.
	// Base.Draw();

	CBase* pTemp = new CTemp;

	pTemp->Draw();

	


	return 0;
}