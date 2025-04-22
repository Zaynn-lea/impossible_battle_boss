#pragma once
#include "olcPixelGameEngine.h"
#include "PlayerClass.h"

namespace  ImpossibleBattleBoss {
  class World : public olc::PixelGameEngine
  {
    private:
      cPlayer player;

    public:
      World()
      {
        sAppName = "Impossible Boss Battle";
      }
      bool OnUserCreate() override;
      bool OnUserUpdate(float fElapsedTime) override;
  };
}
