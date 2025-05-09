
#include "engine.h"
#include "olcPixelGameEngine.h"
#include "PlayerClass.h"


using namespace ImpossibleBattleBoss;


bool World::OnUserCreate()
{
  player = cPlayer(this);

  return true;
}


bool World::OnUserUpdate(float fElapsedTime)
{
  Clear(olc::BLACK);

  player.DrawPlayer();

  player.updateCoord(fElapsedTime);

  return true;
}

