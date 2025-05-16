
#include "Boss.h"
#include "config.h"
#include "olcPixelGameEngine.h"
#include "PlayerClass.h"


using namespace ImpossibleBattleBoss;


cBoss::cBoss() : cEntity() {}

cBoss::cBoss(std::map<BossState, std::vector<olc::Sprite *>> * sprites)
	: cEntity(olc::vi2d(0, 0), createHitbox(0, 0, X_MAX, Y_MAX), (*sprites)[IDLE_BOSS][0], BOSS)
{
	this->sprites	= sprites;
	idleTime	= 0;
	state 		= IDLE_BOSS;
}

cBoss::~cBoss() {}


olc::Sprite * cBoss::getCurrentSprite()
{
	return (*sprites)[state][cAnimable::animationCounter];
}


void cBoss::update(cPlayer p, float deltaTIme)
{
	// TODO
}
