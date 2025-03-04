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

typedef struct sObj {
	char szName[32] = {};
	int iHp;
	int iAtk;
}OBJ;

typedef struct sItem {
	char szName[32] = {};
	int iStat;
}ITEM;