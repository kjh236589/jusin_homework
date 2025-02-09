// 250207.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

#ifdef _DEBUG

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifndef DBG_NEW 
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ ) 
#define new DBG_NEW 

#endif
#endif


using namespace std;

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

#pragma region C언어 동적할당
    // calloc(개수, 자료형의 크기)
   // void* calloc(size_t _Count, size_t _Size)

   // 1. 매개 변수가 두 개이며 동적 배열을 만들기에 다소 안전하다.
   // 2. 동적할당을 수행한 heap 영역을 자동으로 0으로 초기화한다.

   //int* pArray = (int*)calloc(3, sizeof(int));

   //pArray[0] = 10;
   //pArray[1] = 20;
   //pArray[2] = 30;

   //for (int i = 0; i < 3; ++i)
   //{
   //    cout << pArray[i] << endl;
   //}

   //cout << pArray << endl;

   // free(반환할 메모리 주소)
   // void free(void* _Block);

   //free(pArray);
   //pArray = NULL;

   //cout << pArray << endl;         // 댕글링 포인터 : 허가 받지 않은 주소를 소유하고 있는 상태
   //  
   //*pArray = 100;
   //
   //cout << pArray[0] << endl;
#pragma endregion

    // int* p = new int(10);       // 1. 직관적으로 자료형과 용량 판단 가능
    //                             // 2. 선언과 동시에 사용자가 원하는 값으로 heap 영역의 값을 초기화 할 수 있음
    // cout << p << endl;
    // 
    // //*p = 10;
    // 
    // cout << *p << endl;
    // 
    // delete p;
    // // p = NULL;
    // p = nullptr;
    // 
    // cout << p << endl;
    // 
    // 
    /////////////////////////////////////////////////////
    // c++의 동적 배열

    //int* pArray = new int[5] {10, 20, 30, 40, 50};

    //pArray[0] = 100;
    //pArray[1] = 200;
    //pArray[2] = 300;
    //pArray[3] = 400;
    //pArray[4] = 500;

    // for (int i = 0; i < 5; ++i)
    // {
    //     cout << pArray[i] << endl;
    // }
    // 
    // delete[]pArray;
    // pArray = nullptr;

    // 포인터 배열
    // int* pTemp[3] = { new int(1), new int(2), new int(3) };

    // 배열 포인터
    // int* p = new int[3];

    return 0;
}
