#include "stdafx.h"
#include "main.h"

void LevelClear() {

	prn_xy("Level Clear!", 27, 21, CR_GREEN, CR_BLACK, false);
	Sleep(5000);
	//return 0;


}



void gameOver(int time, int score) {

	PlaySound(TEXT("..\\res\\_galaga_end_theme.wav"), NULL, SND_FILENAME | SND_ASYNC);

	system("cls");
	prn_xy("GAME OVER", 26, 9, CR_LGREEN, CR_BLACK, false);
	char itoa_tmp[10] = { 0, };

	prn_xy("Score: ", 20, 12, CR_TURQ, CR_BLACK, false);
	prn_xy(itoa(score, itoa_tmp, 10), 26, 12, CR_LRED, CR_BLACK, false);

	prn_xy("Time: ", 21, 14, CR_TURQ, CR_BLACK, false);
	prn_xy(itoa(time, itoa_tmp, 10), 26, 14, CR_LRED, CR_BLACK, false);

	//prn_xy("[esc]: Exit Game", 11, 23, CR_LGREEN, CR_BLACK, false);
	//prn_xy("Press Any Key to Continue", 11,24, CR_LGREEN, CR_BLACK, false);
	system("pause");
	AddRank(time, score);
	//Sleep(3000);
	//getch();
	system("pause");
	system("mode con cols=80 lines=30");

	main();
	
}