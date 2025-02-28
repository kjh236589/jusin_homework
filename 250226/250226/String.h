#pragma once
class String
{
public :
	String();
	~String();
	void Release();
	String& operator =(const char* pString);
	String& operator =(String& string);
	char* operator +(const char* pString);
	char* operator +(String& string);
	bool operator ==(const char* pString);
	char* operator()();
private:
	char* str;
	int iSize;
};