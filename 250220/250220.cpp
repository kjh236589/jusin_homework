#include "pch.h"
#include "CPlayer.h"

int g_iNumber = 200;

void Draw() {
	cout << "Hello" << endl;
}

int main()
{
	CPlayer cPlayer;
	cPlayer.Render();
	return 0;
}