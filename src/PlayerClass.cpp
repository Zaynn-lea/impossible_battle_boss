
#include <algorithm>

#include "config.h"
#include "Entity.h"
#include "Arena.h"
#include "PlayerClass.h"
#include "olcPixelGameEngine.h"


using namespace ImpossibleBattleBoss;


cPlayer::cPlayer() : cEntity() {}

cPlayer::cPlayer(olc::vi2d spawnCoords, std::map<PlayerState, std::vector<olc::Sprite *>> * sprites)
	: cEntity(spawnCoords, createHitbox(0, 0, (*sprites)[IDLE_RIGHT_PLAYER][0]->width, (*sprites)[IDLE_RIGHT_PLAYER][0]->height), (*sprites)[IDLE_RIGHT_PLAYER][0], PLAYER)
{
	this->sprites = sprites;
	state	      = IDLE_RIGHT_PLAYER;
	isKeyPressed  = false;
	isRight	      = true;
	isInAir	      = true;
}

cPlayer::~cPlayer() {}



PlayerState   cPlayer::getState()		{ return state; }
olc::Sprite * cPlayer::getCurrentSprite()	{ return (*sprites)[state][cAnimable::animationCounter]; }

void cPlayer::setState(PlayerState newState)
{
	cAnimable::animationCounter = 0;
	cAnimable::animationSpeed   = 0;

	state = newState;
}


void cPlayer::update(std::map<olc::Key, olc::HWButton> keys, std::vector<std::vector<cEntity *>> map, float deltaTime)
{
	olc::vi2d mouvment = {0, 0};

	// Gravity and falling down :

	if (isInAir)
	{
		mouvment.y += GRAVITY * deltaTime;
	}

	// Mouvment from player input

	if (keys[olc::Key::Q].bHeld)
	{
		mouvment.x -= std::min(PLAYER_SPEED * deltaTime, (float) (getAbsHB()->topLeft.x));

		isRight = false;

		if (!isKeyPressed)
		{
			setState(WALKING_LEFT_PLAYER);
			isKeyPressed = true;
		}
	}
	else if (keys[olc::Key::D].bHeld)
	{
		mouvment.x += std::min(PLAYER_SPEED * deltaTime, (float) (X_MAX - getAbsHB()->botRight.x));

		isRight = true;

		if (!isKeyPressed)
		{
			setState(WALKING_RIGHT_PLAYER);
			isKeyPressed = true;
		}
	}
	else if (isKeyPressed)
	{
		if (isRight)
			setState(IDLE_RIGHT_PLAYER);
		else
			setState(IDLE_LEFT_PLAYER);
		isKeyPressed = false;
	}

	setPos(getPos() + mouvment);


	// Collisions :

	for (auto & line : map)
	{
		for (auto & entity : line)
		{
			if (isColliding(entity) && (entity->getType() == WALL))
			{
				// TODO : switching between the different types to know what to do with the coords

				switch (((cArena *)entity)->getSubType())
				{
				case PLATEFORM:
				{
					int yDeltaHB = entity->getHitbox()->botRight.y - entity->getHitbox()->topLeft.y;
					setPos({getPos().x, entity->getAbsHB()->topLeft.y - yDeltaHB});
					isInAir = false;
					break;
				}

				case LADDER:
				{
					int xDeltaHB = entity->getHitbox()->botRight.x - entity->getHitbox()->topLeft.x;
					setPos({entity->getAbsHB()->topLeft.x - xDeltaHB, getPos().x});
					break;
				}
				}
			}
		}
	}


	// Update the sprite :

	cAnimable::animationTime += deltaTime;

	if (cAnimable::animationTime >= 0.1)
	{
		cAnimable::animationCounter++;
		cAnimable::animationCounter = cAnimable::animationCounter % (*sprites)[state].size();

		cAnimable::animationTime = 0;
	}
}

