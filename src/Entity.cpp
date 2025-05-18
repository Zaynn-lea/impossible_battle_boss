
#include "config.h"
#include "Entity.h"
#include "olcPixelGameEngine.h"

namespace ImpossibleBattleBoss
{

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

	cEntity::cEntity(olc::vf2d spawnCoords, Hitbox hitbox, olc::Sprite *sprite, EntityType type)
	{
		pos = spawnCoords;
		this->hitbox = hitbox;
		this->sprite = sprite;
		this->type = type;
	}

	Hitbox cEntity::getHitbox() { return hitbox; }
	int cEntity::getHP() { return HP; }
	olc::vf2d cEntity::getPos() { return pos; }
	olc::Sprite *cEntity::getSprite() { return sprite; }

	void cEntity::setHitbox(Hitbox newHitbox) { hitbox = newHitbox; }
	void cEntity::setHP(int newHP) { HP = newHP; }
	void cEntity::setPos(olc::vf2d newPos) { pos = newPos; }
	void cEntity::setSprite(olc::Sprite *newSprite) { sprite = newSprite; }

	bool cEntity::isColliding(cEntity *other)
	{
		return false; // TODO
	}

};
