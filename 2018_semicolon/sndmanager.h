#pragma once
#include "stdafx.h"
//http://dlgnlfus.tistory.com/23 THX THX U VRY MCH

using namespace FMOD;

enum SOUND {
	BACKGROUND_SND = 0,
	PLAYER_BULLET_SND,
	ENEMY_HIT_1,
	ENEMY_HIT_2,
	ENEMY_HIT_3,
	ENEMY_DIE_3,
	GAMEOVER_SND,
	ENEMY_BULLET_SND,
};

class SoundManager {
public:
	static SoundManager* instance;
	static SoundManager* sharedManager();
	void init();
	void load();
	void play(int _type);
	void stop(int _chnum);
	void ErrChk(FMOD_RESULT _r);

private:
	System * pFmod;
	Channel* ch[10];
	Sound* music[10];
	FMOD_RESULT r;
};
