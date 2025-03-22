#include "pch.h"
#include "CMap.h"

CMap::CMap() : b_Pass(true)
{
}

CMap::~CMap()
{
	Release();
}

void CMap::Initialize()
{
}

int CMap::Update()
{
	__super::Update_Rect();
	return 0;
}

void CMap::Late_Update()
{
}

void CMap::Release()
{
}
