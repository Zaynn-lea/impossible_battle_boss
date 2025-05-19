
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
  genMap(5);

  makePlayerControls();

  player = cPlayer({128, 0}, spriteManager.getPlayerSprites());
  boss = cBoss(new olc::Sprite("../assests/Boss/bosia.png"), spriteManager.getBossSprites(), spriteManager.getBossFireHeadSprites());

  spawnMinion();

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
  player.update(controls, GetMouse(0), map, fElapsedTime);
  
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

  DrawSprite(arena.getPos(), arena.getCurrentSprite());
  DrawSprite(ground.getPos(), spriteManager.getGroundSprite());
  DrawSprite(ground.getPos(), ground.getCurrentSprite());

  DrawSprite(player.getPos(), player.getCurrentSprite());

  // Draw Boss foreground
  DrawSprite(boss.getPos(), boss.getForegroundSprite());

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

  drawHitbox(&player);

  return true;
}
