#include "Minion.h"
#include "Arena.h"
#include "config.h"
#include "engine.h"
#include "Entity.h"
#include "olcPixelGameEngine.h"
#include "PlayerClass.h"
#include "Boss.h"
#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace ImpossibleBattleBoss;


void World::genMap(int density){
  Hitbox wallhitbox = createHitbox(0, 0, XSIZE, YSIZE);
  for(int i = 0 ; i<ROWS; ++i){
    Line line;
    map.push_back(line);
    for (int j = 0; j<COLS; ++j){
      if (MAP[i][j] == 1){
        cEntity* e = new cEntity(olc::vf2d(j*XSIZE,i*YSIZE),wallhitbox,NULL,WALL);
        map[i].push_back(e);
      }
      else if (MAP[i][j] == 2){
        cEntity* e = new cEntity(olc::vf2d(j*XSIZE,i*YSIZE),wallhitbox,NULL,PLATFORM);
        map[i].push_back(e);
      }
      else if (MAP[i][j] == 3){
        cEntity* e = new cEntity(olc::vf2d(j*XSIZE,i*YSIZE),wallhitbox,NULL,PLATFORMARIO);
        map[i].push_back(e);
      }
      else if (MAP[i][j] == 4){
        cEntity* e = new cEntity(olc::vf2d(j*XSIZE,i*YSIZE),wallhitbox,NULL,LADDER);
        map[i].push_back(e);
      }
      else {
        map[i].push_back(NULL); 
      } 
    }
  }
}


void World::drawHitbox(cEntity* entity){
  _hitbox hitbox = entity->getAbsHB();
  olc::vf2d pos = entity->getPos();
  if (entity->getType() == PLAYER)
    DrawRect(hitbox.topLeft, hitbox.botRight - pos, olc::GREEN);
  else if (entity->getType() == PLATFORMARIO)
    DrawRect(hitbox.topLeft, hitbox.botRight - pos, olc::YELLOW);
  else if (entity->getType() == PLATFORM)
    DrawRect(hitbox.topLeft, hitbox.botRight - pos, olc::BLUE);
  else if (entity->getType() == LADDER)
    DrawRect(hitbox.topLeft, hitbox.botRight - pos, olc::CYAN);
  else if (entity->getType() == WALL)
    DrawRect(hitbox.topLeft, hitbox.botRight - pos, olc::WHITE);
  else if (entity->getType() == MINION)
    DrawRect(hitbox.topLeft, hitbox.botRight - pos, olc::MAGENTA);
  else if (entity->getType() == BOSS)
    DrawRect(hitbox.topLeft, hitbox.botRight - pos, olc::DARK_RED);
  else
  DrawRect(hitbox.topLeft, hitbox.botRight - pos, olc::RED);
}

bool World::OnUserCreate()
{

  srand(time(NULL));
  genMap(5);

  loadPlayerSprites();
  makePlayerControls();

  loadBossSprites();

  
  player = cPlayer({128, 10}, spriteManager.getPlayerSprites());
  boss	 = cBoss(new olc::Sprite("../assests/Boss/bosia.png"), spriteManager.getBossSprites(), spriteManager.getBossFireHeadSprites());

  
  makeArena();

  //makeEntityMap();

  return true;
}

bool World::OnUserUpdate(float fElapsedTime)
{
  Clear(olc::BLACK);
  std::cout << "deltaTime: " << fElapsedTime << std::endl;

  // Update everything
  //ground.update(fElapsedTime);	// TODO : problem with the sprites
  for (auto const& [key, val] : controls)
    controls[key] = GetKey(key);
  
  player.update(controls, GetMouse(0), map, fElapsedTime);

  for (int i; i < minions.size(); i++)
    minions[i].update(player, map, fElapsedTime);

  boss.update(&player, fElapsedTime);

  
  // Render and Draw everything

  SetPixelMode(olc::Pixel::ALPHA);

  // Draw Boss Background
  // DrawSprite(boss.getPos(), boss.getCurrentSprite());
  DrawSprite(boss.getPos(), boss.getCurrentSprite());
  // Draw Boss FireHead
  DrawSprite(boss.getPos(), boss.getFireHeadSprite());
  // Draw Boss Background
  DrawSprite(boss.getPos(), boss.getBackgroundSprite());

  
  DrawSprite(ground.getPos(), ground.getCurrentSprite());
  DrawSprite(plateformario2.getPos(), plateformario2.getCurrentSprite());
  DrawSprite(plateformario3.getPos(), plateformario3.getCurrentSprite());
  DrawSprite(plateformario4.getPos(), plateformario4.getCurrentSprite());
  DrawSprite(plateformario5.getPos(), plateformario5.getCurrentSprite());
  DrawSprite(plateform1.getPos(), plateform1.getCurrentSprite());
  DrawSprite(plateform2.getPos(), plateform2.getCurrentSprite());
  DrawSprite(plateform3.getPos(), plateform3.getCurrentSprite());
  DrawSprite(plateform4.getPos(), plateform4.getCurrentSprite());
  DrawSprite(ladderLeft.getPos(), ladderLeft.getCurrentSprite());
  DrawSprite(ladderRight.getPos(), ladderRight.getCurrentSprite());
  DrawSprite(player.getPos(), player.getCurrentSprite());

  
// Draw Boss foreground
  DrawSprite(boss.getPos(), boss.getForegroundSprite()); 

//  for (int i; i < minions.size(); i++)
//    DrawSprite(minions[i].getPos(), minions[i].getCurrentSprite());

  SetPixelMode(olc::Pixel::NORMAL);
  
  // Draw Hitboxes
  for (auto & line : map)
  {
    for (auto & entity : line)
    {
      if (entity != NULL)
        drawHitbox(entity);
    }
  }
  
  //drawHitbox((cEntity*)&player);

  return true;
}

