#pragma once
class CItem
{
public:
	void SetItem(const char* szName, int iPrice) {
		strcpy_s(this->szName, sizeof(this->szName), szName);
		this->iPrice = iPrice;
	}
	void Print() {
		cout << szName;
	}
private:
	char szName[32];
	int iPrice;
};

