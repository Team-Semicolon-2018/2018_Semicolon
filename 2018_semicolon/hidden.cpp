#include "stdafx.h"
#include "main.h"

int debugScreen() {
	system("cls");
	while (1) {

		puts("Debug Screen!");
		system("pause");
		gameOver(3,3);
	}
}