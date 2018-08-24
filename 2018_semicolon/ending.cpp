#include "stdafx.h"
#include "main.h"

void LevelClear() {

	prn_xy("Level Clear!", 27, 21, CR_GREEN, CR_BLACK, false);
	Sleep(5000);
	//return 0;


}



void gameOver() {
	int x = 0;
	int y = 15;
	PlaySound(TEXT("..\\res\\_galaga_end_theme.wav"), NULL, SND_FILENAME | SND_ASYNC);

	system("cls");
	for (x = 0; x < 41; x++) {
		prn_xy("GAME OVER", x, y, CR_LPURPLE, CR_LTURQ, false);
		y++;
	}
	
	prn_xy("[esc]: Exit Game", 11, 23, CR_LGREEN, CR_BLACK, false);
	prn_xy("Press Any Key to Continue", 11,24, CR_LGREEN, CR_BLACK, false);
	AddRank(3333, 333334);
	Sleep(3000);
	getch();
	system("pause");
	system("mode con cols=80 lines=30");

	main();
	
}