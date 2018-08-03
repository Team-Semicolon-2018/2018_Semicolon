#include "fucking_header.h"

void intro() {
	//80x30
	gotoxy(0, 0);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 | (7 << 4)); //회색으로 변경
	printf("Loading Hell O world...                                                         ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 18);

	for (int i = 1; i < 29; i++) {
		for (int j = 0; j < 80; j++) {
			printf(" ");
		}
		printf("\n");
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 | (7 << 4)); //회색으로 변경
	printf("[esc]: Debug mode                                                               ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 18);


	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 | (0 << 4)); //검은박스 그리기
	gotoxy(12, 11);
	for (int i = 11; i < 21; i++) {
		for (int j = 0; j < 60; j++) printf(" ");
		printf("\n");
		gotoxy(12, i);
	}

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 | (4 << 4)); //빨간박스 그리기
	gotoxy(10, 10);
	for (int i = 10; i < 20; i++) {
		for (int j = 0; j < 60; j++) printf(" ");
		printf("\n");
		gotoxy(10, i);
	}

	int percent = 0;

	while (percent <= 100) {
		gotoxy(32, 12);

		printf("Loading... %d%%", percent);

		gotoxy(13, 15);
		printf("[");
		for (int i = 0; i <= (percent/2); i++) {
			printf("=");
		}
		printf(">");
		gotoxy(67, 15);
		printf("]");
		gotoxy(20, 17);
		Sleep(2);
		percent++;
	}
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | (0 << 4));
	title();
}

void title() {

	//implement here
	intro();
}