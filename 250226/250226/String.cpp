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
}

String& String::operator=(const char* cArray)
{
	SAFE_DELETE_ARRAY(str);
	iSize = 0;
	while (true) {
		if (cArray[iSize++] == NULL) {
			break;
		}
	}
	str = new char[iSize];
	strcpy_s(str, iSize, cArray);
	return *this;
}

String String::operator+(const char* cArray)
{
	String newStr;
	int iCount(0);
	while (true) {
		if (cArray[iCount++] == NULL) {
			break;
		}
	}
	char* cStr = new char[iSize + iCount - 1];
	strcpy_s(cStr, iSize, str);
	iSize += iCount - 1;
	strcat_s(cStr, iSize, cArray);
	newStr = cStr;
	SAFE_DELETE_ARRAY(cStr);
	return newStr;
}

bool String::operator==(const char* cArray)
{
	return strcmp(str, cArray) == 0;
}

char* String::operator()() {
	return str;
}