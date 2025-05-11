
#include "config.h"
#include "PlayerClass.h"
#include "olcPixelGameEngine.h"


using namespace ImpossibleBattleBoss;


cPlayer::cPlayer() : cEntity() {}

cPlayer::cPlayer(olc::vi2d spawnCoords, std::map<PlayerState, std::vector<olc::Sprite>> * sprites)
	: cEntity(spawnCoords, {{spawnCoords}, {spawnCoords.x + sprites[IDLE].width, spawnCoords.y + sprites[IDLE].height}}, sprites[IDLE], PLAYER)
{
	this->sprites = sprites;
	state	      = IDLE;
}

cPlayer::~cPlayer() {}



PlayerState   cPlayer::getState()		{ return state; }
olc::Sprite * cPlayer::getCurrentSprite()	{ /* return sprites[state][currentSprite]; TODO */ }

void cPlayer::setState(PlayerState newState)
{
	cAnimable::animationCounter = 0;
	cAnimable::animationSpeed   = 0;	// TODO

	state = newState;
}


void cPlayer::update(olc::HWButton key, float deltaTime)
{
	// TODO
}
