
#include "config.h"
#include "engine.h"
#include "olcPixelGameEngine.h"
#include "PlayerClass.h"
#include "Boss.h"
#include "Minion.h"


using namespace ImpossibleBattleBoss;


void World::makePlayerSprites()
{
	std::vector<olc::Sprite *> tempSprites;


	tempSprites.push_back(new olc::Sprite("../assests/idle_player/idle-0.png"));
	tempSprites.push_back(new olc::Sprite("../assests/idle_player/idle-1.png"));
	tempSprites.push_back(new olc::Sprite("../assests/idle_player/idle-2.png"));
	tempSprites.push_back(new olc::Sprite("../assests/idle_player/idle-3.png"));
	tempSprites.push_back(new olc::Sprite("../assests/idle_player/idle-4.png"));

	playerSprites.insert ( std::pair<PlayerState, std::vector<olc::Sprite *>>(IDLE_PLAYER, tempSprites) );

	tempSprites.clear();

	tempSprites.push_back(new olc::Sprite("../assests/walk_player/marche-0.png"));
	tempSprites.push_back(new olc::Sprite("../assests/walk_player/marche-1.png"));
	tempSprites.push_back(new olc::Sprite("../assests/walk_player/marche-2.png"));
	tempSprites.push_back(new olc::Sprite("../assests/walk_player/marche-3.png"));
	tempSprites.push_back(new olc::Sprite("../assests/walk_player/marche-4.png"));
	tempSprites.push_back(new olc::Sprite("../assests/walk_player/marche-5.png"));
	tempSprites.push_back(new olc::Sprite("../assests/walk_player/marche-6.png"));
	tempSprites.push_back(new olc::Sprite("../assests/walk_player/marche-7.png"));

	playerSprites.insert ( std::pair<PlayerState, std::vector<olc::Sprite *>>(WALKING_PLAYER, tempSprites) );
}


void World::makePlayerControls()
{
	controls.insert ( std::pair<olc::Key, olc::HWButton>(olc::Key::Z,	GetKey(olc::Key::Z)) );
	controls.insert ( std::pair<olc::Key, olc::HWButton>(olc::Key::Q,	GetKey(olc::Key::Q)) );
	controls.insert ( std::pair<olc::Key, olc::HWButton>(olc::Key::S,	GetKey(olc::Key::S)) );
	controls.insert ( std::pair<olc::Key, olc::HWButton>(olc::Key::D,	GetKey(olc::Key::D)) );
	controls.insert ( std::pair<olc::Key, olc::HWButton>(olc::Key::SPACE, GetKey(olc::Key::SPACE)) );
}


bool World::OnUserCreate()
{
  boss = cBoss();


  makePlayerSprites();
  makePlayerControls();

  player = cPlayer({10, 10}, &playerSprites);


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

