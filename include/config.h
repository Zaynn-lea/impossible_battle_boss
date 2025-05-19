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
    {1,0,1,1,1,1,0,0,0,1,1,1,1,0,1},
};
// Phisics
#define GRAVITY		    420

// Player
#define PLAYER_SPEED	    420	// nice
#define HP_PLAYER           5
#define ATTACK_POWER_MINION 1


// Minions
#define ATTACK_POWER_MINION 1
#define HP_MINION           1
