
#include <algorithm>

#include "config.h"
#include "Entity.h"
#include "olcPixelGameEngine.h"

namespace ImpossibleBattleBoss
{

using namespace ImpossibleBattleBoss;


  cEntity::~cEntity(){} 

	Hitbox createHitbox(int xTopLeft, int yTopLeft, int xBottomRight, int yBottomRight)
	{
		Hitbox hitbox = new _hitbox;

		olc::vi2d topLeft;
		topLeft.x = xTopLeft;
		topLeft.y = yTopLeft;

		olc::vi2d botRight;
		botRight.x = xBottomRight;
		botRight.y = yBottomRight;

		hitbox->topLeft = topLeft;
		hitbox->botRight = botRight;

		return hitbox;
	}

	cEntity::cEntity() {}

	cEntity::cEntity(olc::vi2d spawnCoords, Hitbox hitbox, olc::Sprite *sprite, EntityType type)
	{
		pos = spawnCoords;
		this->hitbox = hitbox;
		this->sprite = sprite;
		this->type = type;
	}

	Hitbox cEntity::getHitbox() { return hitbox; }
	Hitbox cEntity::getAbsHB()
	{
		Hitbox absHb = new _hitbox();

		absHb->topLeft  = pos + hitbox->topLeft;
		absHb->botRight = pos + hitbox->botRight;

		return absHb;
	}
	int cEntity::getHP() { return HP; }
	olc::vi2d cEntity::getPos() { return pos; }
	olc::Sprite *cEntity::getSprite() { return sprite; }

	void cEntity::setHitbox(Hitbox newHitbox) { hitbox = newHitbox; }
	void cEntity::setHP(int newHP) { HP = newHP; }
	void cEntity::setPos(olc::vi2d newPos) { pos = newPos; }
	void cEntity::setSprite(olc::Sprite *newSprite) { sprite = newSprite; }

	bool cEntity::isColliding(cEntity *other)
	{
		bool vertAlign, horzAlign;

		olc::vi2d selfStart, selfEnd, compStart, compEnd;

		Hitbox absHitbox;


		selfStart = getAbsHB()->topLeft;
		selfEnd   = getAbsHB()->botRight;
		compStart = other->getAbsHB()->topLeft;
		compEnd   = other->getAbsHB()->botRight;

		vertAlign = std::max(selfStart.x, compStart.x) <= std::min(selfEnd.x, compEnd.x);
		horzAlign = std::max(selfStart.y, compStart.y) <= std::min(selfEnd.y, compEnd.y);


		return vertAlign && horzAlign;
	}

};
