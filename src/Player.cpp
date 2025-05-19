#include <iostream>
#include <algorithm>

#include "config.h"
#include "Entity.h"
#include "Arena.h"
#include "Player.h"
#include "olcPixelGameEngine.h"


using namespace ImpossibleBattleBoss;


cPlayer::cPlayer() : cEntity() {}

cPlayer::cPlayer(olc::vi2d spawnCoords,  PlayerSpriteMap* sprites)
	: cEntity(spawnCoords, createHitbox(0, 0, (*sprites)[IDLE_RIGHT_PLAYER][0]->width, (*sprites)[IDLE_RIGHT_PLAYER][0]->height), (*sprites)[IDLE_RIGHT_PLAYER][0], PLAYER)
{
	olc::vi2d 	coords;
	Hitbox  	tempHB;
	for (auto const &[states, vSprites] : (*sprites))
	{
		tempHB = getHitbox();

		coords.x = vSprites[0]->width  - (tempHB.botRight.x - tempHB.topLeft.x);
		coords.y = vSprites[0]->height - (tempHB.botRight.y - tempHB.topLeft.y);

		this->sprites.insert(
			std::pair<PlayerState, std::pair<std::vector<olc::Sprite *>, olc::vi2d>>(
				states,
				std::pair<std::vector<olc::Sprite *>, olc::vi2d>(
					vSprites, coords
				)
			)
		);
	}

	state	      = IDLE_RIGHT_PLAYER;
	isKeyPressed  = false;
	isRight	      = true;
	isInAir	      = true;
}

cPlayer::~cPlayer() {}


olc::vf2d 	cPlayer::getPos()	{ return cEntity::getPos(); /* + sprites[state].second; */ }

PlayerState   cPlayer::getState()		{ return state; }
olc::Sprite * cPlayer::getCurrentSprite()	{ return sprites[state].first[cAnimable::animationCounter]; }

void cPlayer::setState(PlayerState newState)
{
	cAnimable::animationCounter = 0;
	cAnimable::animationSpeed   = 0;
	state = newState;
}


void cPlayer::update(std::map<olc::Key, olc::HWButton> keys, olc::HWButton mouse, std::vector<std::vector<cEntity *>> map, float deltaTime)
{
	olc::vf2d mouvment = {0, 0};

	// Gravity and falling down :
	if (isInAir)
	{
		mouvment.y += GRAVITY * deltaTime;
	}

	//mouvment += controlToMouvment(keys, mouse, deltaTime);
    // setPos(getPos() + mouvment);
	olc::vf2d b = getPos() + mouvment;

	setPos(b);

	applyCollisions(map, mouvment);
	if (getPos().y >= Y_MAX)
	{
		setPos({(float) getPos().x, (float) Y_MAX});
		isInAir = false;
	}


	// Update the sprite :

	cAnimable::animationTime += deltaTime;

	if (cAnimable::animationTime >= 0.1)
	{
		cAnimable::animationCounter++;
		cAnimable::animationCounter = cAnimable::animationCounter % sprites[state].first.size();

		cAnimable::animationTime = 0;
	}
}


// Supporting functions for update()

olc::vi2d cPlayer::controlToMouvment(std::map<olc::Key, olc::HWButton> keys, olc::HWButton mouse, float deltaTime)
{
	olc::vf2d mouvment = {0, 0};

	if (mouse.bPressed)
	{
		if (isRight) setState(ATTACKING_RIGHT_PLAYER);
		else setState(ATTACKING_LEFT_PLAYER);
		isAttacking = true;
	}
	else if (cAnimable::animationCounter == sprites[ATTACKING_LEFT_PLAYER].first.size() - 1)
	{
		isAttacking = false;
	}

	if (keys[olc::Key::Q].bHeld)
	{
		//mouvment.x -= std::min(PLAYER_SPEED * deltaTime, (float) (getAbsHB().topLeft.x));
		mouvment.x -= PLAYER_SPEED * deltaTime; 

		isRight = false;

		if (!isKeyPressed)
		{
			setState(WALKING_LEFT_PLAYER);
			isKeyPressed = true;
		}
	}
	else if (keys[olc::Key::D].bHeld)
	{

		//mouvment.x += std::min(PLAYER_SPEED * deltaTime, (float) (X_MAX - getAbsHB().botRight.x));
		mouvment.x += PLAYER_SPEED * deltaTime;

		isRight = true;

		if (!isKeyPressed)
		{
			setState(WALKING_RIGHT_PLAYER);
			isKeyPressed = true;
		}
	}
	else if (isKeyPressed || !isAttacking)
	{
		if (isRight)
			setState(IDLE_RIGHT_PLAYER);
		else
			setState(IDLE_LEFT_PLAYER);

		isKeyPressed = false;
		isAttacking  = true;
	}

	return mouvment;
}


void cPlayer::applyCollisions(Grid map, olc::vi2d mouvment)
{
	for (auto & line : map)
	{
		for (auto & entity : line)
		{
			if (entity == NULL)
				continue;
			if (isColliding(entity))
			{
				switch ((entity->getType())){
				case PLATFORM:
				{
					float yDeltaHB;

					if (getPos().y - mouvment.y >= entity->getAbsHB().topLeft.y)
					{
						yDeltaHB = getAbsHB().botRight.y - entity->getAbsHB().topLeft.y;
						setPos({(float) getPos().x, (float) entity->getAbsHB().topLeft.y - yDeltaHB});
						isInAir = false;
					}
					else
					{
						yDeltaHB = entity->getAbsHB().botRight.y - getAbsHB().topLeft.y;
						setPos({(float) getPos().x, (float) entity->getAbsHB().topLeft.y + yDeltaHB});
					}
					break;
				}
				case PLATFORMARIO:
				{
					float yDeltaHB;

					if (getPos().y - mouvment.y >= entity->getAbsHB().topLeft.y)
					{
						yDeltaHB = getAbsHB().botRight.y - entity->getAbsHB().topLeft.y;
						setPos({(float) getPos().x, (float) entity->getAbsHB().topLeft.y - yDeltaHB});
						isInAir = false;
					}
					break;
				}
				case LADDER:
				{
					float xDeltaHB;
					
					if (getPos().x > X_MIDDLE)
					{
						// Right Ladder
					
						xDeltaHB = getAbsHB().botRight.x - entity->getAbsHB().topLeft.x;
					}
					else
					{
						// Left Ladder

						xDeltaHB = entity->getAbsHB().botRight.x - getAbsHB().topLeft.x;
					}
					setPos({getPos().x + xDeltaHB, (float) getPos().y});
					isInAir = false;
					break;
				}

				case MINION:
				{
					if (!isAttacking)
					{
						setHP(getHP() - ATTACK_POWER_MINION);
					}
					break;
				}
				}
			}
		}
	}
}