/*
채점자 좆까는 프로그램

Hell O, world!
-헬, 오 월드!

이 좆같은 프로ㄱ램은 4명의 X에 의해 만들어짐.
채점자는 이 X같은 프로그램에 무슨 X이 있는지 알게 되길 바람.(죽기 전에)
발로 코딩했음

앙, goto띠
오류나도 걍 X까
ㅇㅋ?? ^^

FUCKYOU!!!
포인터 좆까
*/


#include "fucking_header.h"
#include "disclaimer.h"

void hidecursor() {
	// <!---------------console cursor settings--------->
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = false; // true 보임 , false 안보임
	ConsoleCursor.dwSize = 1; // 커서 사이즈
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ConsoleCursor);
	// <!---------------console cursor settings end----->
}
void init() {
	system("title Hell, O world!");
	system("mode con cols=80 lines=30");
	hidecursor();
}

int main() {
	
	init();
	
	intro();
	control();
	return DEF_RET_VAL;

}
