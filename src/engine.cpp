#include "Minion.h"
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
      // if ((i == 0) || (i == ROWS-1) ||
      //     (j == 0) || (j == COLS-1))
      // {
      //   cEntity* e = new cEntity(olc::vi2d(i*XSIZE,j*YSIZE),wallhitbox,NULL,WALL);
      //   map[i].push_back(e);
      // } else
      if (rand()%100 < density) {
        cEntity* e = new cEntity(olc::vi2d(i*XSIZE,j*YSIZE),wallhitbox,NULL,OBSCTACLE);
        map[i].push_back(e);
      }
      else {
        map[i].push_back(NULL); 
      }
    }
  }
}


bool World::OnUserCreate()
{
  srand(time(NULL));
  boss	 = cBoss();
  player = cPlayer(olc::vi2d(2*XSIZE,2*YSIZE));
  genMap(10);
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

