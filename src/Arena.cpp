
#include "Arena.h"
#include "Entity.h"
#include "olcPixelGameEngine.h"


using namespace ImpossibleBattleBoss;


cArena::cArena() : cEntity() {}

<<<<<<< HEAD
cArena::cArena(olc::vi2d spawnCoords, olc::Sprite * sprite, EntityType type)
	: cEntity(spawnCoords, createHitbox(spawnCoords.x, spawnCoords.y, sprite->width, sprite->height), sprite, type)
{
	this->sprites = NULL;
}

cArena::cArena(olc::vi2d spawnCoords, std::vector<olc::Sprite *> * sprites, EntityType type)
	: cEntity(spawnCoords, createHitbox(spawnCoords.x, spawnCoords.y, (*sprites)[0]->width, (*sprites)[0]->height), (*sprites)[0], type)
{
	this->sprites = sprites;
}

cArena::~cArena() {}


olc::Sprite * cArena::getCurrentSprite()
{
	if (sprites == NULL)
		return getSprite();
	return (*sprites)[cAnimable::animationCounter];
}


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
=======
cArena::cArena(std::vector<Hitbox>, std::vector<olc::Sprite *> * sprites)
	: cEntity()
{
	
>>>>>>> 0cbec9fad37ecee9bbb7f2964443aefdf9b07c9f
}
