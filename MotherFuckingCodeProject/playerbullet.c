#include "fucking_header.h"

void drawPlayer(void)
{
	prn_xy("Ù»", Player.posx, Player.posy, CR_LGREEN, CR_BLACK, false);
}

void drawBullet(int i)
{
	prn_xy("¶≠", Pl_Bullet[i].posx, Pl_Bullet[i].posy, CR_TURQ, CR_BLACK, false);
	prn_xy("¶≠", Pl_Bullet[i].posx, Pl_Bullet[i].posy + 1, CR_TURQ, CR_BLACK, false);
	//prn_xy("¢¡", Pl_Bullet[i].posx, Pl_Bullet[i].posy, CR_TURQ, CR_BLACK, false);

	//prn_xy("^", Pl_Bullet[i].posx, Pl_Bullet[i].posy, CR_GREEN, CR_BLACK, false);
	//prn_xy("°Ë", Pl_Bullet[i].posx, Pl_Bullet[i].posy, CR_GREEN, CR_BLACK, false);

	//prn_xy("§¥", Pl_Bullet[i].posx, Pl_Bullet[i].posy, CR_GREEN, CR_BLACK, false);

}

void FuckthoseCvalnomeuEnemy(void)
{
	int index = 0;
	for (int i = 0; i < 5; i++)
	{
		if (Pl_Bullet[i].isused == 0)
		{
			index = i;
			break;
		}
	}

	Pl_Bullet[index].isused = 1;
	Pl_Bullet[index].posx = Player.posx;
	Pl_Bullet[index].posy = Player.posy;
}



void control(void)
{
	int ps_tmp = 1, bl_tmp = 1;
	Round = 1;

	spawnEnemy(0, 0);
	spawnEnemy(1, 0);

	Player.posx = 40;
	Player.posy = 26;
	while (true)
	{
		drawEnemy();

		for (int i = 0; i < 5; i++)
		{
			if (Pl_Bullet[i].isused == false) {
				break;
			}

			if (Pl_Bullet[i].posy < 1)
			{
				Pl_Bullet[i].isused = 0;
				break;
			}

			for (int j = 0; j < 20; j++)
			{
				if (Enemy[j].health == false)
					break;
				if (Pl_Bullet[i].posx == Enemy[j].posx && Pl_Bullet[i].posy == Enemy[j].posy)
				{
					Pl_Bullet[i].isused = 0;
					Enemy[j].health--;
				}
			}

			if (Pl_Bullet[i].isused == true)
			{
				Pl_Bullet[i].posy--;

				drawBullet(i);
			}
		}

		for (int i = 0; i < 100; i++)
		{
			if (En_Bullet[i].isused == false)
				break;

			if (En_Bullet[i].posy >= 29)
			{
				En_Bullet[i].isused = 0;
				break;
			}

			if (En_Bullet[i].posx == Player.posx && En_Bullet[i].posy == Player.posy)
			{
				En_Bullet[i].isused = 0;
				Player.health--;
			}
		}
		/*
		if (kbhit())
		{
			int whatKey = getch();
			if ((whatKey == KB_LEFT) && !(Player.posx < 3)) // left
				Player.posx--;

			if ((whatKey == KB_RIGHT) && !(Player.posx > 77)) //right
				Player.posx++;

			if (whatKey == KB_SPACE)
				FuckthoseCvalnomeuEnemy();
		}
		*/

		if ((GetAsyncKeyState(VK_LEFT) & 0x8000) && !(Player.posx < 3)) {
			if (ps_tmp == 1) {
				Player.posx--;
				ps_tmp++;
			}
			else {
				ps_tmp++;
			}
			
		}
		if ((GetAsyncKeyState(VK_RIGHT) & 0x8000) && !(Player.posx > 77)) {
			if (ps_tmp == 1) {
				Player.posx++;
				ps_tmp++;
			}
			else {
				ps_tmp++;
			}
		}
		if (GetAsyncKeyState(KB_SPACE) && bl_tmp == 1)
			FuckthoseCvalnomeuEnemy();
		
		bl_tmp++;

		if (bl_tmp > 7) bl_tmp = 1;

		if (ps_tmp > 4) ps_tmp = 1;
		drawPlayer();

		system("cls");
	}
}