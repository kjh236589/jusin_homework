#include "pch.h"

class CObj {
public:
	explicit CObj(int iA) {			// 묵시적 형 변환을 통한 생성자 호출 금지
		m_iA = iA;
		cout << "생성자 호출" << endl;
	}
	~CObj(){}
	void Render(int iA) {
		this->m_iA = iA;
		cout << this->m_iA << endl;
	}
private:
	int m_iA;
};

int main()
{
	// 객체 포인터 배열
	// CObj* Obj[5] = { new CObj, new CObj , new CObj , new CObj , new CObj };
	// 객체 배열 포인터
	// CObj* pTemp = new CObj[5];

	// CObj cObj = 20;			// 묵시적 형 변환을 통한 생성자 호출
	// cObj.Render();

	//////////////////////////////////////////////

	// this 포인터 : 생성된 객체 자기 자신의 주소

	CObj Temp(100);
	Temp.Render(200);

	return 0;
}