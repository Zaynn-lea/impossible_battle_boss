
#include "../include/PlayerClass.h"

#include "../olcPixelGameEngine.h"


cPlayer::cPlayer()
{
	cPlayer::plyrSprite = new olc::Sprite("assests/proj1_IA.png");

	cPlayer::plyrCoord = olc::vi2d(0, 0);
}

cPlayer::~cPlayer()
{}


bool cPlayer::DrawPlayer(olc::PixelGameEngine * pge)
{
	pge->SetPixelMode(olc::Pixel::ALPHA);

	pge->DrawSprite(cPlayer::plyrCoord, cPlayer::plyrSprite);

	pge->SetPixelMode(olc::Pixel::NORMAL);

	return true;
}
