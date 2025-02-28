#include "pch.h"
#include "String.h"
#include "Define.h"

String::String()
{
	str = nullptr;
	iSize = 0;
}

String::~String()
{
	Release();
}

void String::Release()
{
	SAFE_DELETE_ARRAY(str);
}

String& String::operator=(const char* pString)
{
	Release();
	iSize = (int)strlen(pString) + 1;
	str = new char[iSize];
	strcpy_s(str, iSize, pString);
	return *this;
}

String& String::operator=(String& string)
{
	Release();
	iSize = (int)strlen(string()) + 1;
	str = new char[iSize];
	strcpy_s(str, iSize, string());
	return *this;
}

char* String::operator+(const char* pString)
{
	iSize += (int)strlen(pString) + 1;
	char* cStr = new char[iSize];
	strcpy_s(cStr, iSize, str);
	strcat_s(cStr, iSize, pString);
	return cStr;
}

char* String::operator+(String& string)
{
	iSize += (int)strlen(string()) + 1;
	char* cStr = new char[iSize];
	strcpy_s(cStr, iSize, str);
	strcat_s(cStr, iSize, string());
	return cStr;
}

bool String::operator==(const char* pString)
{
	return !strcmp(str, pString);
}

char* String::operator()() {
	return str;
}