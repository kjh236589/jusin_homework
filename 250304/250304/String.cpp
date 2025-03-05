#include "pch.h"
#include "define.h"
#include "String.h"

String::String()
{
	string = nullptr;
}

String::String(const String& copy)
{
	int iSize(strlen(copy.string) + 1);
	string = new char[iSize];
	strcpy_s(string, iSize, copy.string);
}

String::~String()
{
	Release();
}

void String::Release()
{
	SAFE_DELETE_ARRAY(string);
}

String& String::operator=(const char* pString)
{
	Release();
	int iSize(strlen(pString) + 1);
	string = new char[iSize];
	strcpy_s(string, iSize, pString);
	return *this;
}

char* String::operator+(const char* pString)
{
	int iSize(strlen(string) + strlen(pString));
	char* str = new char[iSize];
	strcpy_s(str, iSize, string);
	strcat_s(str, iSize, pString);
	return str;
}

bool String::operator==(const char* pString)
{
	return !strcmp(string, pString);
}

char* String::operator()() {
	return string;
}
