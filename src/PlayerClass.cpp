
#include "config.h"
#include "PlayerClass.h"
#include "olcPixelGameEngine.h"


using namespace ImpossibleBattleBoss;


cPlayer::cPlayer() {}

cPlayer::cPlayer(olc::vi2d spawnCoords, std::map<PlayerState, std::vector<olc::Sprite>> * sprites)
{
	this->pos	= spawnCoords;
	this->sprites	= sprites;
}

cPlayer::~cPlayer() {}


PlayerState   cPlayer::getState()		{ return state; }
olc::Sprite * cPlayer::getCurrentSprite()	{ return sprites[state][currentSprite]; }

void cPlayer::setState(PlayerState newState)
{
	animationCounter = 0;
	animationSpeed = 0;	// TODO

	state = newState;
}


void cPlayer::update(olc::HWButton key, float deltaTime)
{
	// TODO
}
