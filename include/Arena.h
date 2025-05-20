#pragma once

#include "Animable.h"       // For cAnimable base class
#include "Entity.h"         // For cEntity base class
#include "olcPixelGameEngine.h" // For olc::vi2d, olc::Sprite

#include <vector> // For std::vector

namespace ImpossibleBattleBoss
{
	/**
	 * @enum ArenaType
	 * @brief Defines the different types of arena elements.
	 *
	 * Used to distinguish between various interactive or static parts
	 * of the game arena, such as platforms or ladders.
	 */
	enum ArenaType
	{
		ARENA_PLATEFORM,		///< A standard platform element.
		ARENA_PLATEFORMARIO,	///< A "Mario-style" platform (potentially with different collision behavior).
		ARENA_LADDER			///< A ladder element for vertical movement.
	};

	/**
	 * @class cArena
	 * @brief Represents a static or animated part of the game arena.
	 *
	 * cArena objects are entities that make up the level's structure,
	 * like platforms or decorative elements. They can be animated.
	 * Inherits from cEntity for game world properties and cAnimable for animation.
	 */
	class cArena : public cEntity, public cAnimable // Note: cAnimable should be public for dynamic_cast or similar if needed
	{
	public:
		/**
		 * @brief Default constructor.
		 */
		cArena();

		/**
		 * @brief Constructs an arena element with a single, static sprite.
		 * @param spawnCoords The initial position (top-left) of the arena element.
		 * @param sprite A pointer to the olc::Sprite for this arena element.
		 * @param type The ArenaType of this element.
		 */
		cArena(olc::vi2d spawnCoords, olc::Sprite * sprite, ArenaType type);

		/**
		 * @brief Constructs an arena element with a sequence of sprites for animation.
		 * @param spawnCoords The initial position (top-left) of the arena element.
		 * @param sprites A pointer to a vector of olc::Sprite pointers for animation. The first sprite is used for initial hitbox creation.
		 * @param type The ArenaType of this element.
		 */
		cArena(olc::vi2d spawnCoords, std::vector<olc::Sprite *> * sprites, ArenaType type);

		/**
		 * @brief Destructor.
		 */
		~cArena();

	private:
		std::vector<olc::Sprite *> * sprites; ///< Pointer to a vector of sprites if animated, nullptr otherwise.
		ArenaType subType;                    ///< The specific type of this arena element.

	public:
		/**
		 * @brief Gets the current sprite of the arena element.
		 *
		 * If the arena element is animated (sprites vector is not NULL), it returns
		 * the current frame from the animation sequence. Otherwise, it returns the
		 * single static sprite.
		 * @return A pointer to the current olc::Sprite.
		 */
		olc::Sprite * 	getCurrentSprite() override;

		/**
		 * @brief Gets the sub-type of this arena element.
		 * @return The ArenaType of the element.
		 */
		ArenaType	getSubType();

	public:
		/**
		 * @brief Updates the animation state of the arena element.
		 *
		 * If the element is animated, this function advances the animation frame
		 * based on `fElapsedTime` and `animationSpeed`.
		 * @param fElapsedTime Time elapsed since the last update call.
		 */
		void update(float fElapsedTime);
	};
};