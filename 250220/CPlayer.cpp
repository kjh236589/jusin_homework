#include "pch.h"]
#include "CPlayer.h"

// extern : �ܺο� ǥ���� ������ ���� ������ �����ϴ� ���� �˷��ִ� ���α׷� Ű����
// ���� �޸޷� �Ҵ��� ���� �ʴ´�,(extern�� �ٿ��� ǥ���� �ڷ�� ũ�Ⱑ �������� ������ ���� ������ �� ����)

extern int g_iNumber;

extern void Draw();

void CPlayer::Render()
{
	Draw();
	g_iNumber = 500;
	cout << g_iNumber << endl;
}