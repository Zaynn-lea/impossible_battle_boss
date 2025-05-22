

#include "SpriteManager.h"
#include "Player.h"
#include "Boss.h"
#include "Minion.h"
#include "config.h"
#include "olcPixelGameEngine.h"

namespace ImpossibleBattleBoss
{

    std::string SpriteManager::assertPathExists(const std::string &name)
    {
        std::ifstream file(name);
        if (!file.good())
        {
            std::cerr << "Error: File not found: " << name << std::endl;
            exit(1);
        }
        file.close();
        std::cout << "File found: " << name << std::endl;
        return name;
    }

    SpriteManager::SpriteManager()
    {
        // Load player sprites
        loadPlayerSprites();

        // Load boss sprites
        loadBossSprites();

        // Load minion sprites
        loadMinionSprites();

        // Load ground sprites
        loadGroundSprites();

    }

    SpriteManager::~SpriteManager()
    {
        // Unload player sprites
        unloadPlayerSprites();

        // Unload boss sprites
        unloadBossSprites();

        // Unload minion sprites
        unloadMinionSprites();

        // Unload ground sprites
        unloadGroundSprites();

        // Unload transparent sprite
        delete transparentSprite;
        transparentSprite = nullptr;
        delete groundSprite;
        groundSprite = nullptr;
        delete arenaSprite;
        arenaSprite = nullptr;
    }

    void SpriteManager::loadPlayerSprites()
    {
        playerSprites.insert(std::pair<PlayerState, std::vector<olc::Sprite *>>(IDLE_RIGHT_PLAYER, std::vector<olc::Sprite *>()));
        playerSprites.insert(std::pair<PlayerState, std::vector<olc::Sprite *>>(IDLE_LEFT_PLAYER, std::vector<olc::Sprite *>()));

        for (int i = 0; i < 5; ++i)
        {
            playerSprites[IDLE_RIGHT_PLAYER].push_back(new olc::Sprite(assertPathExists("../assets/idle_player/idle_right-" + std::to_string(i) + ".png")));
            playerSprites[IDLE_LEFT_PLAYER].push_back(new olc::Sprite(assertPathExists("../assets/idle_player/idle_left-" + std::to_string(i) + ".png")));
        }
        playerSprites.insert(std::pair<PlayerState, std::vector<olc::Sprite *>>(WALKING_LEFT_PLAYER, std::vector<olc::Sprite *>()));
        playerSprites.insert(std::pair<PlayerState, std::vector<olc::Sprite *>>(WALKING_RIGHT_PLAYER, std::vector<olc::Sprite *>()));
        for (int i = 0; i < 8; ++i)
        {
            playerSprites[WALKING_RIGHT_PLAYER].push_back(new olc::Sprite(assertPathExists("../assets/walk_player/marche_right-" + std::to_string(i) + ".png")));
            playerSprites[WALKING_LEFT_PLAYER].push_back(new olc::Sprite(assertPathExists("../assets/walk_player/marche_left-" + std::to_string(i) + ".png")));
        }

        playerSprites.insert(std::pair<PlayerState, std::vector<olc::Sprite *>>(ATTACKING_RIGHT_PLAYER, std::vector<olc::Sprite *>()));
        playerSprites.insert(std::pair<PlayerState, std::vector<olc::Sprite *>>(ATTACKING_LEFT_PLAYER, std::vector<olc::Sprite *>()));
        for (int i = 0; i < 9; ++i)
        {
            playerSprites[ATTACKING_RIGHT_PLAYER].push_back(new olc::Sprite(assertPathExists("../assets/attack/proj_IA_attaque_right-" + std::to_string(i) + ".png")));
            playerSprites[ATTACKING_LEFT_PLAYER].push_back(new olc::Sprite(assertPathExists("../assets/attack/proj_IA_attaque_left-" + std::to_string(i) + ".png")));
        }
    }

    void SpriteManager::unloadPlayerSprites()
    {
        for (auto &pair : playerSprites)
        {
            for (auto sprite : pair.second)
            {
                delete sprite;
            }
        }
        playerSprites.clear();
    }

