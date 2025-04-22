
#include "../include/PlayerClass.h"

#include "../olcPixelGameEngine.h"


cPlayer::cPlayer()
{}

cPlayer::cPlayer(int pXmax, int pYmax)
{
	idleSprite = new olc::Sprite("assests/proj1_IA.png");
	jumpSprite = new olc::Sprite("assests/projsaut_IA.png");

	v2Coord = olc::vi2d(0, 0);

	iXsize = 40;
	iYsize = 80;

	iXmax = pXmax - iXsize;
	iYmax = pYmax - iYsize;
}

cPlayer::~cPlayer()
{}


bool cPlayer::DrawPlayer(olc::PixelGameEngine * pge)
{
	pge->SetPixelMode(olc::Pixel::ALPHA);

	pge->DrawSprite(v2Coord, idleSprite);

	pge->SetPixelMode(olc::Pixel::NORMAL);

	return true;
}


void cPlayer::updateCoord(float fElapsedTime)
{
	float fGravity = 450.0;

	if (v2Coord.y <= iYmax)
	{
		v2Coord.y += fGravity * fElapsedTime;
		if (v2Coord.y > iYmax)
			v2Coord.y = iYmax;
	}
}
