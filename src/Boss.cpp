
#include "Boss.h"
#include "olcPixelGameEngine.h"
#include "Player.h"


using namespace ImpossibleBattleBoss;


cBoss::cBoss() {}

cBoss::cBoss(std::map<BossState, std::vector<olc::Sprite>> * sprites)
{
	this.sprites	= sprites;
	idleTime	= 0;
}


olc::Sprite cBoss::getCurrentSprite()
{
	return sprites[state][currentSprite];	//TODO : currentSprite ?
}


void cBoss::update(cPlayer p, float deltaTIme)
{
	// TODO
}
