
#pragma once


#include "Animable.h"
#include "Entity.h"
#include "olcPixelGameEngine.h"


namespace ImpossibleBattleBoss
{
	class cArena : public cEntity, cAnimable
	{
	public:
		cArena();
		cArena(std::vector<Hitbox> hitboxes, std::vector<olc::Sprite *> * sprites);
		~cArena();

	public:
		olc::Sprite * getCurrentSprite();

	public:
		void update(float fElapsedTime);
	};
};
