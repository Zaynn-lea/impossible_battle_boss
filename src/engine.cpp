
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

  controls[olc::Key::Z]	    = GetKey(olc::Key::Z);
  controls[olc::Key::Q]	    = GetKey(olc::Key::Q);
  controls[olc::Key::S]	    = GetKey(olc::Key::S);
  controls[olc::Key::D]	    = GetKey(olc::Key::D);
  controls[olc::Key::SPACE] = GetKey(olc::Key::SPACE);


  return true;
}


bool World::OnUserUpdate(float fElapsedTime)
{
  Clear(olc::BLACK);


  // Update everything

  for (auto const& [key, val] : controls)
    controls[key] = GetKey(key);

  player.update(controls, fElapsedTime);

  for (int i; i < minions.size(); i++)
    minions[i].update(player, map, fElapsedTime);

  boss.update(player, fElapsedTime);


  // Render and Draw everything

  DrawSprite(boss.getPos(), boss.getCurrentSprite());
  // render plateform
  DrawSprite(player.getPos(), player.getCurrentSprite());

  for (int i; i < minions.size(); i++)
    DrawSprite(minions[0].getPos(), minions[0].getCurrentSprite());


  return true;
}

