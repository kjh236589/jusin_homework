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

	list<CObj*>		m_ObjList[OBJ_END];

	ULONGLONG		m_dwTime;
	int			m_iFPS;
	TCHAR		m_szFPS[32];

};

// 1. �÷��̾ �߽����� �����ϴ� ���带 �����ض�
// 2. ��ũ�� �Ѿ� �����ض�
// 3. �÷��̾ ����ٴϴ� ���͸� �����϶�(���Լ��� �̿��� �� : acos, acos y ġ�� 0~180��)

// ������ ���� : �ڵ��� �������� ������ ���·� ����� �����ϱ� ���ϵ��� ����� ����

//https://refactoring.guru/ko/design-patterns

// 1. �߻� ���丮 ���� : ���� ������ �� ������� �ν��Ͻ��� ����� ������ �߻�ȭ��Ų ����, ��ü ���� �� ���ݵǴ� �۾��� �������� ���·� ����� ���

// 2. �ݺ���(���ͷ�����) ���� : ���� ǥ�� ����� �������� �ʰ� �������� ���� ����� �����ϴ� ����