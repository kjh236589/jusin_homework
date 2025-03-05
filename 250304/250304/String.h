#pragma once
class String
{
public:
	String();
	String(const String& copy);
	~String();
	void Release();
	String& operator =(const char* pString);
	char* operator +(const char* pString);
	bool operator ==(const char* pString);
	char* operator()();
private:
	char* string;
};
