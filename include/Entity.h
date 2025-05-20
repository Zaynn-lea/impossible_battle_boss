#pragma once

#include "olcPixelGameEngine.h" // For olc::vf2d, olc::vi2d, olc::Sprite
#include <vector>               // For std::vector (used in Grid typedef)

namespace ImpossibleBattleBoss
{
	/**
	 * @struct _hitbox
	 * @brief Defines a rectangular hitbox with top-left and bottom-right points.
	 *
	 * These coordinates are typically relative to the entity's position.
	 */
	struct _hitbox
	{
		olc::vi2d topLeft;    ///< Top-left corner of the hitbox.
		olc::vi2d botRight;   ///< Bottom-right corner of the hitbox.
	};
	/**
	 * @typedef Hitbox
	 * @brief Alias for the _hitbox struct.
	 */
	typedef struct _hitbox Hitbox;

	/**
	 * @brief Utility function to create a Hitbox.
	 * @param xTopLeft X-coordinate of the top-left corner.
	 * @param yTopLeft Y-coordinate of the top-left corner.
	 * @param xBottomRight X-coordinate of the bottom-right corner (or width if xTopLeft is 0).
	 * @param yBottomRight Y-coordinate of the bottom-right corner (or height if yTopLeft is 0).
	 * @return A Hitbox object initialized with the given coordinates.
	 * @note In cArena, this is used as (x, y, width, height). In cEntity constructor, it is (x, y, x_relative_end, y_relative_end).
	 *       The usage seems to be (topLeft.x, topLeft.y, width, height) in practice for defining the hitbox relative to sprite origin.
	 *       And then createHitbox(0,0,width,height) for hitbox relative to entity pos.
	 */
	Hitbox createHitbox(int xTopLeft, int yTopLeft, int xBottomRight, int yBottomRight);

	/**
	 * @enum EntityType
	 * @brief Defines the different types of entities in the game.
	 */
	enum EntityType
	{
		WALL,			///< An impassable wall or boundary.
		PLAYER,			///< The player character.
		PLAYERATTAC,	///< A player's attack projectile or effect (currently unused).
		BOSS,			///< The main boss enemy.
		MINION,			///< A smaller enemy spawned by the boss.
		OBSCTACLE,		///< A generic obstacle (currently unused).
		PLATFORM,		///< A solid platform the player can stand on.
		LADDER,			///< A ladder the player can climb.
		PLATFORMARIO,	///< A "Mario-style" platform, potentially pass-through from below.
	};

	/**
	 * @class cEntity
	 * @brief Base class for all game objects (entities).
	 *
	 * Provides common properties like position, hitbox, health points (HP),
	 * sprite, and type. Also includes collision detection logic.
	 */
	class cEntity
	{
	public:
		/**
		 * @brief Default constructor.
		 */
		cEntity();

		/**
		 * @brief Constructs an entity with specified properties.
		 * @param spawnCoords Initial position of the entity.
		 * @param hitbox Hitbox for collision detection, relative to the entity's position.
		 * @param sprite Default sprite for the entity.
		 * @param type The EntityType of this entity.
		 */
		cEntity(olc::vf2d spawnCoords, Hitbox hitbox, olc::Sprite * sprite, EntityType type);

		/**
		 * @brief Virtual destructor.
		 */
		virtual ~cEntity();

	private:
		Hitbox 		hitbox; ///< Relative hitbox of the entity.
		int			HP = 1;     ///< Health points of the entity. Defaulted to 1 for basic entities.
		olc::vf2d	pos;    ///< Current position (top-left) of the entity in the game world.
		olc::Sprite * sprite = nullptr; ///< Default visual representation of the entity.
		EntityType	type;   ///< Type of the entity.

	public:
		/**
		 * @brief Gets the entity's relative hitbox.
		 * @return The Hitbox object.
		 */
		Hitbox 		getHitbox();

		/**
		 * @brief Gets the entity's absolute hitbox in world coordinates.
		 * @return An _hitbox object with top-left and bottom-right corners in world space.
		 */
		_hitbox 	getAbsHB();

		/**
		 * @brief Gets the entity's current health points.
		 * @return Current HP.
		 */
		int			getHP();

		/**
		 * @brief Gets the entity's current position.
		 * @return An olc::vf2d representing the position (usually top-left).
		 */
		virtual olc::vf2d 	getPos(); // Made virtual to allow Player to override for sprite offsets

		/**
		 * @brief Gets the entity's default sprite.
		 * @return A pointer to the olc::Sprite.
		 */
		olc::Sprite *	getSprite();

		/**
		 * @brief Gets the entity's type.
		 * @return The EntityType.
		 */
		EntityType		getType();

		/**
		 * @brief Sets the entity's relative hitbox.
		 * @param newHitbox The new Hitbox.
		 */
		void setHitbox(Hitbox newHitbox);

		/**
		 * @brief Sets the entity's health points.
		 * @param newHP The new HP value.
		 */
		void setHP(int newHP);

		/**
		 * @brief Sets the entity's position.
		 * @param newPos The new olc::vf2d position.
		 */
		void setPos(olc::vf2d newPos);

		/**
		 * @brief Sets the entity's default sprite.
		 * @param newSprite A pointer to the new olc::Sprite.
		 */
		void setSprite(olc::Sprite * newSprite);

	public:
		/**
		 * @brief Checks if this entity is colliding with another entity.
		 *
		 * Uses AABB (Axis-Aligned Bounding Box) collision detection based on
		 * their absolute hitboxes.
		 * @param other A pointer to the other cEntity to check collision against.
		 * @return True if a collision is detected, false otherwise. Returns false if `other` is NULL.
		 */
		bool isColliding(cEntity * other);
	};

	/**
	 * @typedef Line
	 * @brief Represents a row in the game grid, containing pointers to cEntity objects.
	 */
	typedef std::vector<cEntity*> Line;
	/**
	 * @typedef Grid
	 * @brief Represents the 2D game map as a grid of cEntity pointers.
	 *
	 * Each cell can hold a pointer to a cEntity or be nullptr if empty.
	 */
	typedef std::vector<Line> Grid;
};