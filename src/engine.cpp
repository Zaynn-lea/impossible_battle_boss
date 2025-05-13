
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
  controls.push_back(olc::Key::Z);
  controls.push_back(olc::Key::Q);
  controls.push_back(olc::Key::S);
  controls.push_back(olc::Key::D);
  controls.push_back(olc::Key::SPACE);

  return true;
}


bool World::OnUserUpdate(float fElapsedTime)
{
  Clear(olc::BLACK);


  player.update(controls, fElapsedTime);

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

