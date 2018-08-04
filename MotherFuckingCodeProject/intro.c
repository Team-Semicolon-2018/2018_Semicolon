#include "fucking_header.h"

void load() {
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
	
}

void title() {
	system("cls");

	// <!---Start Printing Logo--->
	prn_xy("  ;;;;;; ", 13, 8, CR_GREEN, CR_BLACK, false);
	prn_xy("  ;::::; ", 13, 9, CR_GREEN, CR_BLACK, false);
	prn_xy("  ;;;;;; ", 13, 10, CR_GREEN, CR_BLACK, false);
	prn_xy("", 13, 11, CR_GREEN, CR_BLACK, false);
	prn_xy("", 13, 12, CR_GREEN, CR_BLACK, false);
	prn_xy("", 13, 13, CR_GREEN, CR_BLACK, false);
	prn_xy("  ;;;;;; ", 13, 14, CR_GREEN, CR_BLACK, false);
	prn_xy("  ;::::; ", 13, 15, CR_GREEN, CR_BLACK, false);
	prn_xy("  ;:::;; ", 13, 16, CR_GREEN, CR_BLACK, false);
	prn_xy(" ;:::;   ", 13, 17, CR_GREEN, CR_BLACK, false);
	prn_xy(" ;;;;    ", 13, 18, CR_GREEN, CR_BLACK, false);
	// <!---End Printing Logo--->
	prn_xy("//'Codename Semicolon' Logo(Ascii Art)(Doh) Here", 27, 7, CR_GREEN, CR_BLACK, false);
	prn_xy("Press Any Key To Start...", 27, 21, CR_GREEN, CR_BLACK, false);
	while (!kbhit()) {
	}
	
}

void start() {
	load();
	title();
	//implement here

}