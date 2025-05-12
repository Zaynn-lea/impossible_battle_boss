
#include "Minion.h"
#include "olcPixelGameEngine.h"


using namespace ImpossibleBattleBoss;


cMinion::cMinion() : cEntity() {}

cMinion::cMinion(olc::vi2d spawnPos, std::map<MinionState, std::vector<olc::Sprite>> * sprites)
	: cEntity(spawnPos, {spawnPos, spawnPos + {sprites[0].width, sprites[0].height}}, sprites[0], MINION)
{
	this->sprites = sprites;
}

cMinion::~cMinion() : {}


olc::Sprite cMinion::getCurrentSprite()	{  return (*sprites)[state][0];  }	// TOOD : replace 0


void cMinion::update(cPlayer p, std::vector<std::vector<cEntity>> * map, float deltaTime)
{
	// TODO
}
