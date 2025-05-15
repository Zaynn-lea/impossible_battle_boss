

#pragma once

#include "Arena.h"
#include "olcPixelGameEngine.h"
#include "PlayerClass.h"
#include "Boss.h"
#include "Minion.h"


namespace  ImpossibleBattleBoss {
  class World : public olc::PixelGameEngine
  {
    private:
      cBoss   boss;
      std::map<BossState, std::vector<olc::Sprite *>> * bossSprites;


      cPlayer player;
      std::map<olc::Key,    olc::HWButton>		  controls;
      std::map<PlayerState, std::vector<olc::Sprite *>> playerSprites;

      std::vector<cMinion> minions;
      std::map<MinionState, std::vector<olc::Sprite *>> * minionSprites;

      cArena plateformario2, plateformario3, plateformario4, plateformario5;
      cArena plateform2, plateform3, plateform4, plateform1;

      std::vector<std::vector<cEntity>> * map;

    private:
      void makePlayerSprites();
      void makePlayerControls();

    public:
      World()
      {
        sAppName = "Impossible Boss Battle";
      }

      bool OnUserCreate() override;
      bool OnUserUpdate(float fElapsedTime) override;
  };
};
