#pragma once
#include "pch.h"
#include "define.h"
class CObj
{
public:
	CObj() {

	}
	~CObj() {

	}

	void Print() {
		cout << "이름 : " << obj.szName << endl << "HP : " << obj.iHp << endl << "공격력 : " << obj.iAtk << endl;
	}

	bool Damage(CObj* p_enemy) {
		obj.iHp -= p_enemy->obj.iAtk;
		if (0 >= obj.iHp) {
			return true;
		}
		return false;
	}
private:
	OBJ obj;
};

