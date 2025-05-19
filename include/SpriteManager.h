#pragma once

#include "olcPixelGameEngine.h"
#include "PlayerClass.h"
#include "Boss.h"
#include "Minion.h"

namespace ImpossibleBattleBoss
{

    class SpriteManager
    {
        olc::Sprite* transparentSprite = new olc::Sprite(assertPathExists("../assests/Boss/Attacks/transpBackground.png"));;
        PlayerSpriteMap playerSprites;
        BossSpriteMap bossSprites;
        std::vector<olc::Sprite *> BossFireHeadSprites;
        std::map<MinionState, std::vector<olc::Sprite *>> minionSprites;
        
        public:
        SpriteManager();
        ~SpriteManager();
        

        std::string assertPathExists(const std::string &name);

        void loadPlayerSprites();
        void unloadPlayerSprites();
        PlayerSpriteMap* getPlayerSprites() { return &playerSprites; }

        void loadBossSprites();
        void unloadBossSprites();
        BossSpriteMap getBossSprites() { return bossSprites; }
        std::vector<olc::Sprite *> getBossFireHeadSprites() { return BossFireHeadSprites; }

        void loadMinionSprites();
        void unloadMinionSprites();
        PlayerSpriteMap* getMinionSprites() { return &playerSprites; }
    };
}