#include "pch.h"

class CObj2 abstract			// �߻� Ŭ�������� �˸��� Ű����
{
public:
	virtual	void Draw() = 0;

public:
	CObj2() { cout << "�θ� ������" << endl; }
	virtual ~CObj2() {}
};

class CPlayer2 : public CObj2
{
public:
	virtual void Print() = 0;

public:
	CPlayer2() { cout << "�ڽ� ������" << endl; }
	~CPlayer2() { cout << "�ڽ� �Ҹ���" << endl; }
};

class CThief final : public CPlayer2		// ��� ���� �� ���� ���� ������ �˸��� Ű����(�� Ŭ�������� ��� �޴� �ڽ��� ���� �� �� ����)
{
public:
	void Draw() override	{}
	void Print() override	{}

	//virtual void Draw()  override {}
	//virtual void Print() override {}
};

//class CSour : public CThief
//{
//
//};

int main()
{
	//CObj2		Obj;
	//CPlayer2	Player;

	CObj2* pPlayer = new CThief;
	
	delete pPlayer;
	pPlayer = nullptr;

	




	return 0;
}