#include "pch.h"
//#include "CMyString.h"
//
//CMyString::CMyString()
//	: m_pString(nullptr), m_iSize(0)
//{
//}
//
//CMyString::CMyString(const char* pString)
//{
//	m_iSize = (int)strlen(pString);
//	m_pString = new char[m_iSize + 1];
//
//	strcpy_s(m_pString, m_iSize + 1, pString);
//
//}
//
//CMyString::CMyString(const CMyString& rhs)
//	: m_iSize(rhs.m_iSize)
//{
//	m_pString = new char[m_iSize + 1];
//	strcpy_s(m_pString, m_iSize + 1, rhs.m_pString);
//}
//
//CMyString::~CMyString()
//{
//	Release();
//}
//
//CMyString& CMyString::operator=(CMyString&& rString)
//{
//	Release();
//
//	m_iSize = (int)strlen(rString.m_pString);
//
//
//	m_pString = new char[m_iSize + 1];
//
//	strcpy_s(m_pString, m_iSize + 1, rString.m_pString);
//
//	return *this;	
//}
//
//CMyString& CMyString::operator=(const char* pString)
//{
//	Release();
//
//	m_iSize = (int)strlen(pString);
//
//	m_pString = new char[m_iSize + 1];
//
//	strcpy_s(m_pString, m_iSize + 1, pString);
//
//	return *this;
//}
//
//CMyString CMyString::operator+(CMyString& rString)
//{
//	int iLength = m_iSize + (int)strlen(rString.m_pString) + 1;
//
//	char* pStrCat = new char[iLength];
//
//	strcpy_s(pStrCat, iLength, m_pString);
//	strcat_s(pStrCat, iLength, rString.m_pString);
//
//	CMyString	Result(pStrCat);
//
//	SAFE_DELETE_ARRAY(pStrCat);
//
//	return Result;
//}
//
//CMyString CMyString::operator+(const char* pString)
//{
//	int iLength = m_iSize + (int)strlen(pString) + 1;
//
//	char* pStrCat = new char[iLength];
//
//	strcpy_s(pStrCat, iLength, m_pString);
//	strcat_s(pStrCat, iLength, pString);
//
//	CMyString	Result(pStrCat);
//
//	SAFE_DELETE_ARRAY(pStrCat);
//
//	return Result;
//}
//
//bool CMyString::operator==(CMyString& rString)
//{
//	return !strcmp(m_pString, rString.m_pString);
//}
//
//bool CMyString::operator==(const char* pString)
//{
//	return !strcmp(m_pString, pString);
//}
//
//void CMyString::Release()
//{
//	SAFE_DELETE_ARRAY(m_pString);
//}
