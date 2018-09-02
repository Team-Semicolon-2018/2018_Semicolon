#include "stdafx.h"
#include "main.h"

/*
#define BULLET ";"	//총알을 세미콜론으로 바꾸면 좀 구림. 적군이 쏘는 총알을 이걸로 바꿔야겠음.
#define BULLET "⊙"
#define BULLET "^"
#define BULLET "↑"
#define BULLET "ㅄ"	//총알 헤더 만들어야할듯...
*/
#define BULLET "┃"
#define ENEMY_BULLET ";"

void drawPlayer(void) {
	/*
	for (int i = Player.posx*10-20; i <= Player.posx*10+20; i++) {
	for (int j = Player.posy*15+100; j <= Player.posy*15+120; j++)
	{

	SetPixel(hdc, i, j, RGB(0, 255, 255));     // 점을 찍는다. RGB( , , )값에 따라 색이 달라진다.
	}
	}
	*/
	prn_xy("凸", Player.posx, Player.posy, CR_LGREEN, CR_BLACK, false);
}


void drawBullet(int i) {
	prn_xy(BULLET, Pl_Bullet[i].posx, Pl_Bullet[i].posy, CR_TURQ, CR_BLACK, false);
	prn_xy(BULLET, Pl_Bullet[i].posx, Pl_Bullet[i].posy + 1, CR_TURQ, CR_BLACK, false);
}

void drawEnemyBullet(int i) {
	prn_xy(ENEMY_BULLET, En_Bullet[i].posx, En_Bullet[i].posy, CR_TURQ, CR_BLACK, false);
	prn_xy(ENEMY_BULLET, En_Bullet[i].posx, En_Bullet[i].posy - 1, CR_TURQ, CR_BLACK, false);
}

void FuckthoseCvalnomeuEnemy(void) {
	int index = 0;
	for (int i = 0; i < MAX_BULLET; i++) {
		if (Pl_Bullet[i].isused == 0) {
			index = i;
			break;
		}
	}

	Pl_Bullet[index].isused = true;
	Sound_Play(S_PL_BULLET);
	//PlaySound(TEXT("..\\res\\bullet.wav"), NULL, SND_FILENAME | SND_ASYNC);
	Pl_Bullet[index].posx = Player.posx;
	Pl_Bullet[index].posy = Player.posy;

}

int chkAliveEnemy() {
	int chk = 0;
	for (int i = 0; i < MAX_ENEMY; i++) {
		if (Enemy[i].health == 0) {
			chk++;
		}
	}
	return chk;

}


DWORD WINAPI musicthread(LPVOID lpParameter) {
	//thread_data *td = (thread_data*)lpParameter;
	//std::cout << "Success! thread id = " << td->m_id << std::endl;
	while (true) {
		SoundUpdate();
		//Sleep(33);
	}
}

DWORD WINAPI moveenemy(LPVOID lpParameter) {
	//thread_data *td = (thread_data*)lpParameter;
	//std::cout << "Success! thread id = " << td->m_id << std::endl;
	while (true) {
		for (int i = 0; i < MAX_ENEMY; i++) {
			Enemy[i].posy++;
		}
		Sleep(1000);

		for (int j = 0; j < 3; j++) {
			for (int i = 0; i < MAX_ENEMY; i++) {
				Enemy[i].posx--;
			}
			Sleep(1000);
		}

		for (int j = 0; j < 3; j++) {
			for (int i = 0; i < MAX_ENEMY; i++) {
				Enemy[i].posx++;
			}
			Sleep(1000);
		}


	}
}

