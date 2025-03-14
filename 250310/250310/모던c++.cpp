#include "pch.h"

struct tagInfo
{
	int		x;
	float	y;

};

class CObj
{
public:
	CObj(tagInfo tInfo) :m_tInfo(tInfo) { }

public:
	tagInfo		Get_Info() 
	{
		return { 20, 6.36f };
	}
public:
	void Render() { cout << m_tInfo.x << "\t" << m_tInfo.y << endl; }

private:
	tagInfo	m_tInfo;
};


int main()
{
	// auto Ű���� : ����ڰ� ���� Ÿ���� �������� �ʾƵ� �����Ϸ��� �Ǵ��Ͽ� �ڷ����� ã���ִ� Ű����

	// auto	i = 10;
	// auto	f = 3.14f;
	// auto	p = new int;
	// auto	c = 'A';

	//vector<int>		vec;
	//
	//vec.push_back(10);
	//vec.push_back(20);
	//vec.push_back(30);
	//
	////vector<int>::iterator iter = vec.begin();
	//auto iter = vec.begin();
	//
	//for (auto& i : vec)
	//{
	//	i += 5;
	//	cout << i << endl;		
	//}
	//
	//cout << "------------------------------" << endl;
	//
	//for (auto i : vec)
	//{
	//	cout << i << endl;
	//	
	//}

	// ���� ��� for�� : ���� ���س��� for���� �����ϱ� ���� ����

	//int		iArray[5] = { 1, 2, 3, 4, 5 };

	//for (int i = 0; i < 8; ++i)
	// {
	// 	cout << iArray[i] << endl;
	// }

	// for (int i : iArray)
	// {
	// 	cout << i << endl;
	// }

	// ������ �ʱ�ȭ : �� ���� �����͸� �߰�ȣ�� �̿��Ͽ� �ʱ�ȭ�ϴ� ����
	
//	int		iArray[5]{ 1, 2, 3, 4, 5 };
//
//	for (int i : iArray)
//		cout << i << endl;
//
//	tagInfo	tInfo{ 10, 3.14f };

	// CObj		Obj({ 10, 3.14f });
	// 
	// cout << Obj.Get_Info().x << endl;
	// cout << Obj.Get_Info().y << endl;

	// vector<int>		vec{ 1,2,3,4,5 };
	// map<int, int>	map{ {1, 100}, {2, 200}, {3, 300} };

////////////////////////////////////////////////////////////////////////////
	// std::array : ���� �迭�� ��üȭ��Ŵ, ������, ���� ������, ���� �����ڸ� ����
	// empty, swap, front, back �Լ��� ����
	// ���� �߰� �� ���� �Լ��� �������� ����

	//int		iArray[5]{ 1, 2, 3, 4, 5 };
	//cout << sizeof(iArray) / sizeof(int) << endl;
	//int* p = iArray;
	//
	//
	//array<int, 5> arrEx{ 10, 20, 30, 40, 50 };
	//cout << arrEx.size() << endl;
	//
	//array<int, 5> arrTemp = arrEx;		// �迭 ���� ������ ����

	// for (int i : arrTemp)
	// 	cout << i << endl;

	//int* p2 = arrEx.data();	// �迭�� ù ��° �ּҸ� ����
	//cout << p2[2] << endl;

	// arrTemp.fill(999);		// �迭�� ��� ���Ҹ� �Ű� ���� ������ ä��
	
	//for (int i : arrTemp)
	//	cout << i << endl;
	

	return 0;
}
