//#pragma once
//
//#define SAFE_DELETE_ARRAY(p) if(p) { delete []p; p = nullptr;}
//
//class CMyString
//{
//public:
//	CMyString();
//	CMyString(const char* pString);
//	CMyString(const CMyString& rhs);
//	~CMyString();
//
//public:
//	CMyString& operator=(CMyString&& rString);
//	CMyString& operator=(const char* pString);
//
//	CMyString	operator+(CMyString& rString);
//	CMyString	operator+(const char* pString);
//
//	bool		operator ==(CMyString& rString);
//	bool		operator ==(const char* pString);
//
//public:
//	const char* Get_String()
//	{
//		if (m_pString)
//			return m_pString;
//
//		return "";
//	}
//
//	void	Release();
//
//private:
//	char*	m_pString;
//	int		m_iSize;
//};
//
