#pragma once

#include "olcPixelGameEngine.h" // For olc::Sprite

namespace ImpossibleBattleBoss
{
	/**
	 * @class cAnimable
	 * @brief An abstract base class for objects that can be animated.
	 *
	 * This class provides a common interface and basic properties for managing
	 * sprite-based animations. Derived classes must implement the
	 * `getCurrentSprite` method.
	 */
	class cAnimable
	{
	public:
		int   animationCounter	= 0;	///< Current frame index in the animation sequence.
		float animationSpeed	= 0.1f;	///< Time (in seconds) each animation frame is displayed.
		float animationTime		= 0;	///< Accumulator for time elapsed since the last frame change.

	public:
		/**
		 * @brief Virtual destructor.
		 */
		virtual ~cAnimable() = default;

		/**
		 * @brief Pure virtual function to get the current sprite for the animation.
		 *
		 * Derived classes must implement this method to return the appropriate
		 * sprite based on the current animation state (e.g., `animationCounter`).
		 * @return A pointer to the olc::Sprite representing the current animation frame.
		 */
		virtual olc::Sprite * getCurrentSprite() = 0;
	};
};