
#pragma once


#include "Animable.h"
#include "Entity.h"
#include "olcPixelGameEngine.h"


namespace ImpossibleBattleBoss
{
	enum ArenaType
	{
		PLATEFORM,
		LADDER
	};

	class cArena : public cEntity, cAnimable
	{
	public:
		cArena();
		cArena(olc::vi2d spawnCoords, olc::Sprite * sprite, ArenaType type);
		cArena(olc::vi2d spawnCoords, std::vector<olc::Sprite *> *  sprites, ArenaType type);
		~cArena();

	private:
		std::vector<olc::Sprite *> * sprites;
		ArenaType subType;

	public:
		olc::Sprite * 	getCurrentSprite();
		ArenaType	getSubType();

	public:
		void update(float fElapsedTime);
	};
};
