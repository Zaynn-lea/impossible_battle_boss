
#include "config.h"
#include "PlayerClass.h"
#include "olcPixelGameEngine.h"


using namespace ImpossibleBattleBoss;


cPlayer::cPlayer()
{
	idleSprite = new olc::Sprite("../assests/proj1_IA.png");
	jumpSprite = new olc::Sprite("../assests/projsaut_IA.png");

	v2Coord = olc::vi2d(0, 0);

	iXsize = 40;
	iYsize = 80;

	iXmax = X_MAX - iXsize;
	iYmax = Y_MAX - iYsize;
}


cPlayer::~cPlayer(){}


bool cPlayer::DrawPlayer(olc::PixelGameEngine * pge)
{
	pge->SetPixelMode(olc::Pixel::ALPHA);

	pge->DrawSprite(v2Coord, idleSprite);

	pge->SetPixelMode(olc::Pixel::NORMAL);

	return true;
}


void cPlayer::updateCoord(float fElapsedTime)
{
	if (v2Coord.y <= iYmax)
	{
		v2Coord.y += GRAVITY * fElapsedTime;
		if (v2Coord.y > iYmax)
			v2Coord.y = iYmax;
	}
}
