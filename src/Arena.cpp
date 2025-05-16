
#include "Arena.h"
#include "Entity.h"
#include "olcPixelGameEngine.h"


using namespace ImpossibleBattleBoss;


cArena::cArena() : cEntity() {}

cArena::cArena(olc::vi2d spawnCoords, olc::Sprite * sprite, ArenaType type)
	: cEntity(spawnCoords, createHitbox(spawnCoords.x, spawnCoords.y, sprite->width, sprite->height), sprite, WALL)
{
	this->sprites = NULL;
	this->subType = type;
}

cArena::cArena(olc::vi2d spawnCoords, std::vector<olc::Sprite *> * sprites, ArenaType type)
	: cEntity(spawnCoords, createHitbox(spawnCoords.x, spawnCoords.y, (*sprites)[0]->width, (*sprites)[0]->height), (*sprites)[0], WALL)
{
	this->sprites = sprites;
	this->subType = type;
}

cArena::~cArena() {}


olc::Sprite * cArena::getCurrentSprite()
{
	if (sprites == NULL)
		return getSprite();
	return (*sprites)[cAnimable::animationCounter];
}


ArenaType cArena::getSubType() { return subType; }


void cArena::update(float fElapsedTime)
{
	if (sprites != NULL)
	{
		cAnimable::animationTime += fElapsedTime;

		if (cAnimable::animationTime >= 0.1)
		{
			cAnimable::animationCounter++;
			cAnimable::animationCounter = cAnimable::animationCounter % (*sprites).size();

			cAnimable::animationTime = 0;
		}
	}
}
