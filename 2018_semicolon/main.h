#pragma once
#include "stdafx.h"

#ifndef MAIN
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

//typedef int bool;
//#define true 1
//#define false 0

#define DEF_RET_VAL 0 //디폴트 리턴 밸류
#define ERR_RET_VAL 1 //에러 발생 시 리턴 밸류 핸들링.
//#define PROGRAM_VERSION "0.8.2_r4" //0.month.day_revision

#define DEFAULT_TXT_COLOR CR_WHITE
#define DEFAULT_BG_COLOR CR_BLACK

#define MAX_ENEMY 50
#define MAX_BULLET 50
#define MAX_ENEMY_BULLET 50


#pragma once
typedef struct _Bullet {
	int posx;
	int posy;
	bool isused;
} Bullet;


typedef struct _Jet {
	int posx;
	int posy;
	int health;
	int level;
} Jet;


extern Jet Enemy[(MAX_ENEMY + 2)];
extern Jet Player;
extern Bullet Pl_Bullet[MAX_BULLET + 2];
extern Bullet En_Bullet[MAX_ENEMY_BULLET];
extern int Round; //나중에 라운드에 따라 적 움직임 다양하게 만들거임. 물론 그러다가 내가 멘탈이 터져서 빡종할거같음.

extern HWND hwnd;
extern HDC hdc; //윈도우 핸들


#define MAIN

#endif


int main(); //어이쿠 실수
void gotoxy(short x, short y);
int prn_xy(const char print[], int x, int y, int txtcolor, int bgcolor, bool enter);
int prn_xy(int print, int x, int y, int txtcolor, int bgcolor, bool enter);

void init();
void hidecursor();

void load(void);

void drawPlayer(void);
void drawBullet(int i);      //플레이어 불렛을 그리는 함수. 그릴 불릿의 인덱스값을 넘겨받음.
void drawEnemyBullet(int i); //에너미 불렛을 그리는 함수. 그릴 불릿의 인덱스값을 넘겨받음.

void title(void);
void start(void);


void control(void);
void FuckthoseCvalnomeuEnemy(void); //총알 발사 관련 함수 (플레이어 -> 에나미)

void FuckThoseCvalnomeuPlayer(int i); //총알 발사 관련 함수 (에너미 -> 플레이어). 인자값 i를 넘겨받아 i번 에너미가 세미콜론을 발사.
void drawEnemy(void);                 //인자값 없이 걍 모든 적을 한번에 출력하는 방식임.
void spawnEnemy(int index_of_Enemy, int x, int y, int level);
//총알 만드는거랑 똑같은 방식으로 만들거임. 어떤 인덱스에 적이 있는지 없는지 확인은 Jet.health가 0인지 아닌지로 판단. 참고로 라운드별로 나오는 적기의 위치는 노가다로 누군가 만들어주길 바랄거임. 인덱스를 인자로 받는 이유는 적기의 인덱스마다 움직이는 궤도가 다르기 때문.  마지막인자는 0이 왼쪽, 1이 오른쪽임.

int chkAliveEnemy(void);
void LevelClear(void);

void gameOver(int time, int score);

int debugScreen(void);


/*start*/
//void SetColor(int num);
void Flush_buffer(void);
void AddRank(int time, int score);
void RankReset(void);
void RankSort(void);
void FileLoad(void);
void FileSave(void);

void RankDraw(bool enternick);


void SoundInit(void);

void StopSound(void);
void VolumeSetSound(void);
void SoundUpdate(void);


void VolumeCtrl(void);
void Sound_Play(int n);
/*
void start(void);
void help(void);
void EndScreen(void);
*/
