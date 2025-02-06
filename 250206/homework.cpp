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
	cout << "=============================" << endl << "�̸� : ";
	switch (tPlayer.iJob)
	{
	case 1:
		cout << "����" << endl;
		break;
	case 2:
		cout << "������" << endl;
		break;
	case 3:
		cout << "����" << endl;
		break;
	}
	cout << "ü�� : " << tPlayer.iHp << "\t���ݷ� : " << tPlayer.iAtk << endl;
}

void PrintMonster(tObject tMonster) {
	cout << "=============================" << endl << "�̸� : ";
	switch (tMonster.iJob)
	{
	case 1:
		cout << "�ʱ�" << endl;
		break;
	case 2:
		cout << "�߱�" << endl;
		break;
	case 3:
		cout << "���" << endl;
		break;
	}
	cout << "ü�� : " << tMonster.iHp << "\t���ݷ� : " << tMonster.iAtk << endl;
}

void PlayerInput(tObject* pPlayer, GAME* game) {
	int sInput(0);
	cout << "������ �����ϼ���(1. ���� 2. ������ 3. ����) : ";
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
	cout << "1. ����� 2. ���� :";
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
	cout << "1. �ʱ� 2. �߱� 3. ��� 4. �� �ܰ� :";
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
	cout << "1. ���� 2. ���� : ";
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
		cout << "�÷��̾� ���" << endl;
		PlayerReset(pPlayer);
		*game = MONSTER;
		system("pause");
	}
	else if ((*pMonster).iHp <= 0) {
		cout << "�¸�" << endl;
		*game = MONSTER;
		system("pause");
	}
}