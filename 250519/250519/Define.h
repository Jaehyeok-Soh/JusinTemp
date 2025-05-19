#pragma once

#define WINCX 800
#define WINCY 600

#define PURE = 0

struct INFO
{
	float fX;
	float fY;
	float fCX;
	float fCY;
};

extern HWND g_hWnd;

template<typename T>
void safe_delete(T*& _obj)
{
	if (_obj)
	{
		delete _obj;
		_obj = nullptr;
	}
}

template<typename T>
void safe_delete_array(T*& _obj)
{
	if (_obj)
	{
		delete[] _obj;
		_obj = nullptr;
	}
}