
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

      Grid map;

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
