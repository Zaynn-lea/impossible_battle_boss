

#pragma once


#include "Animable.h"
#include "Entity.h"
#include "olcPixelGameEngine.h"
#include "PlayerClass.h"


namespace ImpossibleBattleBoss
{
	enum BossState
	{
		IDLE_BOSS,
		ATTACKING_BOSS,
		HURT_BOSS,
		MSPAWNING_BOSS
	};


	class cBoss : public cEntity, cAnimable
	{
	public:
		cBoss();
		cBoss(std::map<BossState, std::vector<olc::Sprite>> * sprites);
		~cBoss();

	private:
		BossState state;
		std::map<BossState, std::vector<olc::Sprite>> * sprites;
		int idleTime;


	public:
		olc::Sprite * getCurrentSprite();

		void update(cPlayer p, float deltaTime);
	};
};
