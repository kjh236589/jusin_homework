#include "pch.h"

class CBase
{
public:
	CBase();
	~CBase();

public:
	void		Set_A(int _iA) { m_iA = _iA; }

private:
	int		m_iA;
	int* m_pB;
};

CBase::CBase()
{
	m_iA = 100;				// ������ ���� �ʱ�ȭ ���
	m_pB = nullptr;
}
CBase::~CBase()
{

}

int main()
{
	// cout << sizeof(CBase) << endl;

	//CBase	Base = { 10, nullptr };


	// ��ü(Ŭ����)�� ���� ��, �ڵ����� �����Ǵ� �Լ� �� ����

	// 1. default ������ : ������� �����ڰ� �� ���� �����ϸ� �����Ϸ��� �������� ����, �����ڰ� ���� �� ���� �� �� ����
	// 2. default ���� ������
	// 3. default ���� ������
	// 4. default �Ҹ��� : ������� �Ҹ��ڰ� ������ �����Ϸ��� �������� ����. �Ҹ��ڴ� ������ �ϳ��� ������ ����

	// ��ü ���� ����(�� �� ������ �ݵ�� ����Ǿ�� ��)
	// 1. �޸� �Ҵ� 2. ������ ȣ��

	// ��ü �Ҹ� ����(�� �� ������ �ݵ�� ����Ǿ�� ��)
	// 1. �Ҹ��� ȣ�� 2. �޸� ��ȯ


	CBase	Base;


	return 0;
}