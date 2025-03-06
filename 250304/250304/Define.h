#include<string>

template<typename T>
void SAFE_DELETE(T& p) {
	if (p) {
		delete p;
		p = nullptr;
	}
}

template<typename T>
void SAFE_DELETE_ARRAY(T& p) {
	if (p) {
		delete[] p;
		p = nullptr;
	}
}

enum ITEM_TYPE {
	WEAPONE,
	ARMOR,
	POTION
};

enum GAME {
	HOME,
	ADVENTURE,
	SHOP,
	INVENTORY,
	FIGHT,
	END
};

typedef struct sObj {
	string szName;
	int iHp = 0;
	int iAtk = 0;
}OBJ;

typedef struct sItem {
	string szName;
	int iStat = 0;
	ITEM_TYPE type;
}ITEM;