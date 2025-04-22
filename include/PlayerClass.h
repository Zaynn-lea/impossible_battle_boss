
#pragma once


#include "../olcPixelGameEngine.h"


class cPlayer
{
public:
	cPlayer();
	~cPlayer();

private:
	olc::Sprite * plyrSprite;
	olc::vi2d     plyrCoord;

public:
	bool DrawPlayer(olc::PixelGameEngine * pge);
};
