// 250207.cpp : �� ���Ͽ��� 'main' �Լ��� ���Ե˴ϴ�. �ű⼭ ���α׷� ������ ���۵ǰ� ����˴ϴ�.
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

#pragma region C��� �����Ҵ�
    // calloc(����, �ڷ����� ũ��)
   // void* calloc(size_t _Count, size_t _Size)

   // 1. �Ű� ������ �� ���̸� ���� �迭�� ����⿡ �ټ� �����ϴ�.
   // 2. �����Ҵ��� ������ heap ������ �ڵ����� 0���� �ʱ�ȭ�Ѵ�.

   //int* pArray = (int*)calloc(3, sizeof(int));

   //pArray[0] = 10;
   //pArray[1] = 20;
   //pArray[2] = 30;

   //for (int i = 0; i < 3; ++i)
   //{
   //    cout << pArray[i] << endl;
   //}

   //cout << pArray << endl;

   // free(��ȯ�� �޸� �ּ�)
   // void free(void* _Block);

   //free(pArray);
   //pArray = NULL;

   //cout << pArray << endl;         // ��۸� ������ : �㰡 ���� ���� �ּҸ� �����ϰ� �ִ� ����
   //  
   //*pArray = 100;
   //
   //cout << pArray[0] << endl;
#pragma endregion

    // int* p = new int(10);       // 1. ���������� �ڷ����� �뷮 �Ǵ� ����
    //                             // 2. ����� ���ÿ� ����ڰ� ���ϴ� ������ heap ������ ���� �ʱ�ȭ �� �� ����
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
    // c++�� ���� �迭

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

    // ������ �迭
    // int* pTemp[3] = { new int(1), new int(2), new int(3) };

    // �迭 ������
    // int* p = new int[3];

    return 0;
}
