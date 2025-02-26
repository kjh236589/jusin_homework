#pragma once
class String
{
public :
	String();
	~String();
	String& operator =(const char* cArray);
	String operator +(const char* cArray);
	bool operator ==(const char* cArray);
	char* operator()();
private:
	char* str;
	int iSize;
};