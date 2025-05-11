
#include "engine.h"
#include "olcPixelGameEngine.h"
#include "PlayerClass.h"


using namespace ImpossibleBattleBoss;


bool World::OnUserCreate()
{
  cBoss	  boss	 = cBoss();
  cPlayer player = cPlayer();

  std::vector<cMinion> minions;

  return true;
}


bool World::OnUserUpdate(float fElapsedTime)
{
  Clear(olc::BLACK);


  player.update(olc::Key, fElapsedTime);

  for (const cMinion m : minions)
    m.update(player, , fElapsedTime);

  boss.update(player, fElapsedTime);


  DrawSprite(boss.getPos(), boss.getCurrentSprite());
  // render plateform
  DrawSprite(player.getPos(), player.getCurrentSprite());

  for (const cMinion m : minions)
    DrawSprite(m.getPos(), m.getCurrentSprite());


  return true;
}

