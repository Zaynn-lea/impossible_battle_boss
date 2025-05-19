#pragma once


// Screen size
#define	X_MAX	600
#define	Y_MAX	450
#define	X_MIDDLE	300
#define	Y_MIDDLE	225

// Map size
#define ROWS 12
#define COLS 15

const int XSIZE = X_MAX / COLS;
const int YSIZE = Y_MAX / ROWS;

// 0 EMPTY
// 1 WALL
// 2 PLATFORM
// 3 PLATFORMARIO
// 4 LADDER

const int MAP[ROWS][COLS] = {
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {1,0,0,0,2,2,0,0,0,2,2,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,3,3,0,0,0,0,0,0,0,0,0,3,3,1},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,2,2,2,0,0,0,2,2,2,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {1,0,3,3,3,3,0,0,0,3,3,3,3,0,3},
};
// Phisics
#define GRAVITY		    50

// Player
#define PLAYER_SPEED		200
#define PLAYER_JUMP_CAPACITY	100
#define PLAYER_JUMP_TIME	0.1
#define HP_PLAYER           	5
#define ATTACK_POWER_PLAYER	1


// Minions
#define ATTACK_POWER_MINION 1
#define HP_MINION           1
