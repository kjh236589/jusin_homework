#include<iostream>

using namespace std;

struct tObject {
	int iJob;
	int iHp;
	int iAtk;
};

void PrintPlayer(tObject tPlayer);

void PrintMonster(tObject tMonster);

enum GAME {
	START,
	PLAY,
	MONSTER,
	FIGHT,
	END
};

void PlayerInput(tObject* tPlayer, GAME* game);

void PlayerReset(tObject* tPlayer);

void Play(GAME* game);

void ChoiceMonster(tObject* tMonster,GAME* game);

void Fight(tObject* tPlayer, tObject* tMonster, GAME* game);

int main() {
	GAME game = START;
	tObject tPlayer = {}, tMonster = {};
	while (1)
	{
		switch (game) {
		case START:
			PlayerInput(&tPlayer, &game);
			break;
		case PLAY:
			PrintPlayer(tPlayer);
			Play(&game);
			break;
		case MONSTER:
			PrintPlayer(tPlayer);
			ChoiceMonster(&tMonster, &game);
			break;
		case FIGHT:
			PrintPlayer(tPlayer);
			PrintMonster(tMonster);
			Fight(&tPlayer, &tMonster, &game);
			break;
		case END:
			return 0;
		}
		system("cls");
	}
	return 0;
}

void PrintPlayer(tObject tPlayer) {
	cout << "=============================" << endl << "이름 : ";
	switch (tPlayer.iJob)
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
	}
	cout << "체력 : " << tPlayer.iHp << "\t공격력 : " << tPlayer.iAtk << endl;
}

void PrintMonster(tObject tMonster) {
	cout << "=============================" << endl << "이름 : ";
	switch (tMonster.iJob)
	{
	case 1:
		cout << "초급" << endl;
		break;
	case 2:
		cout << "중급" << endl;
		break;
	case 3:
		cout << "고급" << endl;
		break;
	}
	cout << "체력 : " << tMonster.iHp << "\t공격력 : " << tMonster.iAtk << endl;
}

void PlayerInput(tObject* pPlayer, GAME* game) {
	int sInput(0);
	cout << "직업을 선택하세요(1. 전사 2. 마법사 3. 도적) : ";
	cin >> sInput;
	*game = PLAY;
	switch (sInput)
	{
	case 1:
	case 2:
	case 3:
		(*pPlayer).iJob = sInput;
		PlayerReset(pPlayer);
		break;
	default:
		*game = START;
		break;
	}
}

void PlayerReset(tObject* pPlayer) {
	switch ((*pPlayer).iJob)
	{
	case 1:
		*pPlayer = { 1, 100, 10 };
		break;
	case 2:
		*pPlayer = { 2, 50, 30 };
		break;
	case 3:
		*pPlayer = { 3, 80, 15 };
		break;
	}
}

void Play(GAME* game) {
	int sInput(0);
	cout << "1. 사냥터 2. 종료 :";
	cin >> sInput;
	switch (sInput)
	{
	case 1:
		*game = MONSTER;
		break;
	case 2:
		*game = END;
		break;
	}
}

void ChoiceMonster(tObject* pMonster, GAME* game) {
	int sInput(0);
	cout << "1. 초급 2. 중급 3. 고급 4. 전 단계 :";
	cin >> sInput;
	*game = FIGHT;
	switch (sInput)
	{
	case 1:
		*pMonster = { 1, 30, 3 };
		break;
	case 2:
		*pMonster = { 2, 60, 6 };
		break;
	case 3:
		*pMonster = { 3, 90, 9 };
		break;
	case 4:
		*game = PLAY;
		break;
	default:
		*game = MONSTER;
		break;
	}
}

void Fight(tObject* pPlayer, tObject* pMonster, GAME* game) {
	int sInput(0);
	cout << "1. 공격 2. 도망 : ";
	cin >> sInput;
	switch (sInput)
	{
	case 1:
		(*pPlayer).iHp -= (*pMonster).iAtk;
		(*pMonster).iHp -= (*pPlayer).iAtk;
		break;
	case 2:
		*game = MONSTER;
		break;
	}
	if ((*pPlayer).iHp <= 0) {
		cout << "플레이어 사망" << endl;
		PlayerReset(pPlayer);
		*game = MONSTER;
		system("pause");
	}
	else if ((*pMonster).iHp <= 0) {
		cout << "승리" << endl;
		*game = MONSTER;
		system("pause");
	}
}