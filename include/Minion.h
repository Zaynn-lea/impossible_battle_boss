
#pragma once
#include "Animable.h"
#include "Entity.h"
#include "PlayerClass.h"
#include "olcPixelGameEngine.h"


namespace ImpossibleBattleBoss
{
	enum MinionState
	{
		ALIVE_MINION,
		DYING_MINION
	};


	class cMinion: public cEntity, cAnimable
	{
	public:
		cMinion();
		cMinion(olc::vi2d spawnPos, std::map<MinionState, std::vector<olc::Sprite *>> * sprites);


	private:
		MinionState state;
		olc::vi2d destination = {-1,-1};
		std::map<MinionState, std::vector<olc::Sprite *>> * sprites;
		bool isRight = true;

	public:
		olc::Sprite * getCurrentSprite();
		void update(cPlayer p, Grid map, float deltaTime);
		void setState(MinionState newState);

		MinionState getState();
	};
};
