
#include "Arena.h"
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


	tempSprites.push_back(new olc::Sprite("../assests/idle_player/idle_right-0.png"));
	tempSprites.push_back(new olc::Sprite("../assests/idle_player/idle_right-1.png"));
	tempSprites.push_back(new olc::Sprite("../assests/idle_player/idle_right-2.png"));
	tempSprites.push_back(new olc::Sprite("../assests/idle_player/idle_right-3.png"));
	tempSprites.push_back(new olc::Sprite("../assests/idle_player/idle_right-4.png"));

	playerSprites.insert ( std::pair<PlayerState, std::vector<olc::Sprite *>>(IDLE_RIGHT_PLAYER, tempSprites) );

	tempSprites.clear();

	tempSprites.push_back(new olc::Sprite("../assests/idle_player/idle_left-0.png"));
	tempSprites.push_back(new olc::Sprite("../assests/idle_player/idle_left-1.png"));
	tempSprites.push_back(new olc::Sprite("../assests/idle_player/idle_left-2.png"));
	tempSprites.push_back(new olc::Sprite("../assests/idle_player/idle_left-3.png"));
	tempSprites.push_back(new olc::Sprite("../assests/idle_player/idle_left-4.png"));

	playerSprites.insert ( std::pair<PlayerState, std::vector<olc::Sprite *>>(IDLE_LEFT_PLAYER, tempSprites) );


	tempSprites.clear();

	tempSprites.push_back(new olc::Sprite("../assests/walk_player/marche_left-0.png"));
	tempSprites.push_back(new olc::Sprite("../assests/walk_player/marche_left-1.png"));
	tempSprites.push_back(new olc::Sprite("../assests/walk_player/marche_left-2.png"));
	tempSprites.push_back(new olc::Sprite("../assests/walk_player/marche_left-3.png"));
	tempSprites.push_back(new olc::Sprite("../assests/walk_player/marche_left-4.png"));
	tempSprites.push_back(new olc::Sprite("../assests/walk_player/marche_left-5.png"));
	tempSprites.push_back(new olc::Sprite("../assests/walk_player/marche_left-6.png"));
	tempSprites.push_back(new olc::Sprite("../assests/walk_player/marche_left-7.png"));

	playerSprites.insert ( std::pair<PlayerState, std::vector<olc::Sprite *>>(WALKING_LEFT_PLAYER, tempSprites) );

	tempSprites.clear();

	tempSprites.push_back(new olc::Sprite("../assests/walk_player/marche_right-0.png"));
	tempSprites.push_back(new olc::Sprite("../assests/walk_player/marche_right-1.png"));
	tempSprites.push_back(new olc::Sprite("../assests/walk_player/marche_right-2.png"));
	tempSprites.push_back(new olc::Sprite("../assests/walk_player/marche_right-3.png"));
	tempSprites.push_back(new olc::Sprite("../assests/walk_player/marche_right-4.png"));
	tempSprites.push_back(new olc::Sprite("../assests/walk_player/marche_right-5.png"));
	tempSprites.push_back(new olc::Sprite("../assests/walk_player/marche_right-6.png"));
	tempSprites.push_back(new olc::Sprite("../assests/walk_player/marche_right-7.png"));

	playerSprites.insert ( std::pair<PlayerState, std::vector<olc::Sprite *>>(WALKING_RIGHT_PLAYER, tempSprites) );
}


void World::makePlayerControls()
{
	controls.insert ( std::pair<olc::Key, olc::HWButton>(olc::Key::Z,	GetKey(olc::Key::Z)) );
	controls.insert ( std::pair<olc::Key, olc::HWButton>(olc::Key::Q,	GetKey(olc::Key::Q)) );
	controls.insert ( std::pair<olc::Key, olc::HWButton>(olc::Key::S,	GetKey(olc::Key::S)) );
	controls.insert ( std::pair<olc::Key, olc::HWButton>(olc::Key::D,	GetKey(olc::Key::D)) );
	controls.insert ( std::pair<olc::Key, olc::HWButton>(olc::Key::SPACE, GetKey(olc::Key::SPACE)) );
}


