/*
 * Original Source File by lghlove0509, Modded by Computerpark.
 * See Here: https://m.blog.naver.com/PostView.nhn?blogId=lghlove0509&logNo=220815708116&proxyReferer=http%3A%2F%2Fblog.naver.com%2FPostView.nhn%3FblogId%3Dlghlove0509%26logNo%3D220814680325
 * Big Thx to lghlove0509
 * Luv Your Code!
 */


#include "stdafx.h"
#include "main.h"



struct info {
	char name[10];
	int time;
	int score;
};

struct info rank[11];


/*입력버퍼 지우는 함수*/
void Flush_buffer(void)
{
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
}
/*게임이 끝난 후 사용자 이름과 점수,시간을 랭킹에 저장*/
void AddRank(int time, int score)
{
	RankDraw(true); //반드시 먼저 호출
	system("pause");
	system("cls");
	Flush_buffer();
	gotoxy(33, 13);
	printf("닉네임:");
	gotoxy(41, 13);
	scanf("%s",rank[10].name);
	//fgets(rank[10].name, 10, stdin);
	//system("pause");
	rank[10].time = time;
	rank[10].score = score;
	RankSort();
	FileSave();
	RankDraw(false);
}


void RankReset(void)
{
	int i;
	for (i = 0; i<11; i++)
		rank[i].score = 0; //점수가 0점인 상태로 파일을 저장하면 시간,점수,이름이 모두 초기화됨	
	FileSave();
}


/*점수에 따라 랭크 정렬*/
void RankSort(void) //ranksort함수는 셋 이상이 입력된 상태에서 호출하세요 [컴터박]
{
	int i, j, cnt = 0;
	struct info temp;

	for (i = 0; i<10; i++)
	{
		for (j = 0; j<11; j++)
		{
			if(rank[j].time > 100000) {
				rank[j].score = 0;
				rank[j].time = 0;
				rank[j].name[10] = NULL;
			}
			if (rank[j].score < rank[j + 1].score)
			{
				temp = rank[j];
				rank[j] = rank[j + 1];
				rank[j + 1] = temp;
			}
			if (rank[j].score == rank[j+1].score) {
				if(rank[j].time > rank[j+1].time) {
					temp = rank[j];
					rank[j] = rank[j + 1];
					rank[j + 1] = temp;
				}
			}

		}
	}
	FileSave();
}


/*파일을 열어 저장되어있던 데이터를 불러옴*/
void FileLoad(void)
{
	int i;
	FILE *savefile;

	savefile = fopen(".\\savefile\\rank.dat", "r");


	if (savefile == NULL) { //오류 or 파일 없을시 새로 생성 
		savefile = fopen(".\\savefile\\rank.dat", "a");
		fclose(savefile);
		return;
	}


	for (i = 0; i<10; i++)
		fscanf(savefile, "%d %d %s\n", &rank[i].time, &rank[i].score, &rank[i].name);

	fclose(savefile);
}


/*파일을 열어 TOP 10위 랭킹기록 후 저장*/
void FileSave(void)
{
	int i;
	FILE *savefile;
	savefile = fopen(".\\savefile\\rank.dat", "w");

	for (i = 0; i<10; i++) {
		if (rank[i].score == 0) //점수가 0점이면
			fprintf(savefile, "0 0 ---\n");
		else
			fprintf(savefile, "%d %d %s\n", rank[i].time, rank[i].score, rank[i].name);
	}
	fclose(savefile);
}





void RankDraw(bool enternick)
{
	system("mode con cols=80 lines=40");
	const int x = 16;
	int i;

	FileLoad();
	RankSort();

	
	if(enternick==false) {
		prn_xy("ESC : 나가기", 50, 38, CR_WHITE, CR_BLACK, false);
		prn_xy("DELETE : 랭킹 초기화", 10, 38, CR_RED, CR_BLACK, false);
		prn_xy("[랭킹]", 21, 2, CR_TURQ, CR_BLACK, false);

		for (i = 0; i<10; i++) {
			//if (i == 0) SetColor(14);
			gotoxy(x, (i + 1) * 3 + 1);
			printf("[%d위]", i + 1);
			gotoxy(x + 8, (i + 1) * 3 + 1);
			printf("닉네임: %s", rank[i].name);
			gotoxy(x + 26, (i + 1) * 3 + 1);
			printf("시간: %.1f초", (float)rank[i].time/10);
			gotoxy(x + 40, (i + 1) * 3 + 1);
			printf("점수: %d", rank[i].score);
			//SetColor(7);
			Sleep(200);
		}
		while (1)
		{

			if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) break;
			if (GetAsyncKeyState(VK_DELETE) & 0x8000) {
				RankReset();
				break;
			}


		}

		system("cls");
	}
	
}

