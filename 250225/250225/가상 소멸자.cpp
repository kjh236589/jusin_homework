#include "pch.h"

class CObj2 abstract			// 추상 클래스임을 알리는 키워드
{
public:
	virtual	void Draw() = 0;

public:
	CObj2() { cout << "부모 생성자" << endl; }
	virtual ~CObj2() {}
};

class CPlayer2 : public CObj2
{
public:
	virtual void Print() = 0;

public:
	CPlayer2() { cout << "자식 생성자" << endl; }
	~CPlayer2() { cout << "자식 소멸자" << endl; }
};

class CThief final : public CPlayer2		// 상속 계층 중 가장 말단 계층을 알리는 키워드(이 클래스에게 상속 받는 자식이 존재 할 수 없음)
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