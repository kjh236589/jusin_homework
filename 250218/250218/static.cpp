#include "pch.h"

int g_iNumber = 10;

class CObj
{
public:
    CObj() : m_iB(5000)
    {
        //m_iA = 100;
    }

public:
    void    Render() { cout << m_iA << endl; }  

    static void Print()
    {
          //  int     iData(0);    
          //  iData += 10;     
          //  cout << iData << endl;

   // g_iNumber += 200;
   // cout << g_iNumber << endl;

    //static int g_iTest = 300;
    //g_iTest += 100;
    //cout << g_iTest << endl;

    // int* p = new int(10);
    // *p = 20;
    // cout << (*p) << endl;

     //  m_iB += 50;             // Ŭ���� ��� ���� ����� �Ұ�
     //  cout << m_iB << endl;   
    }

    void    Func()
    {
        // m_iA++;
        // cout << m_iA << endl;

        static int  iTest(100);
        cout << (++iTest) << endl;
    }


private:

   static int   m_iA;       // Ŭ���� ����
   int          m_iB;
};

int   CObj::m_iA = 500;     // Ŭ���� ������ �ʱ�ȭ ����

int main()
{
    CObj    Obj;

    //Obj.m_iB = 100;
    //cout << Obj.m_iB << endl;

    //cout << CObj::m_iA << endl;    

    Obj.Func();
    Obj.Func();
    Obj.Func();

    CObj    Dest;       // ���� Ÿ���� ��ü������ static �޸� ������ ����

    Dest.Func();
    Dest.Func();
    Dest.Func();

	return 0;
}