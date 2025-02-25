#include "pch.h"

class CObj2
{
public:
	virtual void	Render() { cout << "Obj" << endl; }		// ���� �Լ�
	virtual void	Draw() {}
};

class CPlayer2 : public CObj2
{
public:
	void	Render() { cout << "Player" << endl; }
};

int main()
{
	// ������ : ��ü �ٸ� ������ ��ü�� ���·� ��ȯ�Ͽ� �޼ҵ� ��� ���ϴ� ��� ����

	// - �θ� Ÿ���� ��ü�� �ڽ� ��ü�� �ִ� �޼ҵ带 ��� �� �� �ֵ��� ����� ����

	// 1. �������̵�	: �ڽ� �ڷ������� �����ϰ� ���ϰ� �ִ� �޼ҵ带 ȣ���ϱ� ���� ����
	// 
	// 1 ���� : �θ�� �ڽ� ���� ��� ����
	// 2 ���� : �θ�� �ڽ� Ŭ������ ������ ������ ������ �Լ��� ����
	// 3 ���� : �θ� Ŭ������ �ִ� �Լ� �տ� virtual�� �ݵ�� ����
	// 
	// 2. �ٿ� ĳ����	: �ڽ� �ڷ��� �� �������� �޼ҵ带 ȣ���ϱ� ���� ����

	// CObj2		Obj;
	// Obj.Render();

	// CPlayer2	Player;
	// Player.Render();
	// 
	// Player.CObj2::Render();

	CPlayer2		Player2;
	//
	CObj2* pObj = new CPlayer2;	// ���� ���ε����� ����(�����Ͱ� � ��ü�� �ּҸ� �����ϴ����� ���� ȣ��Ǵ� �Լ��� ����)
	
	// __vfptr = 0x00007ff6ed8acc20 {250224.exe!void(*CObj2::`vftable'[2])()} { 0x00007ff6ed8a15af {250224.exe!CObj2::Render(void)} }

	// __vfptr = 0x00007ff75148cc98 {
	// 	250224.exe!
	// 		void(*CPlayer2::`vftable'[2])()}
	// { 0x00007ff7514815c3 {250224.exe!CPlayer2::Render(void)} }

	pObj->Render();

	//CObj2	Obj;			// ���� ���ε� �״�� ����
	//Obj.Render();


	return 0;
}