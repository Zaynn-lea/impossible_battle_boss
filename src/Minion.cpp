
#include "Minion.h"
#include "olcPixelGameEngine.h"


using namespace ImpossibleBattleBoss;


cMinion::cMinion() : cEntity() {}

cMinion::cMinion(olc::vi2d spawnPos, std::map<MinionState, std::vector<olc::Sprite *>> * sprites)
	: cEntity(spawnPos, createHitbox(0, 0, (*sprites)[ALIVE_MINION][0]->width, (*sprites)[ALIVE_MINION][0]->height), (*sprites)[ALIVE_MINION][0], MINION)
{
	this->sprites	= sprites;
	state 		= ALIVE_MINION;
}

cMinion::~cMinion() {}


olc::Sprite * cMinion::getCurrentSprite()	{  return (*sprites)[state][0];  }	// TODO : replace 0


void cMinion::update(cPlayer p, std::vector<std::vector<cEntity *>> map, float deltaTime)
{
	// TODO
}
