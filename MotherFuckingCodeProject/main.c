/*
Hell O, world! (Codeneme Semicolon)
-헬, 오 월드!
이 X같은 프로그램은 4명의 X같은 코더들의 발로 코딩했음
앙, goto띠
FUCKYOU!!!
포인터 X까
-(c) 2018 Semicolon team;
*/

#include "fucking_header.h"
#include "disclaimer.h"

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
	}

}

int main() {
	init();
	
	start();
	control();
	return DEF_RET_VAL;
}