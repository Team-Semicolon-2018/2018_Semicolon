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
	system("cls");
	for (x = 0; x < 41; x++) {
		prn_xy("GAME OVER", x, y, CR_LPURPLE, CR_LTURQ, true);
		y++;
	}
	Sleep(3000);
	system("pause");
	main();
	
}