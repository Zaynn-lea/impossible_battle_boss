#pragma once

#include "olcPixelGameEngine.h" // For olc::Sprite
#include "Player.h"             // For PlayerState, PlayerSpriteMap
#include "Boss.h"               // For BossState, BossSpriteMap, BossSpriteVectorPair
#include "Minion.h"             // For MinionState
#include "config.h"             // For asset paths (implicitly)

#include <string>  // For std::string
#include <vector>  // For std::vector
#include <map>     // For std::map
#include <fstream> // For std::ifstream (in assertPathExists)
#include <iostream>// For std::cerr, std::cout (in assertPathExists)
#include <cstdlib> // For exit (in assertPathExists)

namespace ImpossibleBattleBoss
{
    /**
     * @class SpriteManager
     * @brief Manages the loading, storage, and unloading of all game sprites.
     *
     * This class centralizes sprite management to prevent redundant loading and
     * ensure proper cleanup of sprite resources.
     */
    class SpriteManager
    {
    private:
        /// A transparent sprite, often used as a placeholder or for specific boss animation layers.
        olc::Sprite* transparentSprite = new olc::Sprite(assertPathExists("../assests/Boss/Attacks/transpBackground.png"));
        
        /// Map storing sprites for different player states.
        PlayerSpriteMap playerSprites;
        
        /// Map storing sprite pairs (background/foreground) for different boss states.
        BossSpriteMap bossSprites;
        
        /// Vector storing sprites for the boss's fire head effect.
        std::vector<olc::Sprite *> BossFireHeadSprites;
        
        /// Map storing sprites for different minion states.
        std::map<MinionState, std::vector<olc::Sprite *>> minionSprites;
        
        /// Vector storing animated sprites for the ground.
        std::vector<olc::Sprite *> groundSprites;
        
        /// Static base sprite for the ground.
        olc::Sprite* groundSprite = new olc::Sprite(assertPathExists("../assests/ground/solseul-0.png"));
        
        /// Static sprite for the main arena structure.
        olc::Sprite* arenaSprite = new olc::Sprite(assertPathExists("../assests/arena/bosiasol-0.png"));
        
    public:
        /**
         * @brief Constructor that loads all necessary sprites.
         */
        SpriteManager();

        /**
         * @brief Destructor that unloads all loaded sprites to free memory.
         */
        ~SpriteManager();
        
        /**
         * @brief Checks if a file exists at the given path. Exits application if not found.
         * @param name The path to the file.
         * @return The path itself if the file exists.
         */
        std::string assertPathExists(const std::string &name);

        /**
         * @brief Loads all player-related sprites.
         */
        void loadPlayerSprites();

        /**
         * @brief Unloads all player-related sprites.
         */
        void unloadPlayerSprites();

        /**
         * @brief Gets a pointer to the map of player sprites.
         * @return Pointer to PlayerSpriteMap.
         */
        PlayerSpriteMap* getPlayerSprites() { return &playerSprites; }

        /**
         * @brief Loads all boss-related sprites.
         */
        void loadBossSprites();

        /**
         * @brief Unloads all boss-related sprites.
         */
        void unloadBossSprites();

        /**
         * @brief Gets the map of boss sprites (background/foreground pairs).
         * @return BossSpriteMap object.
         */
        BossSpriteMap getBossSprites() { return bossSprites; }

        /**
         * @brief Gets the vector of sprites for the boss's fire head effect.
         * @return Vector of olc::Sprite pointers.
         */
        std::vector<olc::Sprite *> getBossFireHeadSprites() { return BossFireHeadSprites; }

        /**
         * @brief Loads all minion-related sprites.
         */
        void loadMinionSprites();

        /**
         * @brief Unloads all minion-related sprites.
         */
        void unloadMinionSprites();

        /**
         * @brief Gets a pointer to the map of minion sprites.
         * @return Pointer to map of MinionState to vector of olc::Sprite pointers.
         */
        std::map<MinionState, std::vector<olc::Sprite *>>* getMinionSprites() { return &minionSprites; }

        /**
         * @brief Loads all ground-related sprites (animated sequence).
         */
        void loadGroundSprites();

        /**
         * @brief Unloads all ground-related sprites (animated sequence).
         */
        void unloadGroundSprites();

        /**
         * @brief Gets the static base sprite for the ground.
         * @return Pointer to the ground olc::Sprite.
         */
        olc::Sprite* getGroundSprite() { return groundSprite; }

        /**
         * @brief Gets a pointer to the vector of animated ground sprites.
         * @return Pointer to vector of olc::Sprite pointers.
         */
        std::vector<olc::Sprite *>* getGroundSprites() { return &groundSprites; }

        /**
         * @brief Gets the static sprite for the arena structure.
         * @return Pointer to the arena olc::Sprite.
         */
        olc::Sprite* getArenaSprite() { return arenaSprite; }
    };
}