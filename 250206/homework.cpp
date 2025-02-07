#include<iostream>

using namespace std;

struct tObject {
	int iJob;
	int iHp;
	int iAtk;
};

enum GAME {
	START,
	PLAY,
	MONSTER,
	FIGHT,
	END
};

void PrintObject(tObject tObject);

tObject PlayerInput(GAME* game);

tObject PlayerReset(int iJob);

void Play(GAME* game);

tObject ChoiceMonster(GAME* game);

void Fight(tObject* tPlayer, tObject* tMonster, GAME* game);

int main() {
	GAME game = START;
	tObject tPlayer = {}, tMonster = {};
	while (END != game)
	{
		system("cls");
		switch (game) {
		case START:
			tPlayer = PlayerInput(&game);
			break;
		case PLAY:
			PrintObject(tPlayer);
			Play(&game);
			break;
		case MONSTER:
			PrintObject(tPlayer);
			tMonster = ChoiceMonster(&game);
			break;
		case FIGHT:
			PrintObject(tPlayer);
			PrintObject(tMonster);
			Fight(&tPlayer, &tMonster, &game);
			break;
		}
	}
	cout << "게임 종료!" << endl;
	return 0;
}

void PrintObject(tObject tObject) {
	cout << "=============================" << endl << "이름 : ";
	switch (tObject.iJob)
	{
	case 1:
		cout << "전사" << endl;
		break;
	case 2:
		cout << "마법사" << endl;
		break;
	case 3:
		cout << "도적" << endl;
		break;
	case 4:
		cout << "초급" << endl;
		break;
	case 5:
		cout << "중급" << endl;
		break;
	case 6:
		cout << "고급" << endl;
		break;
	}
	cout << "체력 : " << tObject.iHp << "\t공격력 : " << tObject.iAtk << endl;
}

tObject PlayerInput(GAME* game) {
	int iInput(0);
	cout << "직업을 선택하세요(1. 전사 2. 마법사 3. 도적) : ";
	cin >> iInput;
	*game = PLAY;
	tObject tPlayer = {};
	switch (iInput)
	{
	case 1:
	case 2:
	case 3:
		tPlayer = PlayerReset(iInput);
		break;
	default:
		*game = START;
		break;
	}
	return tPlayer;
}

tObject PlayerReset(int iJob) {
	tObject tPlayer = {};
	switch (iJob)
	{
	case 1:
		tPlayer = { 1, 100, 10 };
		break;
	case 2:
		tPlayer = { 2, 50, 30 };
		break;
	case 3:
		tPlayer = { 3, 80, 15 };
		break;
	}
	return tPlayer;
}

void Play(GAME* game) {
	int iInput(0);
	cout << "1. 사냥터 2. 종료 :";
	cin >> iInput;
	switch (iInput)
	{
	case 1:
		*game = MONSTER;
		break;
	case 2:
		*game = END;
		break;
	}
}

tObject ChoiceMonster(GAME* game) {
	int iInput(0);
	cout << "1. 초급 2. 중급 3. 고급 4. 전 단계 :";
	cin >> iInput;
	*game = FIGHT;
	tObject tMonster = {};
	switch (iInput)
	{
	case 1:
		tMonster = { 4, 30, 3 };
		break;
	case 2:
		tMonster = { 5, 60, 6 };
		break;
	case 3:
		tMonster = { 6, 90, 9 };
		break;
	case 4:
		*game = PLAY;
		break;
	default:
		*game = MONSTER;
		break;
	}
	return tMonster;
}

void Fight(tObject* pPlayer, tObject* pMonster, GAME* game) {
	int iInput(0);
	cout << "1. 공격 2. 도망 : ";
	cin >> iInput;
	switch (iInput)
	{
	case 1:
		pPlayer->iHp -= pMonster->iAtk;
		pMonster->iHp -= pPlayer->iAtk;
		if (pPlayer->iHp <= 0) {
			cout << "플레이어 사망" << endl;
			(*pPlayer) = PlayerReset(pPlayer->iJob);
			*game = MONSTER;
			system("pause");
		}
		else if ((*pMonster).iHp <= 0) {
			cout << "승리" << endl;
			*game = MONSTER;
			system("pause");
		}
		break;
	case 2:
		*game = MONSTER;
		break;
	}
}