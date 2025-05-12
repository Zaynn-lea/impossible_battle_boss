
#include "Minion.h"
#include "olcPixelGameEngine.h"


using namespace ImpossibleBattleBoss;


cMinion::cMinion() : cEntity() {}

cMinion::cMinion(olc::vi2d spawnPos, std::map<MinionState, std::vector<olc::Sprite *>> * sprites)
	: cEntity(spawnPos, createHitbox(spawnPos.x, spawnPos.y, spawnPos.x + (*sprites)[ALIVE_MINION][0]->width, spawnPos.y + (*sprites)[ALIVE_MINION][0]->height), (*sprites)[ALIVE_MINION][0], MINION)
{
	this->sprites	= sprites;
	state 		= ALIVE_MINION;
}

cMinion::~cMinion() {}


olc::Sprite * cMinion::getCurrentSprite()	{  return (*sprites)[state][0];  }	// TODO : replace 0


void cMinion::update(cPlayer p, std::vector<std::vector<cEntity>> * map, float deltaTime)
{
	// TODO
}
