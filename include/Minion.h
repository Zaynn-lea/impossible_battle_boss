
#pragma once


#include "Animable.h"
#include "Entity.h"
#include "olcPixelGameEngine.h"


namespace ImpossibleBattleBoss
{
	enum MinionState
	{
		ALIVE,
		DYING
	};


	class cMinion: public cEntity, cAnimable
	{
	public:
		cMinion();
		cMinion(olc::vi2d spawnPos, std::map<MinionState, std::vector<olc::Sprite>> * sprites);
		~cMinion();

	private:
		MinionState state;
		std::map<MinionState, std::vector<olc::Sprite>> * sprites;

	public:
		olc::Sprite * getCurrentSprite();

		void update(cPlayer p, std::vector<std::vecto<cEntity>> * map, float deltaTime);
	};
};
