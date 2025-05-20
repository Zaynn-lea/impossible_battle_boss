#pragma once

#include "Arena.h"              // For cArena
#include "olcPixelGameEngine.h" // Base class for the game engine
#include "Player.h"             // For cPlayer
#include "Boss.h"               // For cBoss
#include "Minion.h"             // For cMinion
#include "SpriteManager.h"      // For SpriteManager
#include "Entity.h"             // For cEntity, Grid, Line typedefs

#include <vector> // For std::vector
#include <map>    // For std::map

namespace  ImpossibleBattleBoss {

  // Typedefs for the game grid (already in Entity.h, but often re-declared or used locally)
  // typedef std::vector<cEntity*> Line; // A row in the grid
  // typedef std::vector<Line>	Grid;   // The 2D game grid

  // typedef void (* func)(void); // A function pointer type, declared but not used in the provided engine code.

  /**
   * @class World
   * @brief The main game class, derived from olc::PixelGameEngine.
   *
   * This class orchestrates the game loop, manages game objects (player, boss,
   * minions, arena elements), handles user input, and renders the game state.
   */
  class World : public olc::PixelGameEngine
  {
    private:
      SpriteManager spriteManager; ///< Manages all game sprites.
      
      cBoss   boss;     ///< The main boss object.
      cPlayer player;   ///< The player character object.
      std::vector<cMinion*> minions; ///< Vector to store active minion objects.
      std::map<olc::Key,olc::HWButton> controls; ///< Map to store the state of monitored keyboard keys.

      Grid map; ///< The 2D game grid representing the level structure.
      
      /// Arena object for the main arena structure/background.
      cArena arena = cArena({0, 0}, spriteManager.getArenaSprite(), ARENA_PLATEFORM);
      /// Arena object for the ground layer, potentially animated.
      cArena ground = cArena({0, 0}, spriteManager.getGroundSprites(), ARENA_PLATEFORM);

    private:
      /**
       * @brief Initializes the player control key map.
       *
       * Populates the `controls` map with the keys that will be tracked for player input.
       */
      void makePlayerControls();

      /**
       * @brief Spawns a new minion in the game world.
       *
       * Creates a cMinion object and adds it to the `minions` vector if the current
       * number of minions is below a certain limit (e.g., 3).
       */
      void spawnMinion();

      /**
       * @brief (Debug function) Draws the hitbox of a given entity.
       *
       * Renders a rectangle around the entity's absolute hitbox, colored
       * based on the entity's type.
       * @param entity A pointer to the cEntity whose hitbox is to be drawn.
       */
      void drawHitbox(cEntity* entity);

    public:
      /**
       * @brief Constructor for the World class.
       *
       * Sets the application name for the game window.
       */
      World()
      {
        sAppName = "Impossible Boss Battle";
      }

      /**
       * @brief Generates the game map based on the `MAP` definition in `config.h`.
       *
       * Populates the `map` (Grid object) with cEntity pointers representing walls,
       * platforms, ladders, etc., or nullptr for empty spaces.
       * @param density An integer parameter (currently unused in the implementation)
       *                that might have been intended for procedural generation density.
       */
      void genMap(int density);

      /**
       * @brief Called once by olc::PixelGameEngine when the application starts.
       *
       * Used for one-time setup, like initializing game objects, loading resources,
       * and setting up the initial game state.
       * @return True if initialization is successful, false otherwise.
       */
      bool OnUserCreate() override;

      /**
       * @brief Called by olc::PixelGameEngine for every frame.
       *
       * This is the main game loop where game logic is updated, user input is
       * processed, and the game scene is rendered.
       * @param fElapsedTime Time in seconds since the last frame.
       * @return True to continue running the application, false to quit.
       */
      bool OnUserUpdate(float fElapsedTime) override;
  };
};