#pragma once

#define WINCX 800
#define WINCY 600

#define	PI		3.141592f
#define PURE		= 0

#define	NOEVENT		0
#define DEAD		1


extern HWND    g_hWnd;

enum DIRECTION {	DIR_LEFT, DIR_RIGHT, DIR_UP, DIR_DOWN, DIR_LU, DIR_RU, DIR_END};
enum OBJID		{OBJ_PLAYER, OBJ_BULLET, OBJ_MONSTER, OBJ_MOUSE, OBJ_SHIELD, OBJ_END };


template<typename T>
void Safe_Delete(T& p)
{
	if (p)
	{
		delete p;
		p = nullptr;
	}
}

typedef struct tagInfo
{
	float	fX;
	float	fY;
	float	fCX;
	float	fCY;

}INFO;