    void SpriteManager::loadBossSprites()
    {
        std::cout << "Loading boss sprites..." << std::endl;
	
        std::vector<BossSpriteVectorPair> tempSprites;
        tempSprites.resize(8);

        for (int i = 0; i < 13; i++){
            //0
            tempSprites[0].first.push_back(new olc::Sprite(assertPathExists("../assets/Boss/Attacks/0/background/background-" + std::to_string(i) + ".png")));
            tempSprites[0].second.push_back(new olc::Sprite(assertPathExists("../assets/Boss/Attacks/0/foreground/foreground-" + std::to_string(i) + ".png")));
            //1
            tempSprites[1].first.push_back(new olc::Sprite(assertPathExists("../assets/Boss/Attacks/1/background/background-" + std::to_string(i) + ".png")));
            tempSprites[1].second.push_back(new	olc::Sprite(assertPathExists("../assets/Boss/Attacks/1/foreground/foreground-" + std::to_string(i) + ".png")));
            //2
            tempSprites[2].first.push_back(new olc::Sprite(assertPathExists("../assets/Boss/Attacks/2/background/background-" + std::to_string(i) + ".png")));
            tempSprites[2].second.push_back(new olc::Sprite(assertPathExists("../assets/Boss/Attacks/2/foreground/foreground-" + std::to_string(i) + ".png")));
            //3
            tempSprites[3].first.push_back(new olc::Sprite(assertPathExists("../assets/Boss/Attacks/3/background/background-" + std::to_string(i) + ".png")));
            tempSprites[3].second.push_back(new olc::Sprite(assertPathExists("../assets/Boss/Attacks/3/foreground/foreground-" + std::to_string(i) + ".png")));
            //4
            tempSprites[4].first.push_back(new olc::Sprite(assertPathExists("../assets/Boss/Attacks/4/background/background-" + std::to_string(i) + ".png")));
            tempSprites[4].second.push_back(new olc::Sprite(assertPathExists("../assets/Boss/Attacks/4/foreground/foreground-" + std::to_string(i) + ".png")));

            //5
            tempSprites[5].first.push_back(new olc::Sprite(assertPathExists("../assets/Boss/Attacks/5/background/background-" + std::to_string(i) + ".png")));
            tempSprites[5].second.push_back(new olc::Sprite(assertPathExists("../assets/Boss/Attacks/5/foreground/foreground-" + std::to_string(i) + ".png")));
        }
        //6
        tempSprites[6].first.push_back(new olc::Sprite(assertPathExists("../assets/Boss/idle.png")));
        tempSprites[6].second.push_back(transparentSprite);

        //7
        for (int i = 0; i < 6; i++)
        {
            tempSprites[7].first.push_back(new olc::Sprite(assertPathExists("../assets/Boss/Attacks/MSPAWN/background-" + std::to_string(i) + ".png")));
            tempSprites[7].second.push_back(transparentSprite);
        }

    
        
        bossSprites.insert(std::pair<BossState, BossSpriteVectorPair>(ATTACKING0_BOSS, tempSprites[0]));
        bossSprites.insert(std::pair<BossState, BossSpriteVectorPair>(ATTACKING1_BOSS, tempSprites[1]));
        bossSprites.insert(std::pair<BossState, BossSpriteVectorPair>(ATTACKING2_BOSS, tempSprites[2]));
        bossSprites.insert(std::pair<BossState, BossSpriteVectorPair>(ATTACKING3_BOSS, tempSprites[3]));
        bossSprites.insert(std::pair<BossState, BossSpriteVectorPair>(ATTACKING4_BOSS, tempSprites[4]));
        bossSprites.insert(std::pair<BossState, BossSpriteVectorPair>(ATTACKING5_BOSS, tempSprites[5]));

        bossSprites.insert(std::pair<BossState, BossSpriteVectorPair>(IDLE_BOSS, tempSprites[6]));
        bossSprites.insert(std::pair<BossState, BossSpriteVectorPair>(MSPAWNING_BOSS, tempSprites[7]));


        for (int i = 0; i < 6; i++)
        {
            BossFireHeadSprites.push_back(new olc::Sprite("../assets/Boss/fireHead/fireHead-" + std::to_string(i) + ".png"));
        }
        std::cout << "Boss sprites loaded." << std::endl;
    }
    
    void SpriteManager::unloadBossSprites() {
        std::cout << "Unloading boss sprites..." << std::endl;
        for (auto &pair : bossSprites) {
            for (olc::Sprite* sprite_ptr : pair.second.first) {
                if (sprite_ptr != nullptr && sprite_ptr != transparentSprite) {
                    delete sprite_ptr;
                }
            }
            pair.second.first.clear();
    
            for (olc::Sprite* sprite_ptr : pair.second.second) {
                if (sprite_ptr != nullptr && sprite_ptr != transparentSprite) {
                    delete sprite_ptr;
                }
            }
            pair.second.second.clear();
        }
        bossSprites.clear();
        for (auto sprite : BossFireHeadSprites) {
            delete sprite;
        }
        BossFireHeadSprites.clear();
        std::cout << "Boss sprites unloaded." << std::endl;
    }

    void SpriteManager::loadMinionSprites()
    {
        std::vector<olc::Sprite *> tempSprites;
        for (int i = 0; i < 4; i++)
        {
            tempSprites.push_back(new olc::Sprite(assertPathExists("../assets/minion/bouledefeu-" + std::to_string(i) + ".png")));
        }
        minionSprites.insert(std::pair<MinionState, std::vector<olc::Sprite *>>(ALIVE_MINION, tempSprites));
        tempSprites.clear();
    //	tempSprites.push_back(new olc::Sprite("../assets/minion/-0.png"));    // TODO
        minionSprites.insert(std::pair<MinionState, std::vector<olc::Sprite *>>(DYING_MINION, tempSprites));
    }

    void SpriteManager::unloadMinionSprites()
    {
        for (auto &pair : minionSprites)
        {
            for (auto sprite : pair.second)
            {
                delete sprite;
            }
        }
        minionSprites.clear();
    }

    void SpriteManager::loadGroundSprites()
    {
        for (int i = 1; i < 4; ++i)
        {
            groundSprites.push_back(new olc::Sprite(assertPathExists("../assets/ground/solseul-" + std::to_string(i) + ".png")));
        }
    }

    void SpriteManager::unloadGroundSprites()
    {
        for (auto sprite : groundSprites)
        {
            delete sprite;
        }
        groundSprites.clear();
    }
}
