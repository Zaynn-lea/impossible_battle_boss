
#define OLC_PGE_APPLICATION

#include "config.h"
#include "engine.h" 
#include "olcPixelGameEngine.h"


int main()
{
  ImpossibleBattleBoss::World ourWorld;

  if (ourWorld.Construct(X_MAX, Y_MAX, 2, 2))
    ourWorld.Start();

  return 0;
}

