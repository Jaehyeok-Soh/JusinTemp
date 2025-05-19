#pragma once
#include <iostream>
using namespace std;

class cMyString
{
public:
	char* m_pCstr;
	size_t m_iSz;

	cMyString() = default;
	cMyString(const char* _pStr);
	~cMyString();
	void Release();
	void Init(const char* _pCstr);

	cMyString& operator = (const char* _pStr);
	cMyString& operator = (cMyString& _pStr);
	cMyString& operator + (const char* _pStr);
	cMyString& operator + (cMyString& _pStr);
	bool operator == (const char* _pStr);
	friend std::ostream& operator<<(std::ostream& _ostr, const cMyString& _cObj);
};

