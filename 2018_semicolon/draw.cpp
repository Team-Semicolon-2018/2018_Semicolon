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
