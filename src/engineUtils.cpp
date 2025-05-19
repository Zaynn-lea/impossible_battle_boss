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

void World::makePlayerControls()
{
	controls.insert(std::pair<olc::Key, olc::HWButton>(olc::Key::Z, GetKey(olc::Key::Z)));
	controls.insert(std::pair<olc::Key, olc::HWButton>(olc::Key::Q, GetKey(olc::Key::Q)));
	controls.insert(std::pair<olc::Key, olc::HWButton>(olc::Key::S, GetKey(olc::Key::S)));
	controls.insert(std::pair<olc::Key, olc::HWButton>(olc::Key::D, GetKey(olc::Key::D)));
	controls.insert(std::pair<olc::Key, olc::HWButton>(olc::Key::SPACE, GetKey(olc::Key::SPACE)));
}

void World::spawnMinion()
{
  if (minions.size() >= 2)
    return;
  cMinion* m = new cMinion({285, 100}, spriteManager.getMinionSprites());
  //cMinion* m = new cMinion({0, 0}, spriteManager.getMinionSprites());
  minions.push_back(m);
}

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
