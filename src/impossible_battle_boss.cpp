

#define OLC_PGE_APPLICATION


#include "../olcPixelGameEngine.h"

#include "../include/PlayerClass.h"


class World : public olc::PixelGameEngine
{

private:
	cPlayer player;


public:
	World()
	{
		sAppName = "Impossible Boss Battle";
	}


public:
	bool OnUserCreate() override
	{
		player = cPlayer();

		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		Clear(olc::BLACK);

		player.DrawPlayer(this);

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

