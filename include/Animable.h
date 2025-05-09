
#pragma once


#include "olcPixelGameEngine.h"


namespace ImpossibleBattleBoss
{
	class cAnimable
	{
	public:
		int animationCounter	= 0;
		int animationSpeed	= 0;

	public:
		// Virtual function which HAVE TO be re-implemented in each derived classes
		virtual olc::Sprite * getCurrentSprite() = 0;
};
