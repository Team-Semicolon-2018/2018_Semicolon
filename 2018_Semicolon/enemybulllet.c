#include "fucking_header.h"

void spawnEnemy(int index_of_Enemy, int x, int y, int level) {
	//if (isRight) {
		Enemy[index_of_Enemy].posx = x;
		Enemy[index_of_Enemy].posy = y;
		if (level == 3) {	//3레벨이 제일높은 초록색 놈. 색깔변화: 초->남
			Enemy[index_of_Enemy].health = 2;
		}
		else {
			Enemy[index_of_Enemy].health = 1;
		}
		Enemy[index_of_Enemy].level = level;
		
	//}
	/*
	else {
		Enemy[index_of_Enemy].posx = 3;
		Enemy[index_of_Enemy].posy = 5 - index_of_Enemy;
		Enemy[index_of_Enemy].health = 2;
	}
	*/
}

void drawEnemy(void) {
	for (int i = 0; i < MAX_ENEMY; i++) {
		/*
		if (Enemy[i].health == 0) {
			continue;
		}
		else {
			*/
		if (Enemy[i].health == 0) continue;
		if (Enemy[i].level == 1) { //쫄병. 파란색
			prn_xy("▼", Enemy[i].posx, Enemy[i].posy, CR_TURQ, CR_BLACK, false);	//내가 병신이라 저따구 모양 말고는 적기의 모양으로 떠오르는게 없어서... 주석에다 뭘로 하면 좋을지 의견좀 써주셈.   
		}
		else if (Enemy[i].level == 2) { //이등병, 짙은 빨강.
			prn_xy("▼", Enemy[i].posx, Enemy[i].posy, CR_RED, CR_BLACK, false);	//내가 병신이라 저따구 모양 말고는 적기의 모양으로 떠오르는게 없어서... 주석에다 뭘로 하면 좋을지 의견좀 써주셈.  
		}
		else if (Enemy[i].level == 3 && Enemy[i].health == 2) { //짱병. 초록색. 헬스가 1이면 남색.
			prn_xy("▼", Enemy[i].posx, Enemy[i].posy, CR_GREEN, CR_BLACK, false);	//내가 병신이라 저따구 모양 말고는 적기의 모양으로 떠오르는게 없어서... 주석에다 뭘로 하면 좋을지 의견좀 써주셈.  
		}
		else if (Enemy[i].level == 3 && Enemy[i].health == 1) { //짱병. 초록색. 헬스가 1이면 남색.
			prn_xy("▼", Enemy[i].posx, Enemy[i].posy, CR_BLUE, CR_BLACK, false);	//내가 병신이라 저따구 모양 말고는 적기의 모양으로 떠오르는게 없어서... 주석에다 뭘로 하면 좋을지 의견좀 써주셈.  
		}


			/*
			if (Enemy[i].posx - i > 60)	//적기가 날아가는 모습은 오른쪽에 있는 놈이랑 왼쪽에 있는 놈이라 대칭으로 만들거임. 정확한 모양은 따로 그림 파일 첨부하겠음.
			{
				Enemy[i].posx--;
				Enemy[i].posy++;
			}

			else if (Enemy[i].posx - i > 40)
			{
				Enemy[i].posx--;
				Enemy[i].posy--;
			}

			else if (Enemy[i].posx - i < 20)
			{
				Enemy[i].posx++;
				Enemy[i].posy++;
			}

			else if (Enemy[i].posx - i < 40)
			{
				Enemy[i].posx++;
				Enemy[i].posy--;
			}
			*/
			
		//}
	}
}

void FuckThoseCvalnomeuPlayer(void)
{
	for (int i = 0; i < 20; i++)
	{
		if (Enemy[i].health == 0)
			break;

		else
		{
			for (int j = 0; j < 100; j++)
			{
				if (En_Bullet[j].isused == 1)
					break;

				else
				{
					En_Bullet[j].isused = 1;
					En_Bullet[j].posx = Enemy[i].posx;
					En_Bullet[j].posy = Enemy[i].posy;
				}
			}
		}
	}
}