
#define OLC_PGE_APPLICATION


#include "../olcPixelGameEngine.h"

#include "../include/PlayerClass.h"


class World : public olc::PixelGameEngine
{

private:
	olc::Sprite * sprPlayer;


public:
	World()
	{
		sAppName = "Impossible Boss Battle";
	}


public:
	bool OnUserCreate() override
	{
		sprPlayer = new olc::Sprite("../assests/proj1_IA.png");

		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		Clear(olc::BLACK);

		SetPixelMode(olc::Pixel::ALPHA);
		DrawSprite(olc::vi2d(10, 10), sprPlayer);

		return true;
	}

};


int main()
{
	World ourWorld;

	if (ourWorld.Construct(600, 450, 2, 2))
		ourWorld.Start();

	return 0;
}

