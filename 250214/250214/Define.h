#pragma once
#define SAFE_DELETE (p) if(p){delete p; p = nullptr;}
#define SAFE_DELETE_ARRAY(p) if(p){delete[] p; p = nullptr;}

typedef struct tagInfo {
	char szName[32];
	int iMaxHp;
	int iHp;
	int iAtk;
}INFO;