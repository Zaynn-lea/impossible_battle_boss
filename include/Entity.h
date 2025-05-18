
#pragma once

#include "olcPixelGameEngine.h"


namespace ImpossibleBattleBoss
{
	struct _hitbox
	{
		olc::vi2d topLeft;
		olc::vi2d botRight;
	};
	typedef struct _hitbox * Hitbox;

	Hitbox createHitbox(int xTopLeft, int yTopLeft, int xBottomRight, int yBottomRight);


	enum EntityType
	{
		WALL,
		PLAYER,
		PLAYERATTAC,
		BOSS,
		MINION,
		OBSCTACLE
	};


	class cEntity
	{
	public:
		cEntity();
		cEntity(olc::vf2d spawnCoords, Hitbox hitbox, olc::Sprite * sprite, EntityType type);
		~cEntity();

	private:
		Hitbox 		hitbox;
		int		HP;
		olc::vf2d	pos;
		olc::Sprite *	sprite;
		EntityType	type;

	public:
		Hitbox 		getHitbox();
		int		getHP();
		olc::vf2d 	getPos();
		olc::Sprite *	getSprite();

		void setHitbox(Hitbox newHitbox);
		void setHP(int newHP);
		void setPos(olc::vf2d newPos);
		void setSprite(olc::Sprite * newSprite);

	public:
		bool isColliding(cEntity * other);
	};
	typedef std::vector<cEntity*> Line;
	typedef std::vector<Line> Grid;
};

