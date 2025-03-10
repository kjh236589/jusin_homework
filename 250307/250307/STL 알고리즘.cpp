#include "pch.h"

template<typename T>
bool IsOddNumber(T Number)
{
    if (0 != Number % 2)
        return true;

    return false;
}

struct tagOddNumber
{
    template<typename T>
    bool operator()(T Number)
    {
        return 0 != Number % 2;
    }
};

template<typename T>
void Safe_Delete(T& p)
{
    if (p) 
    { 
        delete p; 
        p = nullptr; 
    }
}

struct DeletePointer
{
    template<typename T>
    void operator()(T& p)
    {
        if (p)
        {
            delete p;
            p = nullptr;
        }
    }
};

bool MyStrCmp(const char* pName)
{
    return !strcmp(pName, "jusin");
}

struct tagStrCmp
{
    tagStrCmp(const char* pName) : m_pName(pName) {}     // 생성자

    template<typename T>
    bool operator()(T& p)
    {
        return !strcmp(m_pName, p);
    }

    const char* m_pName;
};

int main()
{
    // vector<int>     vecInt{2, 3, 4, 6, 8};
    // 
    // size_t iCount = count_if(vecInt.begin(), vecInt.end(), tagOddNumber());
    // 
    // cout << iCount << endl;

    //for (size_t i = 0; i < vecInt.size(); ++i)
    //    cout << vecInt[i] << " ";
    //    
    //sort(vecInt.begin(), vecInt.end(), greater<int>());
    //
    //cout << endl;
    //cout << "---------------------------------------" << endl;
    //
    //for (size_t i = 0; i < vecInt.size(); ++i)
    //    cout << vecInt[i] << " ";

    //vector<int*>        vecIntp{ new int, new int, new int };
    //
    //for_each(vecIntp.begin(), vecIntp.end(), DeletePointer());
    //vecIntp.clear();

    // vector<const char*>     vecCharp{ "hello", "world", "jusin" };
    // 
    // //vector<const char*>::iterator   iter = find_if(vecCharp.begin(), vecCharp.end(), MyStrCmp);
    // vector<const char*>::iterator   iter = find_if(vecCharp.begin(), vecCharp.end(), tagStrCmp("world"));
    // 
    // if (iter == vecCharp.end())     // find_if는 해당 원소를 찾지 못할 경우 end를 반환
    //     return 0;
    // 
    // cout << (*iter) << endl;

    
    return 0;
}
