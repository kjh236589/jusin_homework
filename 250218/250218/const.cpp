#include "pch.h"

int     g_iNumber = 100;

class CObj
{
public:
    CObj();
    CObj(int _iA, int _iB);

public:
    void    Render() { cout << m_iA << "\t" << m_iB << endl; }

    void    Draw() const;       // 읽기 전용 함수
   
    void    Print() const
    {
        cout << "student bus" << endl;
    }

    void    Print()
    {
        cout << "jusin 154" << endl;
    }

    const int&     Get_B() const
    {
        return m_iB;
    }

    
private:
    const int   m_iA;
    int         m_iB;
};

CObj::CObj()
    : m_iA(100), m_iB(200)      // 이니셜라이저 : 멤버인 상수를 초기화하는 문법
{
    //m_iA = 100;
}
CObj::CObj(int _iA, int _iB)
    : m_iA(_iA), m_iB(_iB)
{

}

void   CObj::Draw() const
{
    // int     iData(0);    // 
    // iData += 10;    // 
    // cout << iData << endl;

    // g_iNumber += 200;
    // cout << g_iNumber << endl;

    // static int g_iTest = 300;
    // g_iTest += 100;
    // cout << g_iTest << endl;

    // int* p = new int(10);
    // *p = 20;
    // cout << (*p) << endl;

    //m_iB += 50;           // 동일 클래스의 멤버 변수 쓰기가 불가능

    //cout << m_iB << endl;   // 동일 클래스의 멤버 변수 읽기는 가능

    cout << "hello world" << endl;

    //Print();
}

int main()
{
   const CObj        Obj;       // 객체의 성격에 따라 const가 붙은 함수와 그렇지 않은 함수 간의 함수 오버로딩이 성립된다.

   //Obj.Render();
    Obj.Print();


    return 0;
}
