#include "pch.h"
#include <string>
#include "cMyString.h"

cMyString::cMyString(const char* _pCstr)
{
	Init(_pCstr);
}

cMyString::~cMyString()
{
	Release();
}

void cMyString::Release()
{
	SAFE_DELETE_ARRAY(m_pCstr);
}

void cMyString::Init(const char* _pCstr)
{
	Release();

	size_t sz(strlen(_pCstr));
	m_pCstr = new char[sz + 1];
	strcpy_s(m_pCstr, sz + 1, _pCstr);

	m_iSz = sz;
}

cMyString& cMyString::operator=(const char* _pCstr)
{
	Init(_pCstr);

	return *this;
}

cMyString& cMyString::operator+(const char* _pCstr)
{
	//m_pCstr + _pCstr
	char* temp = new char[m_iSz + 1];
	strcpy_s(temp, m_iSz + 1, m_pCstr);

	size_t sz(strlen(_pCstr));
	size_t totalSz(m_iSz + sz);

	Release();

	m_pCstr = new char[totalSz + 1];
	strcpy_s(m_pCstr, totalSz + 1, temp);
	strcat_s(m_pCstr, totalSz + 1, _pCstr);

	m_iSz = totalSz;

	return *this;
}

bool cMyString::operator==(const char* _pCstr)
{
	if (m_pCstr == nullptr || _pCstr == nullptr)
	{
		return false;
	}

	return strcmp(const_cast<char*>(m_pCstr), _pCstr) == 0;
}

std::ostream& operator<<(std::ostream& _ostr, const cMyString& _cObj)
{
	_ostr << _cObj.m_pCstr;
	return _ostr;
}