void World::makeGroundSprites()
{
	groundSprites.push_back(new olc::Sprite("../assests/ground/solseul-0.png"));
	groundSprites.push_back(new olc::Sprite("../assests/ground/solseul-1.png"));
	groundSprites.push_back(new olc::Sprite("../assests/ground/solseul-2.png"));
	groundSprites.push_back(new olc::Sprite("../assests/ground/solseul-3.png"));
}


bool World::OnUserCreate()
{
  boss = cBoss();


  makePlayerSprites();
  makePlayerControls();

  player = cPlayer({10, 10}, &playerSprites);


  plateformario2 = cArena({0, 0}, new olc::Sprite("../assests/plateformario2.png"), PLATEFORMARIO);
  plateformario3 = cArena({0, 0}, new olc::Sprite("../assests/plateformario3.png"), PLATEFORMARIO);
  plateformario4 = cArena({0, 0}, new olc::Sprite("../assests/plateformario4.png"), PLATEFORMARIO);
  plateformario5 = cArena({0, 0}, new olc::Sprite("../assests/plateformario5.png"), PLATEFORMARIO);

  plateform1 = cArena({0, 0}, new olc::Sprite("../assests/1.png"), PLATEFORM);
  plateform2 = cArena({0, 0}, new olc::Sprite("../assests/2.png"), PLATEFORM);
  plateform3 = cArena({0, 0}, new olc::Sprite("../assests/3.png"), PLATEFORM);
  plateform4 = cArena({0, 0}, new olc::Sprite("../assests/4.png"), PLATEFORM);

  ladderLeft  = cArena({0, 0}, new olc::Sprite("../assests/echelle1.png"), LADDER);
  ladderRight = cArena({0, 0}, new olc::Sprite("../assests/echelle2.png"), LADDER);

  makeGroundSprites();
  ground = cArena({0, 0}, &groundSprites, PLATEFORM);


  return true;
}


bool World::OnUserUpdate(float fElapsedTime)
{
  Clear(olc::BLACK);


  // Update everything

//  ground.update(fElapsedTime);	// TODO : problem with the sprites

  for (auto const& [key, val] : controls)
    controls[key] = GetKey(key);

  player.update(controls, map, fElapsedTime);

  for (int i; i < minions.size(); i++)
    minions[i].update(player, map, fElapsedTime);

  boss.update(player, fElapsedTime);


  // Render and Draw everything

  SetPixelMode(olc::Pixel::ALPHA);

//  DrawSprite(boss.getPos(), boss.getCurrentSprite());

  DrawSprite(ground.getPos(), ground.getCurrentSprite());

/*  DrawSprite(plateformario2.getPos(), plateformario2.getCurrentSprite());
  DrawSprite(plateformario3.getPos(), plateformario3.getCurrentSprite());
  DrawSprite(plateformario4.getPos(), plateformario4.getCurrentSprite());
  DrawSprite(plateformario5.getPos(), plateformario5.getCurrentSprite());

  DrawSprite(plateform1.getPos(), plateform1.getCurrentSprite());
  DrawSprite(plateform2.getPos(), plateform2.getCurrentSprite());
  DrawSprite(plateform3.getPos(), plateform3.getCurrentSprite());
  DrawSprite(plateform4.getPos(), plateform4.getCurrentSprite());

  DrawSprite(ladderLeft.getPos(), ladderLeft.getCurrentSprite());
  DrawSprite(ladderRight.getPos(), ladderRight.getCurrentSprite());*/


  DrawSprite(player.getPos(), player.getCurrentSprite());

//  for (int i; i < minions.size(); i++)
//    DrawSprite(minions[i].getPos(), minions[i].getCurrentSprite());

  SetPixelMode(olc::Pixel::NORMAL);


  return true;
}

