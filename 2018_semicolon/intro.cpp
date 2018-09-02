#include "stdafx.h"
#include "main.h"

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
		for (int i = 0; i <= (percent / 2); i++) {
			printf("=");
		}
		printf(">");
		gotoxy(67, 15);
		printf("]");
		gotoxy(20, 17);
		if (GetAsyncKeyState(KB_ESC) & 0x8000) {
			debugScreen();
		}
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
	//
	//
	//
	prn_xy("  ;;;;;; ", 13, 14, CR_GREEN, CR_BLACK, false);
	prn_xy("  ;::::; ", 13, 15, CR_GREEN, CR_BLACK, false);
	prn_xy("  ;:::;; ", 13, 16, CR_GREEN, CR_BLACK, false);
	prn_xy(" ;:::;   ", 13, 17, CR_GREEN, CR_BLACK, false);
	prn_xy(" ;;;;    ", 13, 18, CR_GREEN, CR_BLACK, false);
	// <!---End Printing Logo--->


	prn_xy(" _______  _______  __   __  ___              ", 25, 5, CR_GREEN, CR_BLACK, false);
	prn_xy("|       ||       ||  |_|  ||   |             ", 25, 6, CR_GREEN, CR_BLACK, false);
	prn_xy("|  _____||    ___||       ||   |             ", 25, 7, CR_GREEN, CR_BLACK, false);
	prn_xy("| |_____ |   |___ |       ||   |             ", 25, 8, CR_GREEN, CR_BLACK, false);
	prn_xy("|_____  ||    ___||       ||   |             ", 25, 9, CR_GREEN, CR_BLACK, false);
	prn_xy(" _____| ||   |___ | ||_|| ||   |             ", 25, 10, CR_GREEN, CR_BLACK, false);
	prn_xy("|_______||_______||_|   |_||___|             ", 25, 11, CR_GREEN, CR_BLACK, false);
	prn_xy(" _______  _______  ___      _______  __    _ ", 25, 12, CR_GREEN, CR_BLACK, false);
	prn_xy("|       ||       ||   |    |       ||  |  | |", 25, 13, CR_GREEN, CR_BLACK, false);
	prn_xy("|       ||   _   ||   |    |   _   ||   |_| |", 25, 14, CR_GREEN, CR_BLACK, false);
	prn_xy("|       ||  | |  ||   |    |  | |  ||       |", 25, 15, CR_GREEN, CR_BLACK, false);
	prn_xy("|      _||  |_|  ||   |___ |  |_|  ||  _    |", 25, 16, CR_GREEN, CR_BLACK, false);
	prn_xy("|     |_ |       ||       ||       || | |   |", 25, 17, CR_GREEN, CR_BLACK, false);
	prn_xy("|_______||_______||_______||_______||_|  |__|", 25, 18, CR_GREEN, CR_BLACK, false);




	prn_xy("[↑][↓]:이동 [space]:선택", 27, 21, CR_TURQ, CR_BLACK, false);
	int menuindex = 1;
	prn_xy("Start Game", 27, 23, CR_TURQ, CR_BLACK, false);
	prn_xy("Help", 27, 24, CR_TURQ, CR_BLACK, false);
	prn_xy("Options", 27, 25, CR_TURQ, CR_BLACK, false);
	prn_xy(">", 25, 22 + menuindex, CR_RED, CR_BLACK, false);
	while (1) {
		getch();
		if (GetAsyncKeyState(VK_DOWN)<0) {
			prn_xy(" ", 25, 22 + menuindex, CR_RED, CR_BLACK, false);
			if (menuindex > 1) {
				menuindex--;
			}else {
				menuindex = 3;
			}
			
			PlaySound(TEXT("..\\res\\starfox_vs_menu_move.wav"), NULL, SND_FILENAME | SND_ASYNC);
			prn_xy(">", 25, 22 + menuindex, CR_RED, CR_BLACK, false);
		}
		if (GetAsyncKeyState(VK_UP)<0) {
			prn_xy(" ", 25, 22 + menuindex, CR_RED, CR_BLACK, false);
			if (menuindex < 3) {
				menuindex++;
			}
			else {
				menuindex = 1;
			}
			PlaySound(TEXT("..\\res\\starfox_vs_menu_move.wav"), NULL, SND_FILENAME | SND_ASYNC);
			prn_xy(">", 25, 22 + menuindex, CR_RED, CR_BLACK, false);
		}
		if (GetAsyncKeyState(VK_SPACE)<0) {
			PlaySound(TEXT("..\\res\\starfox_vs_menu_move.wav"), NULL, SND_FILENAME | SND_ASYNC);

			if (menuindex==1) {
				control();

			}
			if(menuindex==2) {
				debugScreen();

			}
			if(menuindex==3) {
				VolumeCtrl();
			}
		}

		
	
	
	
		
		//prn_xy(" ", 25, 22 + menuindex, CR_BLACK, CR_BLACK, false);
		
	}
	fflush(stdin);

}

void start() {
	load();
	title();
	//implement here

}