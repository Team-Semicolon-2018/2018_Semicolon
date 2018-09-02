#include "stdafx.h"
#include "main.h"


void gotoxy(short x, short y) {
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

int prn_xy(const char print[], int x, int y, int txtcolor, int bgcolor, bool enter) { //bool enter의 디푤트 벨류. 빼먹어도 된다
	gotoxy(x, y);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), txtcolor | (bgcolor << 4));

	printf("%s", print);
	if (enter) printf("\n");

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), DEFAULT_TXT_COLOR | (DEFAULT_BG_COLOR << 4));

	return DEF_RET_VAL;
}

int prn_xy(int print, int x, int y, int txtcolor, int bgcolor, bool enter) { //cpp에서는 매개변수의 형식이 다르면 이름이 같은 함수를 허용한다. 편하게 int로 호출하자

	gotoxy(x, y);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), txtcolor | (bgcolor << 4));

	printf("%d", print);
	if (enter) printf("\n");

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), DEFAULT_TXT_COLOR | (DEFAULT_BG_COLOR << 4));

	return DEF_RET_VAL;
}