#include "pch.h"
#include "define.h"
#include "String.h"

String::String()
{
	string = nullptr;
}

String::String(const String& copy)
{
	int iSize(static_cast<int>(strlen(copy.string)) + 1);
	string = new char[iSize];
	strcpy_s(string, iSize, copy.string);
}

String::~String()
{
	Release();
}

void String::Release()
{
	SAFE_DELETE_ARRAY<char*>(string);
}

String& String::operator=(const char* pString)
{
	Release();
	int iSize(static_cast<int>(strlen(pString)) + 1);
	string = new char[iSize];
	strcpy_s(string, iSize, pString);
	return *this;
}

char* String::operator+(const char* pString)
{
	int iSize(static_cast<int>(strlen(string)) + static_cast<int>(strlen(pString)));
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
