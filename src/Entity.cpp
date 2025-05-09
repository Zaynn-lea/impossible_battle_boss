
#include "config.h"
#include "Entity.h"
#include "PixelGameEngine.h"


cEntity::cEntity() {}

cEntity::cEntity(olc::vi2d spawnCoords, Hitbox hitbox, olc::Sprite * sprite, EntityType type)
{
	pos 		= spawnCoords;
	this->hitbox	= hitbox;
	this->sprite	= sprite;
	this->type	= type;
}


Hitbox *	cEntity::getHitbox()	{ return hitbox; }
int		cEntity::getHP()	{ return HP; }
olc::vi2d	cEntity::getPos()	{ return pos; }
olc::Sprite *	cEntity::getSprite()	{ return sprite; }


void cEntity::setHitbox(Hitbox * newHitbox)	 { hitbox = newHitbox; }
void cEntity::setHP(int newHP)			 { HP	  = newHP; }
void cEntity::setPos(olc::vi2d newPos)		 { pos	  = newPos; }
void cEntity::setSprite(olc::Sprite * newSprite) { sprite = newSprite;}


bool cEntity::isColiding(cEntity other)
{
	// TODO
}
