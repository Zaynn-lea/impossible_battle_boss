
#include "engine.h"
#include "olcPixelGameEngine.h"
#include "PlayerClass.h"
#include "Boss.h"
#include "Minion.h"


using namespace ImpossibleBattleBoss;


bool World::OnUserCreate()
{
  boss	 = cBoss();
  player = cPlayer();

  return true;
}


bool World::OnUserUpdate(float fElapsedTime)
{
  Clear(olc::BLACK);


  player.update(GetKey(olc::Key::A), fElapsedTime);

  for (int i; i < minions.size(); i++)
    minions[i].update(player, map, fElapsedTime);

  boss.update(player, fElapsedTime);


  DrawSprite(boss.getPos(), boss.getCurrentSprite());
  // render plateform
  DrawSprite(player.getPos(), player.getCurrentSprite());

  for (int i; i < minions.size(); i++)
    DrawSprite(minions[0].getPos(), minions[0].getCurrentSprite());


  return true;
}

