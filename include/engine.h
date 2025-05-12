
#pragma once

#include "olcPixelGameEngine.h"
#include "PlayerClass.h"
#include "Boss.h"
#include "Minion.h"


namespace  ImpossibleBattleBoss {
  class World : public olc::PixelGameEngine
  {
    private:
      cBoss   boss;
      cPlayer player;

      std::vector<cMinion> minions;

      std::vector<std::vector<cEntity>> * map;

    public:
      World()
      {
        sAppName = "Impossible Boss Battle";
      }

      bool OnUserCreate() override;
      bool OnUserUpdate(float fElapsedTime) override;
  };
};
