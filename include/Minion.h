#pragma once

#include "Animable.h"       // For cAnimable base class
#include "Entity.h"         // For cEntity base class
#include "Player.h"         // For cPlayer, used for targeting
#include "olcPixelGameEngine.h" // For olc::vi2d, olc::Sprite, etc.
#include "pathfind.h"       // For pathfinding structures/functions (implicitly, by using Grid type)

#include <map>    // For std::map
#include <vector> // For std::vector

namespace ImpossibleBattleBoss
{
	// Forward declaration for cPlayer, if not fully needed. Player.h is included.
	// class cPlayer;

	/**
	 * @enum MinionState
	 * @brief Defines the states a Minion can be in.
	 */
	enum MinionState
	{
		ALIVE_MINION,	///< Minion is alive and active.
		DYING_MINION	///< Minion is in the process of dying (animation, etc.). (Currently, dying animation sprites might be missing)
	};

	/**
	 * @typedef MinionSpriteMap
	 * @brief A map associating each MinionState with its corresponding vector of animation sprites.
	 */
	typedef std::map<MinionState, std::vector<olc::Sprite *>> MinionSpriteMap;

	/**
	 * @class cMinion
	 * @brief Represents a smaller enemy, typically spawned by the Boss.
	 *
	 * Minions use pathfinding to move towards the player and can deal damage
	 * upon collision. They inherit from cEntity and cAnimable.
	 */
	class cMinion: public cEntity, public cAnimable
	{
	public:
		/**
		 * @brief Default constructor.
		 */
		cMinion();

		/**
		 * @brief Constructs a Minion object.
		 * @param spawnPos The initial position of the minion.
		 * @param sprites A pointer to a MinionSpriteMap containing animations for different states.
		 *                The first sprite of ALIVE_MINION is used for initial hitbox creation.
		 */
		cMinion(olc::vi2d spawnPos, MinionSpriteMap* sprites);

		// No explicit destructor ~cMinion(); but one is called in cMinion::update upon collision.

	private:
		MinionState state; ///< Current state of the minion.
		olc::vi2d destination = {-1,-1}; ///< Target grid cell for pathfinding. (-1,-1) indicates no current destination or needs recalculation.
		MinionSpriteMap* sprites; ///< Pointer to the map of sprites for animation.
		// bool isRight = true; // This member is declared but not used in the provided cMinion.cpp code.

	public:
		/**
		 * @brief Gets the current sprite of the minion based on its state and animation frame.
		 * @return A pointer to the current olc::Sprite.
		 */
		olc::Sprite * getCurrentSprite() override;

		/**
		 * @brief Updates the minion's logic, including pathfinding, movement, and interaction.
		 *
		 * Handles animation, pathfinding towards the player, movement,
		 * collision detection with the player (damaging player and self-destructing),
		 * and health checks.
		 * @param p A pointer to the cPlayer object for targeting.
		 * @param map The game grid (Grid object) used for pathfinding.
		 * @param deltaTime Time elapsed since the last update call.
		 */
		void update(cPlayer* p, Grid map, float deltaTime);

		/**
		 * @brief Sets the minion's current state and resets animation.
		 * @param newState The new MinionState to transition to.
		 */
		void setState(MinionState newState);

		/**
		 * @brief Gets the current state of the minion.
		 * @return The current MinionState.
		 */
		MinionState getState();
	};
};