

#pragma once

#include "Arena.h"
#include "olcPixelGameEngine.h"
#include "Player.h"
#include "Boss.h"
#include "Minion.h"
#include "SpriteManager.h"

namespace  ImpossibleBattleBoss {

  typedef std::vector<cEntity*> Line;
  typedef std::vector<Line>	Grid;
  typedef void (* func)(void);

  class World : public olc::PixelGameEngine
  {
    private:
      SpriteManager spriteManager;
      
      cBoss   boss;
      cPlayer player;
      std::vector<cMinion*> minions;
      std::map<olc::Key,olc::HWButton> controls;


      Grid map;
      cArena arena = cArena({0, 0}, spriteManager.getArenaSprite(), ARENA_PLATEFORM);
      cArena ground = cArena({0, 0}, spriteManager.getGroundSprites(), ARENA_PLATEFORM);


    private:
      void makePlayerControls();
      void spawnMinion();
      void drawHitbox(cEntity* entity);

    public:
      World()
      {
        sAppName = "Impossible Boss Battle";
      }
      void genMap(int density);
      bool OnUserCreate() override;
      bool OnUserUpdate(float fElapsedTime) override;
  };
};
