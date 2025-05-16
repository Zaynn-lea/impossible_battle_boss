
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
<<<<<<< HEAD
		cArena(olc::vi2d spawnCoords, olc::Sprite * sprite, EntityType type);
		cArena(olc::vi2d spawnCoords, std::vector<olc::Sprite *> *  sprites, EntityType type);
		~cArena();

	private:
		std::vector<olc::Sprite *> * sprites;

=======
		cArena(std::vector<Hitbox> hitboxes, std::vector<olc::Sprite *> * sprites);
		~cArena();

>>>>>>> 0cbec9fad37ecee9bbb7f2964443aefdf9b07c9f
	public:
		olc::Sprite * getCurrentSprite();

	public:
		void update(float fElapsedTime);
	};
};
