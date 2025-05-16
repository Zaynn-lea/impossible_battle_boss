
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
		cArena(olc::vi2d spawnCoords, olc::Sprite * sprite, EntityType type);
		cArena(olc::vi2d spawnCoords, std::vector<olc::Sprite *> *  sprites, EntityType type);
		~cArena();

	private:
		std::vector<olc::Sprite *> * sprites;

	public:
		olc::Sprite * getCurrentSprite();

	public:
		void update(float fElapsedTime);
	};
};
