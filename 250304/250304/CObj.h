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
		cout << "�̸� : " << obj.szName << endl << "HP : " << obj.iHp << endl << "���ݷ� : " << obj.iAtk << endl;
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

