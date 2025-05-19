#include "Minion.h"
#include "Arena.h"
#include "config.h"
#include "engine.h"
#include "Entity.h"
#include "olcPixelGameEngine.h"
#include "Player.h"
#include "Boss.h"
#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace ImpossibleBattleBoss;

bool World::OnUserCreate()
{
  srand(time(NULL));
  genMap(25);

  makePlayerControls();

  player = cPlayer({130, 170}, spriteManager.getPlayerSprites());
  boss = cBoss(new olc::Sprite("../assests/Boss/bosia.png"), spriteManager.getBossSprites(), spriteManager.getBossFireHeadSprites());
  return true;
}

bool World::OnUserUpdate(float fElapsedTime)
{
  Clear(olc::BLACK);

  // Update everything

  for (auto const &[key, val] : controls)
  controls[key] = GetKey(key);
  
  //
  // Player Logic
  //
  //player.update(controls, GetMouse(0), map, fElapsedTime);
  
  //
  // Minion Logic
  //
  // use iterator to avoid invalidating the vector while deleting
  std::vector<cMinion *>::iterator it = minions.begin();
  while (it != minions.end())
  {
    if ((*it)->getHP() <= 0)
    {
      delete *it;
      it = minions.erase(it);
    }
    else
    {
      (*it)->update(&player, map, fElapsedTime);
      ++it;
    }
  }
  
  //
  // Boss Logic
  //

  boss.update(&player, fElapsedTime);
  if (boss.getTriggerMinions() == true)
  {
    spawnMinion();
    boss.setTriggerMinions(false);
  }

  // Ground Animation
  ground.update(fElapsedTime);
  
  //////////////////////////////////
  //                              //
  //  Render and Draw everything  //
  //                              //
  //////////////////////////////////
  
  SetPixelMode(olc::Pixel::ALPHA);
  
  // Draw Boss
  DrawSprite(boss.getPos(), boss.getCurrentSprite());
  DrawSprite(boss.getPos(), boss.getFireHeadSprite());
  DrawSprite(boss.getPos(), boss.getBackgroundSprite());

  // Draw Arena
  DrawSprite(arena.getPos(), arena.getCurrentSprite());
  DrawSprite(ground.getPos(), ground.getCurrentSprite());

  // Draw Player
  DrawSprite(player.getPos(), player.getCurrentSprite());

  // Draw Boss foreground
  DrawSprite(boss.getPos(), boss.getForegroundSprite());

  // Draw Minions
  for (int i = 0; i < minions.size(); i++)
  {
    DrawSprite(minions[i]->getPos(), minions[i]->getCurrentSprite());
  }

  SetPixelMode(olc::Pixel::NORMAL);

  // Draw Hitboxes
  for (auto &line : map)
  {
    for (auto &entity : line)
    {
      if (entity != NULL)
        drawHitbox(entity);
    }
  }
  for (int i = 0; i < minions.size(); i++)
  {
    drawHitbox(minions[i]);
  }

  drawHitbox(&player);

  return true;
}
