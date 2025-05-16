

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
<<<<<<< HEAD
      std::map<BossState, std::vector<olc::Sprite *>> bossSprites;
=======
      std::map<BossState, std::vector<olc::Sprite *>> * bossSprites;
>>>>>>> 0cbec9fad37ecee9bbb7f2964443aefdf9b07c9f


      cPlayer player;
      std::map<olc::Key,    olc::HWButton>		  controls;
      std::map<PlayerState, std::vector<olc::Sprite *>> playerSprites;

      std::vector<cMinion> minions;
<<<<<<< HEAD
      std::map<MinionState, std::vector<olc::Sprite *>> minionSprites;

      cArena plateformario2, plateformario3, plateformario4, plateformario5;
      cArena plateform2, plateform3, plateform4, plateform1;
      cArena ladderLeft, ladderRight;

      std::vector<olc::Sprite *> groundSprites;
      cArena ground;
=======
      std::map<MinionState, std::vector<olc::Sprite *>> * minionSprites;

      cArena arena;
      std::vector<olc::Sprite *> arenaSprites;
>>>>>>> 0cbec9fad37ecee9bbb7f2964443aefdf9b07c9f

      std::vector<std::vector<cEntity>> * map;

    private:
      void makePlayerSprites();
      void makePlayerControls();
<<<<<<< HEAD
      void makeGroundSprites();
=======
      void makeArenaSprites();
      std::vector<Hitbox> makeArenaHitbox();

>>>>>>> 0cbec9fad37ecee9bbb7f2964443aefdf9b07c9f

    public:
      World()
      {
        sAppName = "Impossible Boss Battle";
      }

      bool OnUserCreate() override;
      bool OnUserUpdate(float fElapsedTime) override;
  };
};
