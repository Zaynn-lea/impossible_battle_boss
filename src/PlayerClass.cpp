
#include <algorithm>

#include "config.h"
#include "Entity.h"
#include "PlayerClass.h"
#include "olcPixelGameEngine.h"


using namespace ImpossibleBattleBoss;


cPlayer::cPlayer() : cEntity() {}

cPlayer::cPlayer(olc::vi2d spawnCoords, std::map<PlayerState, std::vector<olc::Sprite *>> * sprites)
	: cEntity(spawnCoords, createHitbox(0, 0, (*sprites)[IDLE_PLAYER][0]->width, (*sprites)[IDLE_PLAYER][0]->height), (*sprites)[IDLE_PLAYER][0], PLAYER)
{
	this->sprites = sprites;
	state	      = IDLE_PLAYER;
}

cPlayer::~cPlayer() {}



PlayerState   cPlayer::getState()		{ return state; }
olc::Sprite * cPlayer::getCurrentSprite()	{ return (*sprites)[state][0]; /* TODO : replace the 0 */ }

void cPlayer::setState(PlayerState newState)
{
	cAnimable::animationCounter = 0;
	cAnimable::animationSpeed   = 0;	// TODO

	state = newState;
}


void cPlayer::update(std::map<olc::Key, olc::HWButton> keys, float deltaTime)
{
	olc::vi2d mouvment = {0, 0};


	if (keys[olc::Key::Q].bHeld)
		mouvment.x -= std::min(PLAYER_SPEED * deltaTime, (float) (getAbsHB()->topLeft.x));

	if (keys[olc::Key::D].bHeld)
		mouvment.x += std::min(PLAYER_SPEED * deltaTime, (float) (X_MAX - getAbsHB()->botRight.x));


	setPos(getPos() + mouvment);
}

