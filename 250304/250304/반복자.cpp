#include "pch.h"

using namespace std;

template<typename T>
void Safe_Delete(T& p)
{
	if (p) { delete p; p = nullptr; }
}


class CObj
{
public:
	CObj(int _iA) : m_iA(_iA){}

public:
	int		Get_A() { return m_iA; }

private:
	int m_iA;
};

int main()
{
	vector<CObj*>		m_vecObj;

	m_vecObj.push_back(new CObj(10));
	m_vecObj.push_back(new CObj(20));
	m_vecObj.push_back(new CObj(30));
	m_vecObj.push_back(new CObj(40));
	m_vecObj.push_back(new CObj(50));

	for (vector<CObj*>::iterator iter = m_vecObj.begin();
		iter != m_vecObj.end(); )
	{
		if (30 == (*iter)->Get_A())
		{
			Safe_Delete<CObj*>(*iter);

			iter = m_vecObj.erase(iter);
		}
		else
		{
			++iter;
		}
	}


	// vector<int>		vecInt;
	// 
	// vecInt.push_back(1);
	// vecInt.push_back(2);
	// vecInt.push_back(3);
	// vecInt.push_back(4);
	// vecInt.push_back(5);
	// 
	// // cout << vecInt.front() << endl;
	// // cout << vecInt.back() << endl;
	// 
	// // vecInt.front() = 100;		// 값 쓰기, 읽기 모두 가능
	// // vecInt.back()  = 500;
	// 
	// vector<int>::iterator iter = vecInt.begin(); // +2;	// 임의 접근 반복자의 예 1
	// 
	// iter += 2;											// 임의 접근 반복자의 예 2
	// 
	// 
	// // 원소를 중간에 삽입하는 함수
	// //iter = vecInt.insert(iter, 999);
	// 
	// // 원소를 중간에 삭제하는 함수
	// iter = vecInt.erase(iter);
	// 
	// cout << (*iter) << endl;

	//for(iter = vecInt.begin(); iter != vecInt.end(); ++iter)
	//	cout << (*iter) << endl;


	// for (vector<int>::iterator iter = vecInt.begin();
	// 	iter != vecInt.end(); 
	// 	++iter)
	// {
	// 	cout << (*iter) << endl;
	// }


	//for (size_t i = 0; i < vecInt.size(); ++i)
	//{
	//	cout << vecInt[i] << endl;
	//}

	//반복자 : 컨테이너에 저장되어 있는 원소 공간에 접근을 수행하는 객체

	// 1. 출력 반복자 2. 입력 반복자 3. 순방향 반복자 4. 양방향 반복자   5. 임의 접근 반복자
	// const *		 *, =		  *, =, ++	     *, =, ++, --	  *, =, ++, --, +=, -=

	return 0;
}

// 1. vector 를 이용하여 성적표 프로그램 만들기(삭제)
// 1. 입력 2. 출력 3. 검색 4. 삭제 5. 종료

// 2. TRPG 최종판 만들기
// - 인벤토리, 아이템 장착
// - VECTOR를 이용하여 인벤토리 만들기(5칸 제한)