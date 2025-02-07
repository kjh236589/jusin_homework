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
	cout << "���� ����!" << endl;
	return 0;
}

void PrintObject(tObject tObject) {
	cout << "=============================" << endl << "�̸� : ";
	switch (tObject.iJob)
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
	case 4:
		cout << "�ʱ�" << endl;
		break;
	case 5:
		cout << "�߱�" << endl;
		break;
	case 6:
		cout << "���" << endl;
		break;
	}
	cout << "ü�� : " << tObject.iHp << "\t���ݷ� : " << tObject.iAtk << endl;
}

tObject PlayerInput(GAME* game) {
	int iInput(0);
	cout << "������ �����ϼ���(1. ���� 2. ������ 3. ����) : ";
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
	cout << "1. ����� 2. ���� :";
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
	cout << "1. �ʱ� 2. �߱� 3. ��� 4. �� �ܰ� :";
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
	cout << "1. ���� 2. ���� : ";
	cin >> iInput;
	switch (iInput)
	{
	case 1:
		pPlayer->iHp -= pMonster->iAtk;
		pMonster->iHp -= pPlayer->iAtk;
		if (pPlayer->iHp <= 0) {
			cout << "�÷��̾� ���" << endl;
			(*pPlayer) = PlayerReset(pPlayer->iJob);
			*game = MONSTER;
			system("pause");
		}
		else if ((*pMonster).iHp <= 0) {
			cout << "�¸�" << endl;
			*game = MONSTER;
			system("pause");
		}
		break;
	case 2:
		*game = MONSTER;
		break;
	}
}