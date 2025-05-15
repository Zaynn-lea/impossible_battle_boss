
#pragma once


#include "Animable.h"
#include "Entity.h"
#include "olcPixelGameEngine.h"


namespace ImpossibleBattleBoss
{
	class cArena : public cEntity
	{
	public:
		cArena();
		cArena(olc::vi2d spawnCoords, olc::Sprite * sprite, EntityType type);
		~cArena();

	public:
		olc::Sprite * getCurrentSprite();

	public:
		void update(float fElapsedTime);
	};
};
