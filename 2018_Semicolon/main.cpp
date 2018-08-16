/*
Hell O, world! (Codeneme Semicolon)
-헬, 오 월드! (코드네임 세미콜론)
이 프로그램은 4명의 코더들의 발로 코딩했음
앙, goto띠
FUCKYOU!!!
포인터 X까
-(c) 2018 Semicolon team;
*/

#include "master.h"

Jet Enemy[(MAX_ENEMY + 2)];
Jet Player;
Bullet Pl_Bullet[MAX_BULLET + 2];
Bullet En_Bullet[100];
int Round;   //나중에 라운드에 따라 적 움직임 다양하게 만들거임. 물론 그러다가 내가 멘탈이 터져서 빡종할거같음.
HWND hwnd;
HDC hdc; //윈도우 핸들

void hidecursor() {
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = false; // true 보임 , false 안보임
	ConsoleCursor.dwSize = 1; // 커서 사이즈
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ConsoleCursor);
}

void init() {

	system("title Hell, O world!");
	system("mode con cols=80 lines=30");
	hidecursor();
	for (int i = 0; i <= MAX_ENEMY; i++) {

		Enemy[i].health = 0;
		Enemy[i].posx = 0;
		Enemy[i].posy = 0;
		Enemy[i].level = 0;
	}
	Player.health = 3;
	hwnd = GetForegroundWindow();
	hdc = GetWindowDC(GetForegroundWindow());
}

int main() {
	init();

	start();
	control();
	return DEF_RET_VAL;
}