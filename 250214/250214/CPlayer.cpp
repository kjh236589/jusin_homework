#include "pch.h"
#include "CPlayer.h"
#include "CObject.h"

CPlayer::CPlayer()
{
	pPlayer = nullptr;
	pMonster = nullptr;
}

CPlayer::~CPlayer()
{
	(*pPlayer).Release();
	(*pMonster).Release();
	Release();
}

void CPlayer::Initialize()
{
	pPlayer = new CObject();
	pMonster = new CObject();
}

void CPlayer::Update()
{
}

void CPlayer::Release()
{
	SAFE_DELETE_ARRAY(pPlayer);
	SAFE_DELETE_ARRAY(pMonster);
}
