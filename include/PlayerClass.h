
#pragma once

#include "olcPixelGameEngine.h"


namespace  ImpossibleBattleBoss {
  class cPlayer
  {
    public:
      cPlayer();
      ~cPlayer();

    private:
      olc::Sprite * idleSprite;
      olc::Sprite * jumpSprite;
      olc::vi2d     v2Coord;

      int iXmax,  iYmax;
      int iXsize, iYsize;

    public:
      bool DrawPlayer(olc::PixelGameEngine * pge);

      void updateCoord(float fElapsedTime);
  };
};
