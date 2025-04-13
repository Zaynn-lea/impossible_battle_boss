
#define OLC_PGE_APPLICATION

#include "olcPixelGameEngine.h"


class World : public olc::PixelGameEngine
{

public:
	World()
	{
		sAppName = "Impossible Boss Battle";
	}

public:
	bool OnUserCreate() override
	{
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		return true;
	}

};


int main()
{
	World ourWorld;

	if (ourWorld.Construct(256, 240, 4, 4))
		ourWorld.Start();

	return 0;
}

