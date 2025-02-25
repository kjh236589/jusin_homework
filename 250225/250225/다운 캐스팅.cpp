#include "pch.h"

class CObj3
{
public:
	virtual ~CObj3() {}

public:
	void	Output() { cout << "Obj" << endl; }
};

class CPlayer3 : public CObj3
{
public:
	~CPlayer3() {}

public:
	void	Render() { cout << "Player" << endl; }
};

class CMonster3
{
public:
	CMonster3() { cout << "������ ȣ��" << endl; }

public:
	void	Print() { cout << "Monster" << endl; }
};

int main()
{
	//CObj3* pPlayer = new CPlayer3;
	// ((CPlayer3*)pPlayer)->Render();

	//((CMonster3*)pPlayer)->Print();

	////////////////////////////////////////////////////////////

	// c++ ĳ���� ������
	// 
	// static_cast, dynamic_cast(������), const_cast, reinterpret_cast

#pragma region static_cast

	// static_cast : c ��Ÿ���� ĳ���ð� ���� ����, ���� ĳ�����̶�� �θ�, ������ Ÿ�ӿ� ĳ����
	// �� ��(Ŭ������ ��� ����)���� �� ��ȯ�� ������� ����
	// �� Ÿ�� ��, ������ �� ��ȯ�� ���� �Ǵ��� �Ұ����ϱ� ������ ��ȯ�� ���輺�� ���� �� �� ����.

	// int	iNumber = (int)3.14f;
	// int	iNumber = static_cast<int>(3.14f);
	// cout << iNumber << endl;

	// CMonster3* pMonster = new CMonster3;

	// CObj3* pObj = (CObj3*)pMonster;		// �� ������ �� ��ȯ�� ����
	// pObj->Output();

	// CObj3* pObj = static_cast<CObj3*>(pMonster);	// ������ ����(�� ������ �� ��ȯ�� ������� ����)
	// pObj->Output();

	//CObj3*	pObj		= new	CPlayer3;
	// CPlayer3* pPlayer	= static_cast<CPlayer3*>(pObj);
	// pPlayer->Render();

	//static_cast<CPlayer3*>(pObj)->Render();		// ������ �� ���� down casting �ڵ�(�������� �ƴ�)
	
#pragma endregion

#pragma region dynamic_cast

	// 1. Ŭ������ down ĳ���ø� ���
	// 2. ��� ������ Ŭ������ �־�� ��
	// 3. �θ� Ŭ������ �ݵ�� �� �� �̻��� virtual Ű���尡 ���� ���� �Լ��� �־�� ��
	// 4. �Ϲ� �ڷ����̳� �Ϲ� �����͸� ������δ� �������� ������ �� Ÿ�� ��, ���� �˻縦 �����Ѵ�.

	// CObj3* pObj = new	CPlayer3;	
	// dynamic_cast<CPlayer3*>(pObj)->Render();			// ������ �ٿ� ĳ������ ��

	CObj3* pObj = new CObj3;

	CPlayer3* pPlayer = dynamic_cast<CPlayer3*>(pObj);

	// �� ������ �� ��ȯ�� ������ ���, �� Ÿ�� �� nullptr�� ��ȯ
	// �� ��ȯ�� ���ϴ� ���� �ƴ�
	
	if (nullptr == pPlayer)
		cout << "�� ������ �� ��ȯ" << endl;

	else
		pPlayer->Render();

#pragma endregion

	

	return 0;
}