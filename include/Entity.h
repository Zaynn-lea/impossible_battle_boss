
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
		LADDER,
		PLATEFORM,
		PLATEFORMARIO,
		PLAYER,
		PLAYERATTAC,
		BOSS,
		MINION
	};


	class cEntity
	{
	public:
		cEntity();
		cEntity(olc::vi2d spawnCoords, Hitbox hitbox, olc::Sprite * sprite, EntityType type);
		~cEntity();

	private:
		Hitbox 		hitbox;
		int		HP;
		olc::vi2d	pos;
		olc::Sprite *	sprite;
		EntityType	type;

	public:
		Hitbox 		getHitbox();
		Hitbox 		getAbsHB();
		int		getHP();
		olc::vi2d 	getPos();
		olc::Sprite *	getSprite();

		void setHitbox(Hitbox newHitbox);
		void setHP(int newHP);
		void setPos(olc::vi2d newPos);
		void setSprite(olc::Sprite * newSprite);

	public:
		bool isColliding(cEntity * other);
	};
};

