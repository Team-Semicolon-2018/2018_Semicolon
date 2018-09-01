#include "stdafx.h"
#include "sndmanager.h"
#include ".//inc//fmod_errors.h"

//http://dlgnlfus.tistory.com/23 THX THX U VRY MCH


SoundManager* SoundManager::sharedManager() {
	if (instance==NULL) {
		instance = new SoundManager;
	}
	return instance;
}

void SoundManager::init() {
	r = System_Create(&pFmod);
	ErrChk(r);
	r = pFmod->init(100, FMOD_INIT_NORMAL, NULL);
	ErrChk(r);
}

void SoundManager::load() {
	r = pFmod->createSound("..\\res\\bgm.wav", FMOD_LOOP_NORMAL, NULL, &music[BACKGROUND_SND]);
	ErrChk(r); //fuck
	r = pFmod->createSound("..\\res\\bullet.wav", FMOD_DEFAULT, NULL, &music[PLAYER_BULLET_SND]);
	ErrChk(r); //fuck
	r = pFmod->createSound("..\\res\\enemyhit1.wav", FMOD_DEFAULT, NULL, &music[ENEMY_HIT_1]);
	ErrChk(r); //fuck
	r = pFmod->createSound("..\\res\\enemyhit2.wav", FMOD_DEFAULT, NULL, &music[ENEMY_HIT_1]);
	ErrChk(r); //fuck
	r = pFmod->createSound("..\\res\\enemyhit3.wav", FMOD_DEFAULT, NULL, &music[ENEMY_HIT_3]);
	ErrChk(r); //fuck
	r = pFmod->createSound("..\\res\\enemy3die.wav", FMOD_DEFAULT, NULL, &music[ENEMY_DIE_3]);
	ErrChk(r); //fuck

	r = pFmod->createSound("..\\res\\_galaga_end_theme.wav", FMOD_DEFAULT, NULL, &music[GAMEOVER_SND]);
	ErrChk(r); //fuck
	//r = pFmod->createSound("..\\res\\enemy3die.wav", FMOD_DEFAULT, NULL, &music[ENEMY_BULLET_SND]);
	//ErrChk(r); //fuck -->추후 에너미 불렛 사운드 작업

}

void SoundManager::play(int _type) {
	pFmod->update();
	r = pFmod->playSound(FMOD_CHANNEL_FREE, music[_type], false, &ch[_type]);
	ErrChk(r);
}

void SoundManager::stop(int _chNum) {
	ch[_chNum]->stop();
}

void SoundManager::ErrChk(FMOD_RESULT _r) {
	if (_r != FMOD_OK) {
		TCHAR szStr[256] = { 0 };
		MultiByteToWideChar(CP_ACP, NULL, FMOD_ErrorString(r), -1, szStr, 256);
		MessageBox(NULL, szStr, L"Sound Error", MB_OK);
	}
}