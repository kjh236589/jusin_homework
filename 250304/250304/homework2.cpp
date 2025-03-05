#include "pch.h"
#include "CMainGame.h"

int main() {
	CMainGame game;
	game.Initialize();
	game.Update();
	game.Release();
}