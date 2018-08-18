#include "stdafx.h"
#include "main.h"


void gotoxy(const short x, const short y) {
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

int prn_xy(const char print[], const int x, const int y, const int txtcolor, const int bgcolor, const bool enter) {

	gotoxy(x, y);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), txtcolor | (bgcolor << 4));

	printf("%s", print);
	if (enter == true) printf("\n");

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), DEFAULT_TXT_COLOR | (DEFAULT_BG_COLOR << 4));
	return DEF_RET_VAL;
}

