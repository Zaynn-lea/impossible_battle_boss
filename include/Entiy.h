
#pragma once

#include "olcPixelGameEngine.h"


namespace ImpossibleBattleBoss
{
	struct Hitbox
	{
		olc::vi2d topLeft;
		olc::vi2d botRight;
	};


	enum EntityType
	{
		WALL,
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
		Hitbox *	hitbox;
		int		HP;
		olc::vi2d	pos;
		olc::Sprite *	sprite;
		EntityType	type;

	public:
		Hitbox *	getHitbox();
		int		getHP();
		olc::vi2d 	getPos();
		olc::Sprite *	getSprite();

		void setHitbox(Hitbox * newHitbox);
		void setHP(int newHP);
		void setPos(olc::vi2d newPos);
		void setSprite(olc::Sprite * newSprite);

	public:
		bool isColliding(Entity other);
	};
};

