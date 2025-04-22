#define OLC_PGE_APPLICATION
#include "engine.h" 

int main()
{
  ImpossibleBattleBoss::World ourWorld;
  if (ourWorld.Construct(600, 450, 2, 2))
    ourWorld.Start();
  return 0;
}

