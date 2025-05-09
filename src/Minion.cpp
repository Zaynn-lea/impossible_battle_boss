
#include "Minion.h"
#include "olcPixelGameEngine.h"


using namespace ImpossibleBattleBoss;


cMinion::cMinion() {}

cMinion::cMinion(olc::vi2d spawnPos, std::map<MinionState, std::vector<olc::Sprite>> * sprites)
{
	pos		= spawnPos;
	this->sprites	= sprites;
}


olc::Sprite cMinion::getCurrentSprite()	{  return sprites[state][currentSprite];  }	// TOOD : curretSprite ?


void cMinion::update(cPlayer p, std::vector<std::vector<cEntity>> * map, float deltaTime)
{
	// TODO
}
