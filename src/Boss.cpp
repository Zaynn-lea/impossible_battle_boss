#include "Boss.h"
#include "config.h"
#include "olcPixelGameEngine.h"
#include "PlayerClass.h"
#include <cassert>

using namespace ImpossibleBattleBoss;

cBoss::cBoss() : cEntity() {}

cBoss::cBoss(olc::Sprite *defaultSprite, std::map<BossState, BossSpriteVectorPair> sprites, std::vector<olc::Sprite *> fireHeadSprites)
	: cEntity(olc::vi2d(0, 0), createHitbox(0, 0, X_MAX, Y_MAX), defaultSprite, BOSS)
{
	this->sprites = sprites;
	this->fireHeadSprites = fireHeadSprites;

	idleTime = 0;
	state = IDLE_BOSS;
}

cBoss::~cBoss() {}

olc::Sprite *cBoss::getCurrentSprite()
{
	if (state == IDLE_BOSS){
		assert(sprites[state].first.size() == 1);
		backgroundSprite = sprites[state].first[0];
		foregroundSprite = sprites[state].second[0];
	}
	else {
		if (animationCounter >= sprites[state].second.size())
		{
			animationCounter = 0;
			idleTime = 0;
			setState(IDLE_BOSS);
		}
		backgroundSprite = sprites[state].first[animationCounter];
		foregroundSprite = sprites[state].second[animationCounter];
	}
	

	return getSprite();
}

void cBoss::setState(BossState newState)
{
	cAnimable::animationCounter = 0;
	cAnimable::animationSpeed = 0;
	state = newState;
}

olc::Sprite *cBoss::getFireHeadSprite()
{
	return fireHeadSprites[fireHeadCounter];
}

void cBoss::update(cPlayer* p, float deltaTIme)
{
	animationTime += deltaTIme;
	idleTime += deltaTIme;
	if (animationTime >= 0.1)
	{
		animationCounter++;
		fireHeadCounter++;
		if (fireHeadCounter >= fireHeadSprites.size())
			fireHeadCounter = 0;
		animationTime = 0;
	}

	if (state == IDLE_BOSS)
	{
		if (idleTime >= 5.0f)
		{
			idleTime = 0;
			attackSpot = getGridPositionId(p);
			switch (attackSpot)
			{
			case 0:
				std::cout << "Attack spot 0" << std::endl;
				setState(ATTACKING0_BOSS);
				break;
			case 1:
				std::cout << "Attack spot 1" << std::endl;
				setState(ATTACKING1_BOSS);
				break;
			case 2:
				std::cout << "Attack spot 2" << std::endl;
				setState(ATTACKING2_BOSS);
				break;
			case 3:
				std::cout << "Attack spot 3" << std::endl;
				setState(ATTACKING3_BOSS);
				break;
			case 4:
				std::cout << "Attack spot 4" << std::endl;
				setState(ATTACKING4_BOSS);
				break;
			case 5:
				std::cout << "Attack spot 5" << std::endl;
				setState(ATTACKING5_BOSS);
				break;
			}
		}
	}
	else
	{
	}
}

int cBoss::getGridPositionId(cPlayer* player)
{
	int column_index = (player->getPos().x < XSIZE / 2.0) ? 0 : 1;
	std::cout << "Column index: " << column_index << std::endl;

	int row_index = 0;
	double row_height = static_cast<double>(YSIZE) / 3.0;

	if (player->getPos().y < row_height)
	{
		row_index = 0;
	}
	else if (player->getPos().y < 2.0 * row_height)
	{
		row_index = 1;
	}
	else
	{
		row_index = 2;
	}

	std::cout << "Row index: " << row_index << std::endl;
	const int num_cols = 2;
	int grid_id = row_index * 2 + column_index;

	return grid_id;
}