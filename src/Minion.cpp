#include "Minion.h"
#include "Entity.h"
#include "PlayerClass.h"
#include "olcPixelGameEngine.h"
#include "pathfind.h"
#include <iostream>

using namespace ImpossibleBattleBoss;

cMinion::cMinion() : cEntity() {}

cMinion::cMinion(olc::vi2d spawnPos, std::map<MinionState, std::vector<olc::Sprite *>> * sprites)
	: cEntity(spawnPos, createHitbox(0, 0, (*sprites)[ALIVE_MINION][0]->width, (*sprites)[ALIVE_MINION][0]->height), (*sprites)[ALIVE_MINION][0], MINION)
{
	this->sprites	= sprites;
	state 		= ALIVE_MINION;
}


olc::Sprite * cMinion::getCurrentSprite()	{  return (*sprites)[state][0];  }	// TODO : replace 0

void cMinion::update(cPlayer p, Grid map, float deltaTime){
  if ((destination == olc::vi2d(-1,-1)) || (getPosInGrid(getPos()) == destination)){
    destination = pathFind(*this, p, map);
  }
  else{
    olc::vi2d trueDest = getCenter(destination);
    int dx = trueDest.x - getPos().x;
    int dy = trueDest.y - getPos().y;
    olc::vf2d newPos = olc::vf2d(getPos().x + (dx * deltaTime), getPos().y + (dy * deltaTime));
    setPos(newPos);
  }
}
