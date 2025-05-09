
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
		~cMinion();

	private:
		

	public:
		olc::Sprite * getCurrentSprite();

		void update(cPlayer p, float deltaTime);
	};
};
