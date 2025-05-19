#pragma once

#include "Animable.h"
#include "Entity.h"
#include "olcPixelGameEngine.h"
#include "Player.h"


namespace ImpossibleBattleBoss
{
	enum BossState
	{
		IDLE_BOSS,
		ATTACKING0_BOSS,
		ATTACKING1_BOSS,
		ATTACKING2_BOSS,
		ATTACKING3_BOSS,
		ATTACKING4_BOSS,
		ATTACKING5_BOSS,
		HURT_BOSS,
		MSPAWNING_BOSS
	};

	typedef std::pair<std::vector<olc::Sprite *> , std::vector<olc::Sprite *>> BossSpriteVectorPair;
	typedef std::map<BossState, BossSpriteVectorPair> BossSpriteMap;

	class cBoss : public cEntity, cAnimable
	{
	public:
		cBoss();
		cBoss(olc::Sprite* defaultSprite, std::map<BossState, BossSpriteVectorPair> sprites, std::vector<olc::Sprite *> fireHeadSprites);
		~cBoss();

	private:
		BossState state;
		// Pair.first = back, second = front
		BossSpriteMap sprites;
		std::vector<olc::Sprite *> fireHeadSprites;
		float idleTime = 0;
		int attackSpot = 0;
		int fireHeadCounter = 0;
		void setState(BossState newState);
		void setAttackSpot(int attackSpot);
		bool triggerMinions = false;
		
		olc::Sprite* backgroundSprite; 
		olc::Sprite* foregroundSprite;
		int getGridPositionId(cPlayer* player);


	public:
		olc::Sprite* getCurrentSprite();
		olc::Sprite* getFireHeadSprite();
		olc::Sprite* getBackgroundSprite() { return backgroundSprite; }
		olc::Sprite* getForegroundSprite() { return foregroundSprite; }
		void setTriggerMinions(bool trigger) { triggerMinions = trigger; }
		bool getTriggerMinions() { return triggerMinions; }

		void update(cPlayer* p, float deltaTime);
	};
};
