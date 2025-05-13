
#include "config.h"
#include "engine.h"
#include "olcPixelGameEngine.h"
#include "PlayerClass.h"
#include "Boss.h"
#include "Minion.h"


using namespace ImpossibleBattleBoss;


bool World::OnUserCreate()
{
  std::vector<olc::Sprite *> tempSprites;


  boss = cBoss();

  tempSprites.push_back(new olc::Sprite("../assests/proj1_IA.png"));
  playerSprites.insert ( std::pair<PlayerState, std::vector<olc::Sprite *>>(IDLE_PLAYER, tempSprites) );

  player = cPlayer({10, 10}, &playerSprites);

  controls.insert ( std::pair<olc::Key, olc::HWButton>(olc::Key::Z,	GetKey(olc::Key::Z)) );
  controls.insert ( std::pair<olc::Key, olc::HWButton>(olc::Key::Q,	GetKey(olc::Key::Q)) );
  controls.insert ( std::pair<olc::Key, olc::HWButton>(olc::Key::S,	GetKey(olc::Key::S)) );
  controls.insert ( std::pair<olc::Key, olc::HWButton>(olc::Key::D,	GetKey(olc::Key::D)) );
  controls.insert ( std::pair<olc::Key, olc::HWButton>(olc::Key::SPACE, GetKey(olc::Key::SPACE)) );


  return true;
}


bool World::OnUserUpdate(float fElapsedTime)
{
  Clear(olc::BLACK);


  // Update everything

  for (auto const& [key, val] : controls)
    controls[key] = GetKey(key);

  player.update(controls, fElapsedTime);

  for (int i; i < minions.size(); i++)
    minions[i].update(player, map, fElapsedTime);

  boss.update(player, fElapsedTime);


  // Render and Draw everything

//  DrawSprite(boss.getPos(), boss.getCurrentSprite());
  // render plateform
  DrawSprite(player.getPos(), player.getCurrentSprite());

//  for (int i; i < minions.size(); i++)
//    DrawSprite(minions[i].getPos(), minions[i].getCurrentSprite());


  return true;
}

