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
	// auto 키워드 : 사용자가 직접 타입을 지정하지 않아도 컴파일러가 판단하여 자료형을 찾아주는 키워드

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

	// 범위 기반 for문 : 범위 정해놓고 for문을 구동하기 위해 제공

	//int		iArray[5] = { 1, 2, 3, 4, 5 };

	//for (int i = 0; i < 8; ++i)
	// {
	// 	cout << iArray[i] << endl;
	// }

	// for (int i : iArray)
	// {
	// 	cout << i << endl;
	// }

	// 유니폼 초기화 : 블럭 단위 데이터를 중괄호를 이용하여 초기화하는 문법
	
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
	// std::array : 정적 배열을 객체화시킴, 생성자, 복사 생성자, 대입 연산자를 지원
	// empty, swap, front, back 함수를 제공
	// 각종 추가 및 삭제 함수는 제공하지 않음

	//int		iArray[5]{ 1, 2, 3, 4, 5 };
	//cout << sizeof(iArray) / sizeof(int) << endl;
	//int* p = iArray;
	//
	//
	//array<int, 5> arrEx{ 10, 20, 30, 40, 50 };
	//cout << arrEx.size() << endl;
	//
	//array<int, 5> arrTemp = arrEx;		// 배열 간의 대입이 가능

	// for (int i : arrTemp)
	// 	cout << i << endl;

	//int* p2 = arrEx.data();	// 배열의 첫 번째 주소를 얻어옴
	//cout << p2[2] << endl;

	// arrTemp.fill(999);		// 배열의 모든 원소를 매개 변수 값으로 채움
	
	//for (int i : arrTemp)
	//	cout << i << endl;
	

	return 0;
}
