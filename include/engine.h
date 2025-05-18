

#pragma once

#include "Arena.h"
#include "olcPixelGameEngine.h"
#include "PlayerClass.h"
#include "Boss.h"
#include "Minion.h"


namespace  ImpossibleBattleBoss {

  typedef std::vector<cEntity*> Line;
  typedef std::vector<Line>	Grid;

  class World : public olc::PixelGameEngine
  {
    private:
      cBoss   boss;
      std::map<BossState, std::vector<olc::Sprite *>> bossSprites;


      cPlayer player;
      std::map<olc::Key,    olc::HWButton>		  controls;
      std::map<PlayerState, std::vector<olc::Sprite *>> playerSprites;

      std::vector<cMinion> minions;
      std::map<MinionState, std::vector<olc::Sprite *>> minionSprites;

      Grid map;
      cArena plateformario2, plateformario3, plateformario4, plateformario5;
      cArena plateform2, plateform3, plateform4, plateform1;
      cArena ladderLeft, ladderRight;

      std::vector<olc::Sprite *> groundSprites;
      cArena ground;


    private:
      void makePlayerSprites();
      void makePlayerControls();
      void makeGroundSprites();
      void makeArena();
      void makeEntityMap();

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
