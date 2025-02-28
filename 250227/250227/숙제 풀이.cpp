// 250227.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include "CMyString.h"


int main()
{
    CMyString       Temp("hello");

    CMyString       Sour("jusin");

    CMyString       Dest("hello");

    //Sour = Temp;
   //  Sour = "world";

    //Temp = Temp + Sour;
    //Temp = Temp + "academy";

    //cout << Sour.Get_String() << endl;

   // cout << Temp.Get_String() << endl;

    if (Temp == Dest)
        cout << "일치" << endl;

    if (Temp == "hello")
        cout << "일치" << endl;

    
    return 0;
}