void control(void) {


	CreateThread(nullptr, 0, musicthread, nullptr, 0, nullptr);
	CreateThread(nullptr, 0, moveenemy, nullptr, 0, nullptr);

	clock_t begin_t = clock();

	int score = 0;
	int tmpmvl = 0;
	int tmpmvr = 0;
	Round = 1;

	//플레이어 간격 반드시 3씩 띄울것

	for (int i = 0; i < 10; i++) {
		spawnEnemy(i, 20 + (i * 3), 4, 3); //일등병 소환
	}
	for (int i = 10; i < 20; i++) {
		spawnEnemy(i, 20 + ((i - 10) * 3), 6, 2); //이등병 소환
	}
	for (int i = 20; i < 30; i++) {
		spawnEnemy(i, 20 + ((i - 20) * 3), 8, 1); //맨앞에 졸병 소환
	}

	Player.posx = 40;
	Player.posy = 26;
	//Ready
	system("cls");
	StopSound();
	PlaySound(nullptr, nullptr, SND_FILENAME | SND_ASYNC);
	PlaySound(TEXT("..\\res\\NewPlayerInit.wav"), nullptr, SND_LOOP | SND_ASYNC);
	//Sound_Play(S_START);

	drawEnemy();
	prn_xy("Player 1", 27, 15, CR_RED, CR_BLACK, false);
	Sleep(2000);
	prn_xy("Level", 27, 16, CR_RED, CR_BLACK, false);
	prn_xy(Round, 34, 16, CR_RED, CR_BLACK, false);
	Sleep(2000);

	system("cls");
	drawEnemy();
	prn_xy("Ready", 27, 17, CR_RED, CR_BLACK, false);
	Sleep(4000);

	PlaySound(nullptr, nullptr, SND_FILENAME | SND_ASYNC);


	clock_t nowtime_tmp;
	long int nowtime;
	long int firetime = 0;

	int randtmp;
	VolumeSetSound();
	Sound_Play(S_BGM);
	while (true) {

		//VolumeSetSound();
		drawEnemy();

		//continue 쓰셈
		for (int i = 0; i < MAX_BULLET; i++) {

			if (Pl_Bullet[i].isused == false) {
				continue;
			}

			if (Pl_Bullet[i].posy < 1) {
				Pl_Bullet[i].isused = false;
				continue;
			}

			for (int j = 0; j < MAX_ENEMY; j++) {
				if (Enemy[j].health == 0)
					continue;
				if (((Pl_Bullet[i].posx == Enemy[j].posx) || (Pl_Bullet[i].posx == Enemy[j].posx + 1) || (Pl_Bullet[i].
					posx == Enemy[j].posx - 1)) && (Pl_Bullet[i].posy == Enemy[j].posy)) {
					Pl_Bullet[i].isused = false;
					Enemy[j].health--;
					if (Enemy[j].level == 3 && Enemy[j].health == 1) {
						//PlaySound(TEXT("..\\res\\enemyhit3.wav"), NULL, SND_FILENAME | SND_ASYNC);
						Sound_Play(S_ENEMYHIT3);
					}
					else if (Enemy[j].level == 3 && Enemy[j].health == 0) {
						//PlaySound(TEXT("..\\res\\enemy3die.wav"), NULL, SND_FILENAME | SND_ASYNC);
						Sound_Play(S_ENEMYDIE3);
						score += 3;
					}
					else if (Enemy[j].level == 2) {
						//PlaySound(TEXT("..\\res\\enemyhit2.wav"), NULL, SND_FILENAME | SND_ASYNC);
						Sound_Play(S_ENEMYDIE2);
						score += 2;
					}
					else if (Enemy[j].level == 1) {
						//PlaySound(TEXT("..\\res\\enemyhit1.wav"), NULL, SND_FILENAME | SND_ASYNC);
						Sound_Play(S_ENEMYDIE1);
						score++;
					}
				}
			}

			if (Pl_Bullet[i].isused == true) {

				Pl_Bullet[i].posy--;
				drawBullet(i);

			}

			if (En_Bullet[i].isused == true) {
				for (int j = 0; j < MAX_ENEMY_BULLET; j++) {
					if ((((En_Bullet[j].posx == Pl_Bullet[i].posx) || (En_Bullet[j].posx == Pl_Bullet[i].posx + 1) || (
						En_Bullet[j].posx == Pl_Bullet[i].posx - 1)) && ((En_Bullet[j].posy == Pl_Bullet[i].posy) || (
						En_Bullet[j].posy == Pl_Bullet[i].posy + 1) || (En_Bullet[j].posy == Pl_Bullet[i].posy - 1)))) {
						En_Bullet[i].isused = false;
						Pl_Bullet[i].isused = false;
						score++;
						//continue;
					}
				}

			}


		}


		for (int i = 0; i < MAX_ENEMY_BULLET; i++) {

			if (En_Bullet[i].isused == false) //무조건 맨위에
				continue;

			if (En_Bullet[i].posy > 26) {
				En_Bullet[i].isused = false;
			}

			if (((En_Bullet[i].posx == Player.posx) || (En_Bullet[i].posx == Player.posx + 1) || (En_Bullet[i].posx ==
				Player.posx - 1)) && ((En_Bullet[i].posy == Player.posy) || (En_Bullet[i].posy == Player.posy - 1)))
				//Enemybullet-> Player Hit!
			{
				En_Bullet[i].isused = false;
				Player.health--;
				continue;
			}


			if (En_Bullet[i].isused == true) {
				En_Bullet[i].posy++;
				drawEnemyBullet(i); //수정
			}


			//drawEnemyBullet(i);//수정


		}


		if (((GetAsyncKeyState(KB_LEFT) & 0x8000) || (GetAsyncKeyState(KB_a) & 0x8000) || (GetAsyncKeyState(KB_A) &
			0x8000)) && !(Player.posx < 3)) {
			if (tmpmvl == 0) {
				//slow down
				Player.posx--;
				tmpmvl++;
			}
			else {
				tmpmvl++;
				if (tmpmvl > 3) {
					tmpmvl = 0;
				}
			}


		}
		if (((GetAsyncKeyState(KB_RIGHT) & 0x8000) || (GetAsyncKeyState(KB_d) & 0x8000) || (GetAsyncKeyState(KB_D) &
			0x8000)) && !(Player.posx > 77)) {


			if (tmpmvr == 0) {
				//slow down
				Player.posx++;
				tmpmvr++;
			}
			else {
				tmpmvr++;
				if (tmpmvr > 3) {
					tmpmvr = 0;
				}
			}

		}
		if (GetAsyncKeyState(KB_SPACE) || (GetAsyncKeyState(KB_UP)) || (GetAsyncKeyState(KB_DOWN)) || (
				GetAsyncKeyState(KB_a)) || (GetAsyncKeyState(KB_s)) || (GetAsyncKeyState(KB_A)) || (
				GetAsyncKeyState(KB_S))
		) {

			nowtime_tmp = clock();
			nowtime = nowtime_tmp;


			if (firetime <= (nowtime - 300)) {
				FuckthoseCvalnomeuEnemy();
				firetime = nowtime;
			}

		}


		drawPlayer();
		prn_xy("Health: ", 68, 1, CR_LRED, CR_BLACK, false);
		prn_xy(Player.health, 76, 1, CR_LRED, CR_BLACK, false);
		prn_xy("Alive Enemys: ", 50, 1, CR_LRED, CR_BLACK, false);
		prn_xy(50 - chkAliveEnemy(), 64, 1, CR_LRED, CR_BLACK, false);
		prn_xy("Score: ", 39, 1, CR_TURQ, CR_BLACK, false);
		prn_xy(score, 46, 1, CR_LRED, CR_BLACK, false);
		prn_xy("Time: ", 20, 1, CR_TURQ, CR_BLACK, false);
		clock_t now_t = clock();
		prn_xy((now_t - begin_t) / 100, 26, 1, CR_LRED, CR_BLACK, false);

		system("cls");

		if (chkAliveEnemy() == MAX_ENEMY) {
			LevelClear();
		}
		if (Player.health <= 0) {

			long msec = now_t - begin_t; // 단위는 milliseconds, 나누기 1000 하면 seconds

			gameOver((int)msec / 100, score); //time, score

		}

		srand(clock());
		randtmp = rand();
		if (randtmp % 13 == 0) {
			if ((Enemy[(randtmp % MAX_ENEMY)].health != 0) && (randtmp % MAX_ENEMY) != 0) {

				FuckThoseCvalnomeuPlayer((randtmp % MAX_ENEMY));

			}

		}
	}
}
