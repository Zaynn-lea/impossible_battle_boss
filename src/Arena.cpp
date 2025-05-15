
#include "Arena.h"
#include "Entity.h"
#include "olcPixelGameEngine.h"


using namespace ImpossibleBattleBoss;


cArena::cArena() : cEntity() {}

cArena::cArena(olc::vi2d spawnCoords, std::vector<olc::Sprite *> * sprites, EntityType type)
	: cEntity(spawnCoords, createHitbox(spawnCoords.x, spawnCoords.y, (*sprites)[0]->width, (*sprites)[0]->height), (*sprites)[0], type)
{
	this->sprites = sprites;
}

cArena::~cArena() {}


olc::Sprite * cArena::getCurrentSprite() { return (*sprites)[cAnimable::animationCounter]; }


void cArena::update(float fElapsedTime) {}
