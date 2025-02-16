#include "pch.h"
#include "CGame.h"

int main()
{
	CGame* cGame = new CGame();
	cGame->Initialize();
	cGame->Update();
	cGame->Release();
	return 0;
}