
#include <algorithm>

#include "olcPixelGameEngine.h"

// Had to define a bunch of stuff that we'll remove when merging

typedef struct
{
	olc::vi2d topLeft;
	olc::vi2d botRight;
} * Hitbox;


class cEntity
{
private:
	olc::vi2d pos;
	Hitbox    hitbox;

public:
	cEntity();
	~cEntity();

public:
	Hitbox    getHitbox();
	olc::vi2d getPos();

public:
	bool isColliding(cEntity * other);
};


Hitbox    cEntity::getHitbox() { return hitbox; }
olc::vi2d cEntity::getPos()    { return pos; }


bool cEntity::isColliding(cEntity * other)
{
	bool vertAlign, horzAlign;

	olc::vi2d selfStart, selfEnd, compStart, compEnd;


	selfStart = this->pos + this->hitbox->topLeft;
	selfEnd   = this->pos + this->hitbox->botRight;
	compStart = other->getPos() + other->getHitbox()->topLeft;
	compEnd   = other->getPos() + other->getHitbox()->botRight;

	vertAlign = std::max(selfStart.x, compStart.x) > std::min(selfEnd.x, compEnd.x);
	vertAlign = std::max(selfStart.y, compStart.y) > std::min(selfEnd.y, compEnd.y);


	return vertAlign && horzAlign;
}
