// 250313.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <Windows.h>

class CObj
{
public:
    CObj() : m_pArray(0), m_iSize(0) {}
    CObj(int iSize) : m_pArray(new int[iSize]), m_iSize(iSize) {}
    CObj(const CObj& rhs)
        : m_pArray(new int[rhs.m_iSize]), m_iSize(rhs.m_iSize)
    {
        memcpy(m_pArray, rhs.m_pArray, sizeof(int) * m_iSize);
    }

    CObj(CObj&& rObj)
    {
        m_pArray = rObj.m_pArray;
        m_iSize = rObj.m_iSize;

        rObj.m_pArray = nullptr;    // 소유권 이전
    }



    ~CObj()
    {
        delete[]m_pArray;
        m_pArray = nullptr;
    }

public:
    void    Render() const
    {
        m_iData = 100;
        cout << m_iData << endl;
    }

public:
   mutable int     m_iData;     // 멤버 변수의 쓰기를 읽기 전용 함수에서 허용
   int* m_pArray;
   int   m_iSize;

};

class CBase
{
public:
    CBase() : m_iX(0), m_iY(0) {}
    CBase(int& iX, int& iY) : m_iX(iX), m_iY(iY) {}

private:
    int     m_iX, m_iY;
};

CBase* Create(int&& X, int&&  Y)
{
    return new CBase(X, Y);
}



int main()
{
    // 람다식 (람다 표현식) : 무명의 inline 함수

    // [] : 람다 소개자, 캡처절, 컴파일러가 람다 함수로 인지하게 만드는 기호
    // () : 람다 호출자, 일반 함수의 파라미터와 동일한 기능을 수행
    // {} : 람다 몸체, 일반 함수의 몸체와 동일한 기능


   // []() {cout << "hello world" << endl; }();

    // [](int iData) {cout << iData << endl; }(100);
    // [](int iData = 300) {cout << iData << endl; }();


    //vector<int>     vec{ 10, 20, 30, 40 , 50 };
    //
    //for_each(vec.begin(), vec.end(), [](int n) { cout << n << endl; });


    // 묵시적 반환
    //int iResult = [](int Dst, int Src) { return Dst + Src;  }(10, 20);

    // 명시적 반환
    // int iResult = [](int Dst, int Src)->int { return Dst + Src;  }(10, 20);
    // cout << iResult << endl;


     // vector<int>     vec{ 10, 20, 33, 44, 58 };
     // 
     // auto iter = find_if(vec.begin(), vec.end(), 
     //     [](int n)->bool 
     //     {
     //         return 0 != n % 2; 
     //     });
     // 
     // cout << *iter << endl;
    
    // vector<int> vec{ 1, 2, 3, 4, 5 };
    // 
    // int iEvenSum(0), iOddSum(0);
    // 
    // for_each(vec.begin(), vec.end(), 
    //     [&iEvenSum, &iOddSum](int n)   mutable        // 값을 복사하여 캡처(const 성격이 부여)
    //     {                                           // 복사 값을 증가시켰기 때문에 원본 값은 변경이 되질 않음
    //         if (n % 2 == 0)
    //         {
    //             iEvenSum += n;
    //         } 
    //         else
    //         {
    //             iOddSum += n;
    //         }
    //     });
    // 
    // cout << iEvenSum << endl;
    // 
    // cout << iOddSum << endl;


    ////////////////////////////////////////////////
    // r-value 레퍼런스 :  r-value 데이터 또한 참조가 가능한 문법

   // int     iData = 100;
   //
   // int& r = iData;
   //
   // r = 200;
   //
   // cout << iData << endl;

   /*const int& r2 = 200;

   r2 = 300;

   cout << r2 << endl;*/

    // int&& rr = 100;
    // 
    // rr = 200;
    // 
    // cout << rr << endl;

    //CBase* pBase = Create(10, 20);

    // 이동 생성자 

    // CObj        Obj(100000000);
    // 
    // DWORD   dwTime = GetTickCount();
    // 
    // //CObj        Copy(Obj);
    // CObj        Movement(std::move(Obj));
    // 
    // // move : r-value 레퍼런스로 캐스팅해주는 함수
    // 
    // cout << GetTickCount() - dwTime << endl;


    ///////////////////////c++ 예외처리 문법////////////////////////

    int     iNumber1(0), iNumber2(0);

    cout << "숫자 입력 : ";
    cin >> iNumber1 >> iNumber2;


    try
    {
        if (iNumber2 == 0)
            throw iNumber2;

        cout << "몫 : " << (iNumber1 / iNumber2) << endl;
        cout << "나머지 : " << (iNumber1 % iNumber2) << endl;
    }

    int iData = 100;

    catch (int)
    {
        cout << "잘못 입력" << endl;
    }

    //if (iNumber2 == 0)
    //{
    //    cout << "잘못 입력" << endl;
    //}
    //
    //else
    //{
    //    cout << "몫 : " << (iNumber1 / iNumber2) << endl;
    //    cout << "나머지 : " << (iNumber1 % iNumber2) << endl;
    //}
    
    


	return 0;
}

