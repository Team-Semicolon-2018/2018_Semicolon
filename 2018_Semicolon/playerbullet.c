#include "fucking_header.h"
/*
#define BULLET ";"	//총알을 세미콜론으로 바꾸면 좀 구림. 적군이 쏘는 총알을 이걸로 바꿔야겠음.
#define BULLET "⊙"
#define BULLET "^"
#define BULLET "↑"
#define BULLET "ㅄ"	//총알 헤더 만들어야할듯...
*/
#define BULLET "┃"

void drawPlayer(void)
{
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


void drawBullet(int i)
{
	prn_xy(BULLET, Pl_Bullet[i].posx, Pl_Bullet[i].posy, CR_TURQ, CR_BLACK, false);
	prn_xy(BULLET, Pl_Bullet[i].posx, Pl_Bullet[i].posy + 1, CR_TURQ, CR_BLACK, false);
}

void FuckthoseCvalnomeuEnemy(void)
{
	int index = 0;
	for (int i = 0; i < MAX_BULLET; i++)
	{
		if (Pl_Bullet[i].isused == 0)
		{
			index = i;
			break;
		}
	}

	Pl_Bullet[index].isused = 1;
	PlaySound(TEXT("..\\res\\bullet.wav"), NULL, SND_FILENAME | SND_ASYNC);
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

void control(void)
{
	
	Round = 1;
	
	//플레이어 간격 반드시 3씩 띄울것
	
	for (int i = 0; i < 10; i++) {
		spawnEnemy(i, 20+(i*3), 4, 3); //일등병 소환
	}
	for (int i = 10; i < 20; i++) {
		spawnEnemy(i, 20 + ((i - 10) * 3), 6, 2); //이등병 소환
	}
	for (int i = 20; i < 30; i++) {
		spawnEnemy(i, 20 + ((i - 20) * 3), 8, 1); //맨앞에 졸병 소환
	}

	Player.posx = 40;
	Player.posy = 26;
	char itoa_tmp[10] = { 0, };
	//Ready
	system("cls");
	PlaySound(NULL, NULL, SND_FILENAME | SND_ASYNC);
	PlaySound(TEXT("..\\res\\start.wav"), NULL, SND_FILENAME | SND_ASYNC);

	drawEnemy();
	prn_xy("Player 1", 27, 15, CR_RED, CR_BLACK, false);
	Sleep(2000);
	prn_xy("Level", 27, 16, CR_RED, CR_BLACK, false);
	prn_xy(itoa(Round, itoa_tmp, 10), 34, 16, CR_RED, CR_BLACK, false);
	Sleep(2000);

	system("cls");
	drawEnemy();
	prn_xy("Ready", 27, 17, CR_RED, CR_BLACK, false);
	Sleep(4000);

	
	
	clock_t nowtime_tmp = clock();
	long int nowtime = nowtime_tmp;
	long int firetime = 0;
	

	while (true)
	{
		drawEnemy();
		
		//continue 쓰셈
		for (int i = 0; i < MAX_BULLET; i++)
		{
			if (Pl_Bullet[i].isused == false) {
				continue;
			}

			if (Pl_Bullet[i].posy < 1)
			{
				Pl_Bullet[i].isused = 0;
				continue;
			}

			for (int j = 0; j < MAX_ENEMY; j++)
			{
				if (Enemy[j].health == 0)
					continue;
				if (((Pl_Bullet[i].posx == Enemy[j].posx) || (Pl_Bullet[i].posx == Enemy[j].posx + 1) || (Pl_Bullet[i].posx == Enemy[j].posx - 1)) && (Pl_Bullet[i].posy == Enemy[j].posy))
				{
					Pl_Bullet[i].isused = 0;
					Enemy[j].health--;
					if (Enemy[j].level == 3 && Enemy[j].health == 1) {
						PlaySound(TEXT("..\\res\\enemyhit3.wav"), NULL, SND_FILENAME | SND_ASYNC);
					} else if (Enemy[j].level == 3 && Enemy[j].health == 0) {
						PlaySound(TEXT("..\\res\\enemy3die.wav"), NULL, SND_FILENAME | SND_ASYNC);
					} else if (Enemy[j].level == 2) {
						PlaySound(TEXT("..\\res\\enemyhit2.wav"), NULL, SND_FILENAME | SND_ASYNC);
					} else if (Enemy[j].level == 1) {
						PlaySound(TEXT("..\\res\\enemyhit1.wav"), NULL, SND_FILENAME | SND_ASYNC);
					}
				}
			}

			if (Pl_Bullet[i].isused == true)
			{
				
					Pl_Bullet[i].posy--;
					drawBullet(i);	
				
			}
		}

		

		for (int i = 0; i < 100; i++)
		{
			if (En_Bullet[i].isused == false)
				continue;

			if (En_Bullet[i].posy >= 29)
			{
				En_Bullet[i].isused = 0;
				continue;
			}

			if (En_Bullet[i].posx == Player.posx && En_Bullet[i].posy == Player.posy)
			{
				En_Bullet[i].isused = 0;
				Player.health--;
			}
		}
		

		if (((GetAsyncKeyState(KB_LEFT) & 0x8000) || (GetAsyncKeyState(KB_a) & 0x8000) || (GetAsyncKeyState(KB_A) & 0x8000)) && !(Player.posx < 3)) {
			
			Player.posx--;
			
		}
		if (((GetAsyncKeyState(KB_RIGHT) & 0x8000) || (GetAsyncKeyState(KB_d) & 0x8000) || (GetAsyncKeyState(KB_D) & 0x8000)) && !(Player.posx > 77)) {
			
			Player.posx++;
			
			
		}
		if (GetAsyncKeyState(KB_SPACE) || (GetAsyncKeyState(KB_UP)) || (GetAsyncKeyState(KB_DOWN)) || (GetAsyncKeyState(KB_a)) || (GetAsyncKeyState(KB_s)) || (GetAsyncKeyState(KB_A)) || (GetAsyncKeyState(KB_S))) {

			nowtime_tmp = clock();
			nowtime = nowtime_tmp;
			

			if (firetime <= (nowtime - 300)) {
				FuckthoseCvalnomeuEnemy();
				firetime = nowtime;
			}
			
		}
			
		drawPlayer();
		prn_xy("Health: ", 68, 1, CR_LRED, CR_BLACK, false);
		prn_xy(itoa(Player.health, itoa_tmp, 10), 76, 1, CR_LRED, CR_BLACK, false);
		prn_xy("Alive Enemys: ", 50, 1, CR_LRED, CR_BLACK, false);
		prn_xy(itoa(50 - chkAliveEnemy(), itoa_tmp, 10), 64, 1, CR_LRED, CR_BLACK, false);

		system("cls");

		if (chkAliveEnemy() == MAX_ENEMY) {
			LevelClear();
		}
		if (Player.health == 0) {
			gameOver();
		}
	}
}