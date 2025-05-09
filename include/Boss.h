

#pragma once


#include "Animable.h"
#include "Entity.h"
#include "olcPixelGameEngine.h"
#include "Player.h"


namespace ImpossibleBattleBoss
{
	enum BossState
	{
		IDLE,
		ATTACKING,
		HURT,
		MSPAWNING
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
		olc::Srpite getCurrentSprite();

		void update(cPlayer p, float deltaTime);
	}
};
