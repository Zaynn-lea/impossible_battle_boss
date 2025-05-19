#pragma once

#include "olcPixelGameEngine.h"
#include "Player.h"
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
        std::vector<olc::Sprite *> groundSprites;
        olc::Sprite* groundSprite = new olc::Sprite(assertPathExists("../assests/ground/solseul-0.png"));
        olc::Sprite* arenaSprite = new olc::Sprite(assertPathExists("../assests/arena/bosiasol-0.png"));
        
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
        std::map<MinionState, std::vector<olc::Sprite *>>* getMinionSprites() { return &minionSprites; }

        void loadGroundSprites();
        void unloadGroundSprites();
        olc::Sprite* getGroundSprite() { return groundSprite; }
        std::vector<olc::Sprite *>* getGroundSprites() { return &groundSprites; }
        olc::Sprite* getArenaSprite() { return arenaSprite; }
        
    };
}