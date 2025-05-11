
#include "Boss.h"
#include "config.h"
#include "olcPixelGameEngine.h"
#include "Player.h"


using namespace ImpossibleBattleBoss;


cBoss::cBoss() : cEntity() {}

cBoss::cBoss(std::map<BossState, std::vector<olc::Sprite>> * sprites)
	: cEntity({0, 0}, {{0, 0}, {X_MAX, Y_MAX}}, sprites[0], BOSS)
{
	this.sprites	= sprites;
	idleTime	= 0;
}


olc::Sprite cBoss::getCurrentSprite()
{
	// return sprites[state][currentSprite];	// TODO : currentSprite ?
}


void cBoss::update(cPlayer p, float deltaTIme)
{
	// TODO
}
