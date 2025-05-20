#pragma once

#include "Animable.h"       // For cAnimable base class
#include "Entity.h"         // For cEntity base class
#include "olcPixelGameEngine.h" // For olc::vi2d, olc::Sprite, etc.
#include "Player.h"         // For cPlayer, used in update and targeting

#include <map>    // For std::map
#include <vector> // For std::vector
#include <utility> // For std::pair

namespace ImpossibleBattleBoss
{
	// Forward declaration of cPlayer if Player.h is too heavy or creates circular dependency.
	// class cPlayer; // Already included Player.h

	/**
	 * @enum BossState
	 * @brief Defines the various states the Boss can be in.
	 */
	enum BossState
	{
		IDLE_BOSS,			///< Boss is idle.
		ATTACKING0_BOSS,	///< Boss is performing attack type 0.
		ATTACKING1_BOSS,	///< Boss is performing attack type 1.
		ATTACKING2_BOSS,	///< Boss is performing attack type 2.
		ATTACKING3_BOSS,	///< Boss is performing attack type 3.
		ATTACKING4_BOSS,	///< Boss is performing attack type 4.
		ATTACKING5_BOSS,	///< Boss is performing attack type 5.
		HURT_BOSS,			///< Boss is in a hurt/damaged state
		MSPAWNING_BOSS		///< Boss is in the state of spawning minions.
	};

	/**
	 * @typedef BossSpriteVectorPair
	 * @brief A pair of sprite vectors, typically for background and foreground layers of a boss animation.
	 * The first vector is for background sprites, the second for foreground sprites.
	 */
	typedef std::pair<std::vector<olc::Sprite *>, std::vector<olc::Sprite *>> BossSpriteVectorPair;

	/**
	 * @typedef BossSpriteMap
	 * @brief A map associating each BossState with its corresponding BossSpriteVectorPair (animation frames).
	 */
	typedef std::map<BossState, BossSpriteVectorPair> BossSpriteMap;

	/**
	 * @class cBoss
	 * @brief Represents the main antagonist, the Boss, in the game.
	 *
	 * The cBoss class manages its own state, animations, attacks, and interactions
	 * with the player. It inherits from cEntity and cAnimable.
	 */
	class cBoss : public cEntity, public cAnimable
	{
	public:
		/**
		 * @brief Default constructor.
		 */
		cBoss();

		/**
		 * @brief Constructs a Boss object.
		 * @param defaultSprite The default sprite for the boss (used as a base, potentially for idle or if other sprites are missing).
		 * @param sprites A map containing sprite animations for different boss states.
		 * @param fireHeadSprites A vector of sprites for the "fire head" visual effect.
		 */
		cBoss(olc::Sprite* defaultSprite, BossSpriteMap sprites, std::vector<olc::Sprite *> fireHeadSprites);

		/**
		 * @brief Destructor.
		 */
		~cBoss();

	private:
		BossState state; ///< Current state of the boss.
		// Pair.first = back, second = front
		BossSpriteMap sprites; ///< Map storing animation frames for each state (background and foreground layers).
		std::vector<olc::Sprite *> fireHeadSprites; ///< Sprites for the fire head effect.
		
		float idleTime = 0;     ///< Timer for how long the boss has been in the IDLE_BOSS state.
		int attackSpot = 0;     ///< Target spot for certain attacks, determined by player position.
		int fireHeadCounter = 0;///< Animation counter for the fire head sprites.
		
		/**
		 * @brief Sets the boss's current state and resets animation counters.
		 * @param newState The new BossState to transition to.
		 */
		void setState(BossState newState);

		/**
		 * @brief Sets the boss to an attacking state corresponding to the given attack spot.
		 * @param attackSpot An integer identifier for the attack spot (0-5).
		 */
		void setAttackSpot(int attackSpot);

		bool triggerMinions = false; ///< Flag to indicate whether minions should be spawned.

		olc::Sprite* backgroundSprite = nullptr; ///< Pointer to the current background sprite layer of the boss.
		olc::Sprite* foregroundSprite = nullptr; ///< Pointer to the current foreground sprite layer of the boss.

		/**
		 * @brief Determines a grid-based ID representing the player's current zone.
		 *
		 * Divides the playable area into a 3x2 grid and returns an ID (0-5)
		 * based on the player's x and y coordinates. Used for targeting attacks.
		 * @param player A pointer to the cPlayer object.
		 * @return An integer ID (0-5) for the player's grid position.
		 */
		int getGridPositionId(cPlayer* player);


	public:
		/**
		 * @brief Gets the current "main" sprite of the boss.
		 *
		 * This method also updates `backgroundSprite` and `foregroundSprite` based on the current state and animation frame.
		 * The return value is `getSprite()`, which is the `defaultSprite` passed in constructor.
		 * Actual visual representation relies on drawing background, foreground, and fire head sprites separately.
		 * @return A pointer to the boss's default olc::Sprite.
		 */
		olc::Sprite* getCurrentSprite() override;

		/**
		 * @brief Gets the current sprite for the fire head animation.
		 * @return A pointer to the current fire head olc::Sprite.
		 */
		olc::Sprite* getFireHeadSprite();

		/**
		 * @brief Gets the current background layer sprite of the boss.
		 * @return A pointer to the background olc::Sprite.
		 */
		olc::Sprite* getBackgroundSprite() { return backgroundSprite; }

		/**
		 * @brief Gets the current foreground layer sprite of the boss.
		 * @return A pointer to the foreground olc::Sprite.
		 */
		olc::Sprite* getForegroundSprite() { return foregroundSprite; }

		/**
		 * @brief Sets the flag to trigger minion spawning.
		 * @param trigger True to trigger minion spawning, false otherwise.
		 */
		void setTriggerMinions(bool trigger) { triggerMinions = trigger; }

		/**
		 * @brief Checks if minion spawning is currently triggered.
		 * @return True if minions should be spawned, false otherwise.
		 */
		bool getTriggerMinions() { return triggerMinions; }

		/**
		 * @brief Updates the boss's logic, state, and animations.
		 *
		 * Handles state transitions (e.g., from IDLE to ATTACKING or MSPAWNING),
		 * progresses animations, and updates timers.
		 * @param p A pointer to the cPlayer object for targeting and interaction.
		 * @param deltaTime Time elapsed since the last update call.
		 */
		void update(cPlayer* p, float deltaTime);
	};
};