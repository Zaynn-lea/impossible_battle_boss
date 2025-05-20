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

		coords.x = (*sprites)[IDLE_RIGHT_PLAYER][0]->width  - vSprites[0]->width;
		coords.y = (*sprites)[IDLE_RIGHT_PLAYER][0]->height - vSprites[0]->height;

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
	timeInAir     = 0.0;

	setHP(HP_PLAYER);
}

cPlayer::~cPlayer() {}


olc::vf2d 	cPlayer::getPos()	{ return cEntity::getPos() + sprites[state].second; }

PlayerState   cPlayer::getState()		{ return state; }
olc::Sprite * cPlayer::getCurrentSprite()	{ return sprites[state].first[cAnimable::animationCounter]; }

void cPlayer::setState(PlayerState newState)
{
	cAnimable::animationCounter = 0;
	cAnimable::animationSpeed   = 0;
	state = newState;
}

bool cPlayer::getAttackState()	{ return (getState() == ATTACKING_RIGHT_PLAYER) || (getState() == ATTACKING_LEFT_PLAYER); }


void cPlayer::update(std::map<olc::Key, olc::HWButton> keys, olc::HWButton mouse, std::vector<std::vector<cEntity *>> map, float deltaTime)
{
	olc::vf2d mouvment = {0, 0};

	// Gravity and falling down :
	if (isInAir)
	{
		mouvment.y += GRAVITY * deltaTime;
	}

	mouvment += controlToMouvment(keys, mouse, deltaTime);

	setPos(cEntity::getPos() + mouvment);

	applyCollisions(map, mouvment);
	if (getPos().y >= Y_MAX)
	{
		setPos({(float) getPos().x, (float) Y_MAX});
		isInAir = false;
	}

	// Update the sprite :

	cAnimable::animationTime += deltaTime;

	if (cAnimable::animationTime >= animationSpeed)
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

	if ((keys[olc::Key::SPACE].bPressed) || (timeInAir <= PLAYER_JUMP_TIME))
	{
		mouvment.y -= PLAYER_JUMP_CAPACITY * deltaTime;

		timeInAir += deltaTime;

		if (!isInAir)
		{
			timeInAir = 0.0;
			isInAir = true;
		}
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
						setPos({getPos().x - xDeltaHB, (float) getPos().y});
					}
					else
					{
						// Left Ladder
						xDeltaHB = entity->getAbsHB().botRight.x - getAbsHB().topLeft.x;
						setPos({getPos().x + xDeltaHB, (float) getPos().y});
					}

					isInAir = false;
					break;
				}
				}
			}
		}
	}
}


void cPlayer::takeDamage(int amount)
{
	setHP(getHP() - amount);

	// setState(HURT_PLAYER);

	if (getHP() == 0)
		cPlayer::~cPlayer();
}
