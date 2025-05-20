#pragma once

// Screen and World Dimensions
#define	X_MAX	600			///< Maximum X-coordinate for the screen (width).
#define	Y_MAX	450			///< Maximum Y-coordinate for the screen (height).
#define	X_MIDDLE (X_MAX / 2) ///< X-coordinate for the middle of the screen.
#define	Y_MIDDLE (Y_MAX / 2) ///< Y-coordinate for the middle of the screen.

// Map Grid Dimensions
#define ROWS 12				///< Number of rows in the game grid.
#define COLS 15				///< Number of columns in the game grid.

// Size of one grid cell in pixels
const int XSIZE = X_MAX / COLS; ///< Width of a single grid cell.
const int YSIZE = Y_MAX / ROWS; ///< Height of a single grid cell.

// Tile type definitions for the MAP array
// 0: EMPTY          - Passable space.
// 1: WALL           - Impassable solid block.
// 2: PLATFORM       - Solid platform, collidable from top, sides, and bottom.
// 3: PLATFORMARIO   - "Mario-style" platform, typically collidable from top, passable from bottom.
// 4: LADDER         - Climbable ladder.

/**
 * @var MAP
 * @brief 2D array defining the static layout of the game level.
 * Each integer represents a type of tile/entity at that grid position.
 */
const int MAP[ROWS][COLS] = {
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, // Row 0
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, // Row 1
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, // Row 2
    {1,0,0,0,2,2,0,0,0,2,2,0,0,0,1}, // Row 3: Walls at ends, two small platforms
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, // Row 4: Walls at ends
    {1,3,3,0,0,0,0,0,0,0,0,0,3,3,1}, // Row 5: Walls at ends, two small "Mario" platforms
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,4}, // Row 6: Ladders at sides
    {4,0,0,2,2,2,0,0,0,2,2,2,0,0,4}, // Row 7: Ladders at sides, two larger platforms
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,4}, // Row 8: Ladders at sides
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,4}, // Row 9: Ladders at sides
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,4}, // Row 10: Ladders at sides
    {1,0,2,2,2,2,0,0,0,2,2,2,2,0,1}, // Row 11: Bottom row with platforms and walls
};

// Physics Constants
#define GRAVITY		    50.0f	///< Gravitational acceleration affecting entities (pixels per second per second). Changed to float for fElapsedTime usage.

// Player Configuration
#define PLAYER_SPEED		200.0f	///< Player's horizontal movement speed (pixels per second).
#define PLAYER_JUMP_CAPACITY	100.0f	///< Initial upward velocity or force for player's jump.
#define PLAYER_JUMP_TIME	0.1f	///< Duration the jump button can be held to extend jump height.
#define HP_PLAYER           	5		///< Initial health points for the player.
#define ATTACK_POWER_PLAYER	1		///< Damage dealt by the player's attack.


// Minions Configuration
#define ATTACK_POWER_MINION 1		///< Damage dealt by a minion upon collision.
#define HP_MINION           1		///< Health points for a minion (they die on hit).