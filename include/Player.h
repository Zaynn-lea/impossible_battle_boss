#pragma once

#include "Animable.h"       // For cAnimable base class
#include "Entity.h"         // For cEntity base class (and Grid typedef)
#include "olcPixelGameEngine.h" // For olc::vi2d, olc::vf2d, olc::Sprite, olc::Key, olc::HWButton

#include <map>    // For std::map
#include <vector> // For std::vector
#include <utility> // For std::pair

namespace ImpossibleBattleBoss
{
  /**
   * @enum PlayerState
   * @brief Defines the various states the Player character can be in.
   */
  enum PlayerState
  {
    IDLE_RIGHT_PLAYER,		///< Player is idle, facing right.
    IDLE_LEFT_PLAYER,		///< Player is idle, facing left.
    ATTACKING_RIGHT_PLAYER,	///< Player is attacking, facing right.
    ATTACKING_LEFT_PLAYER,	///< Player is attacking, facing left.
    WALKING_RIGHT_PLAYER,	///< Player is walking, facing right.
    WALKING_LEFT_PLAYER,	///< Player is walking, facing left.
    JUMPING_PLAYER,			///< Player is jumping
    HURT_PLAYER				///< Player is in a hurt/damaged state
  };

  /**
   * @typedef PlayerSpriteMap
   * @brief A map associating each PlayerState with a vector of its animation sprites.
   *        Note: The actual implementation in cPlayer uses a more complex map (see `sprites` member).
   *        This typedef is likely from an earlier design or for general reference.
   */
  typedef std::map<PlayerState, std::vector<olc::Sprite *>> PlayerSpriteMap;

  /**
   * @typedef PlayerSpriteVectorPair
   * @brief A pair consisting of a vector of animation sprites and an offset (olc::vi2d).
   *        The offset is used to align sprites of different sizes correctly.
   *        Note: This typedef is not directly used for the `sprites` member type in `cPlayer`,
   *        but `std::pair<std::vector<olc::Sprite *>, olc::vi2d>` is.
   */
  typedef std::pair<std::vector<olc::Sprite *>, olc::vi2d> PlayerSpriteVectorPair;


  /**
   * @class cPlayer
   * @brief Represents the player character in the game.
   *
   * Manages player state, movement, actions (like attacking and jumping),
   * collisions, health, and animations. Inherits from cEntity and cAnimable.
   */
  class cPlayer : public cEntity, public cAnimable
  {
    public:
      /**
       * @brief Default constructor.
       */
      cPlayer();

      /**
       * @brief Constructs a Player object.
       * @param spawnCoords The initial position of the player.
       * @param sprites A pointer to a PlayerSpriteMap (actually, a map of PlayerState to vectors of olc::Sprite*)
       *                containing animations for different player states. The IDLE_RIGHT_PLAYER sprites are used
       *                for initial hitbox and dimension calculations.
       */
      cPlayer(olc::vi2d spawnCoords, PlayerSpriteMap* sprites);

      /**
       * @brief Destructor.
       */
      ~cPlayer();

    private:
      PlayerState state;      ///< Current state of the player.
      bool isKeyPressed = false; ///< True if a movement key (Q or D) is currently held.
      bool isAttacking = false;  ///< True if the player is currently in an attack animation.
      bool isRight = true;     ///< True if the player is facing right, false if facing left.
      bool isInAir = true;     ///< True if the player is currently airborne (jumping or falling).

      float timeInAir = 0.0f;   ///< Accumulator for time spent in the current jump, used to limit jump height/duration.

      /**
       * @brief Map storing sprite animations and their offsets for each player state.
       * The olc::vi2d is an offset applied to the player's position to correctly align
       * sprites of varying dimensions, ensuring the player's logical 'feet' or center
       * remains consistent.
       */
      std::map<PlayerState, std::pair<std::vector<olc::Sprite *>, olc::vi2d>> sprites;

      // olc::vi2d velocity; // Declared but not used in the provided cPlayer.cpp

    public:
      /**
       * @brief Gets the current state of the player.
       * @return The current PlayerState.
       */
      PlayerState   getState();

      /**
       * @brief Gets the current sprite of the player based on its state and animation frame.
       * @return A pointer to the current olc::Sprite.
       */
      olc::Sprite * getCurrentSprite() override;

      /**
       * @brief Gets the player's current "visual" position, adjusted for sprite offsets.
       *
       * Overrides cEntity::getPos() to account for the sprite-specific offset,
       * ensuring the drawn sprite aligns correctly with the player's logical position.
       * @return An olc::vf2d representing the adjusted top-left position for drawing the current sprite.
       */
      olc::vf2d     getPos() override;

      /**
       * @brief Checks if the player is currently in an attacking state.
       * @return True if state is ATTACKING_RIGHT_PLAYER or ATTACKING_LEFT_PLAYER, false otherwise.
       */
      bool getAttackState();

      /**
       * @brief Sets the player's current state and resets animation.
       * @param newState The new PlayerState to transition to.
       */
      void setState(PlayerState newState); // Changed parameter name for clarity

    public:
      /**
       * @brief Updates the player's logic, including input, movement, collisions, and animation.
       * @param keys A map of olc::Key to olc::HWButton representing the state of relevant keyboard keys.
       * @param mouse The state of the primary mouse button (olc::HWButton for GetMouse(0)).
       * @param map The game grid (std::vector<std::vector<cEntity *>>) for collision detection.
       * @param deltaTime Time elapsed since the last update call.
       */
      void update(std::map<olc::Key, olc::HWButton> keys, olc::HWButton mouse, Grid map, float deltaTime);

      /**
       * @brief Converts player input (keyboard and mouse) into a movement vector.
       *
       * Also handles state changes related to input, such as switching to walking
       * or attacking states.
       * @param keys A map of olc::Key to olc::HWButton for keyboard input.
       * @param mouse The state of the primary mouse button.
       * @param deltaTime Time elapsed, used for scaling movement speed and jump force.
       * @return An olc::vi2d (actually olc::vf2d in implementation) representing the desired movement offset for this frame.
       */
      olc::vf2d	controlToMouvment(std::map<olc::Key, olc::HWButton> keys, olc::HWButton mouse, float deltaTime); // Return type was vi2d, but implementation returns vf2d. Corrected to vf2d.

      /**
       * @brief Applies collision detection and response with the game map.
       *
       * Checks for collisions with entities in the `map` (like PLATFORM, LADDER)
       * and adjusts the player's position accordingly. Also updates `isInAir`.
       * @param map The game grid.
       * @param mouvment The movement vector applied in the current frame before collision checks.
       */
      void	applyCollisions(Grid map, olc::vf2d mouvment); // Parameter type was vi2d, but passed vf2d from update. Corrected to vf2d.

      /**
       * @brief Reduces the player's HP by a specified amount.
       *
       * If HP reaches 0, the player character is "destroyed" (destructor called).
       * @param amount The amount of damage to take.
       */
      void takeDamage(int amount);
  };
};