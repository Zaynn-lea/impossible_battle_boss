
#include <algorithm>

#include "config.h"
#include "Entity.h"
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


void cPlayer::update(std::map<olc::Key, olc::HWButton> keys, float deltaTime)
{
	olc::vi2d mouvment = {0, 0};


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


	// Update the sprite :

	cAnimable::animationTime += deltaTime;

	if (cAnimable::animationTime >= 0.1)
	{
		cAnimable::animationCounter++;
		cAnimable::animationCounter = cAnimable::animationCounter % (*sprites)[state].size();

		cAnimable::animationTime = 0;
	}
}

