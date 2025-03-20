#pragma once

#include "Define.h"
#include "CPlayer.h"

class CMainGame
{
public:
	CMainGame();
	~CMainGame();

public:
	void		Initialize();
	void		Update();
	void		Late_Update();
	void		Render();
	void		Release();

private:
	HDC		m_hDC;

	// CObj*			m_pPlayer;
	// list<CObj*>		m_BulletList;

	list<CObj*>		m_ObjList[3][OBJ_END];

	ULONGLONG		m_dwTime;
	int			m_iFPS, game;
	TCHAR		m_szFPS[32];

};

// 1. ��Ÿ����� ������ �о�Ͷ�
// 2. ��Ÿ����� ������ �̿��Ͽ� �� �浹�� �����ض�
// 3. �ﰢ �Լ��� �������� �˾ƿͶ�
// 4. �÷��̾� �߽����� ȸ���ϴ� ������ �����Ͷ�.


// RECT	rc{};
// IntersectRect(�浹�� ���� �߻��� ��Ʈ ������ �����ϱ� ���� ��Ʈ �ּ�, �浹��Ʈ 1�� �ּ�, �浹 ��Ʈ 2�� �ּ�)
// IntersectRect(&rc, , )


// ������ ���� : �ڵ��� �������� ������ ���·� ����� �����ϱ� ���ϵ��� ����� ����

//https://refactoring.guru/ko/design-patterns

// 1. �߻� ���丮 ���� : ���� ������ �� ������� �ν��Ͻ��� ����� ������ �߻�ȭ��Ų ����, ��ü ���� �� ���ݵǴ� �۾��� �������� ���·� ����� ���

// 2. �ݺ���(���ͷ�����) ���� : ���� ǥ�� ����� �������� �ʰ� �������� ���� ����� �����ϴ� ����