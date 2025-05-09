
#include "Minion.h"
#include "olcPixelGameEngine.h"


using namespace ImpossibleBattleBoss;


cMinion::cMinion() {}


olc::Sprite cMinion::getCurrentSprite()	{  return sprites[state][currentSprite];  }	// TOOD : curretSprite ?


void cMinion::update(cPlayer p, float deltaTime)
{
	// TODO
}
