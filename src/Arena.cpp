
#include "Arena.h"
#include "Entity.h"
#include "olcPixelGameEngine.h"


using namespace ImpossibleBattleBoss;


cArena::cArena() : cEntity() {}

cArena::cArena(olc::vi2d spawnCoords, olc::Sprite * sprite, EntityType type)
	: cEntity(spawnCoords, createHitbox(spawnCoords.x, spawnCoords.y, sprite->width, sprite->height), sprite, type)
{
	setSprite(sprite);
}

cArena::~cArena() {}


olc::Sprite * cArena::getCurrentSprite() { return getSprite(); }


void cArena::update(float fElapsedTime) {}
