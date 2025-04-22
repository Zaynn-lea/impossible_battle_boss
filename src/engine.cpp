#include "engine.h"
#include "olcPixelGameEngine.h"
#include "PlayerClass.h"

using namespace ImpossibleBattleBoss;

bool World::OnUserCreate()
{
  player = cPlayer();
  return true;
}

bool World::OnUserUpdate(float fElapsedTime)
{
  Clear(olc::BLACK);
  player.DrawPlayer(this);
	player.updateCoord(fElapsedTime);
  return true;
}

