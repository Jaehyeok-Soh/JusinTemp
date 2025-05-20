#pragma once

#define	WINCX 800
#define	WINCY 600

#define PURE = 0


typedef struct tagInfo
{
	float	fX;		// 중점 X,Y
	float	fY;
	float	fCX;	// 가로, 세로 길이
	float	fCY;	

}INFO;

template<typename T>
void Safe_Delete(T& p)
{
	if (p)
	{
		delete p;
		p = nullptr;
	}
}



extern HWND g_hWnd;