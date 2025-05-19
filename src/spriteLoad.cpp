#include "Minion.h"
#include "Arena.h"
#include "config.h"
#include "engine.h"
#include "Entity.h"
#include "olcPixelGameEngine.h"
#include "PlayerClass.h"
#include "Boss.h"
#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace ImpossibleBattleBoss;

void World::loadPlayerSprites()
{
	std::vector<olc::Sprite *> tempSprites;

	tempSprites.push_back(new olc::Sprite("../assests/idle_player/idle_right-0.png"));
	tempSprites.push_back(new olc::Sprite("../assests/idle_player/idle_right-1.png"));
	tempSprites.push_back(new olc::Sprite("../assests/idle_player/idle_right-2.png"));
	tempSprites.push_back(new olc::Sprite("../assests/idle_player/idle_right-3.png"));
	tempSprites.push_back(new olc::Sprite("../assests/idle_player/idle_right-4.png"));

	playerSprites.insert(std::pair<PlayerState, std::vector<olc::Sprite *>>(IDLE_RIGHT_PLAYER, tempSprites));

	tempSprites.clear();

	tempSprites.push_back(new olc::Sprite("../assests/idle_player/idle_left-0.png"));
	tempSprites.push_back(new olc::Sprite("../assests/idle_player/idle_left-1.png"));
	tempSprites.push_back(new olc::Sprite("../assests/idle_player/idle_left-2.png"));
	tempSprites.push_back(new olc::Sprite("../assests/idle_player/idle_left-3.png"));
	tempSprites.push_back(new olc::Sprite("../assests/idle_player/idle_left-4.png"));

	playerSprites.insert(std::pair<PlayerState, std::vector<olc::Sprite *>>(IDLE_LEFT_PLAYER, tempSprites));

	tempSprites.clear();

	tempSprites.push_back(new olc::Sprite("../assests/walk_player/marche_left-0.png"));
	tempSprites.push_back(new olc::Sprite("../assests/walk_player/marche_left-1.png"));
	tempSprites.push_back(new olc::Sprite("../assests/walk_player/marche_left-2.png"));
	tempSprites.push_back(new olc::Sprite("../assests/walk_player/marche_left-3.png"));
	tempSprites.push_back(new olc::Sprite("../assests/walk_player/marche_left-4.png"));
	tempSprites.push_back(new olc::Sprite("../assests/walk_player/marche_left-5.png"));
	tempSprites.push_back(new olc::Sprite("../assests/walk_player/marche_left-6.png"));
	tempSprites.push_back(new olc::Sprite("../assests/walk_player/marche_left-7.png"));

	playerSprites.insert(std::pair<PlayerState, std::vector<olc::Sprite *>>(WALKING_LEFT_PLAYER, tempSprites));

	tempSprites.clear();

	tempSprites.push_back(new olc::Sprite("../assests/walk_player/marche_right-0.png"));
	tempSprites.push_back(new olc::Sprite("../assests/walk_player/marche_right-1.png"));
	tempSprites.push_back(new olc::Sprite("../assests/walk_player/marche_right-2.png"));
	tempSprites.push_back(new olc::Sprite("../assests/walk_player/marche_right-3.png"));
	tempSprites.push_back(new olc::Sprite("../assests/walk_player/marche_right-4.png"));
	tempSprites.push_back(new olc::Sprite("../assests/walk_player/marche_right-5.png"));
	tempSprites.push_back(new olc::Sprite("../assests/walk_player/marche_right-6.png"));
	tempSprites.push_back(new olc::Sprite("../assests/walk_player/marche_right-7.png"));

	playerSprites.insert(std::pair<PlayerState, std::vector<olc::Sprite *>>(WALKING_RIGHT_PLAYER, tempSprites));

	tempSprites.clear();

	tempSprites.push_back(new olc::Sprite("../assests/attack/proj_IA_attaque_right-0.png"));
	tempSprites.push_back(new olc::Sprite("../assests/attack/proj_IA_attaque_right-1.png"));
	tempSprites.push_back(new olc::Sprite("../assests/attack/proj_IA_attaque_right-2.png"));
	tempSprites.push_back(new olc::Sprite("../assests/attack/proj_IA_attaque_right-3.png"));
	tempSprites.push_back(new olc::Sprite("../assests/attack/proj_IA_attaque_right-4.png"));
	tempSprites.push_back(new olc::Sprite("../assests/attack/proj_IA_attaque_right-5.png"));
	tempSprites.push_back(new olc::Sprite("../assests/attack/proj_IA_attaque_right-6.png"));
	tempSprites.push_back(new olc::Sprite("../assests/attack/proj_IA_attaque_right-7.png"));
	tempSprites.push_back(new olc::Sprite("../assests/attack/proj_IA_attaque_right-8.png"));

	playerSprites.insert(std::pair<PlayerState, std::vector<olc::Sprite *>>(ATTACKING_RIGHT_PLAYER, tempSprites));

	tempSprites.clear();

	tempSprites.push_back(new olc::Sprite("../assests/attack/proj_IA_attaque_left-0.png"));
	tempSprites.push_back(new olc::Sprite("../assests/attack/proj_IA_attaque_left-1.png"));
	tempSprites.push_back(new olc::Sprite("../assests/attack/proj_IA_attaque_left-2.png"));
	tempSprites.push_back(new olc::Sprite("../assests/attack/proj_IA_attaque_left-3.png"));
	tempSprites.push_back(new olc::Sprite("../assests/attack/proj_IA_attaque_left-4.png"));
	tempSprites.push_back(new olc::Sprite("../assests/attack/proj_IA_attaque_left-5.png"));
	tempSprites.push_back(new olc::Sprite("../assests/attack/proj_IA_attaque_left-6.png"));
	tempSprites.push_back(new olc::Sprite("../assests/attack/proj_IA_attaque_left-7.png"));
	tempSprites.push_back(new olc::Sprite("../assests/attack/proj_IA_attaque_left-8.png"));

	playerSprites.insert(std::pair<PlayerState, std::vector<olc::Sprite *>>(ATTACKING_LEFT_PLAYER, tempSprites));
}

void World::makePlayerControls()
{
	controls.insert(std::pair<olc::Key, olc::HWButton>(olc::Key::Z, GetKey(olc::Key::Z)));
	controls.insert(std::pair<olc::Key, olc::HWButton>(olc::Key::Q, GetKey(olc::Key::Q)));
	controls.insert(std::pair<olc::Key, olc::HWButton>(olc::Key::S, GetKey(olc::Key::S)));
	controls.insert(std::pair<olc::Key, olc::HWButton>(olc::Key::D, GetKey(olc::Key::D)));
	controls.insert(std::pair<olc::Key, olc::HWButton>(olc::Key::SPACE, GetKey(olc::Key::SPACE)));
}

void World::makeMinionsSprites()
{   
	std::vector<olc::Sprite *> tempSprites;

	tempSprites.push_back(new olc::Sprite("../assests/minion/bouledefeu-0.png"));
	tempSprites.push_back(new olc::Sprite("../assests/minion/bouledefeu-1.png"));
	tempSprites.push_back(new olc::Sprite("../assests/minion/bouledefeu-2.png"));
	tempSprites.push_back(new olc::Sprite("../assests/minion/bouledefeu-3.png"));

	minionSprites.insert(std::pair<MinionState, std::vector<olc::Sprite *>>(ALIVE_MINION, tempSprites));

	tempSprites.clear();

//	tempSprites.push_back(new olc::Sprite("../assests/minion/-0.png"));    // TODO

    minionSprites.insert(std::pair<MinionState, std::vector<olc::Sprite *>>(DYING_MINION, tempSprites));
}

void World::loadGroundSprites()
{
	groundSprites.push_back(new olc::Sprite("../assests/ground/solseul-0.png"));
	groundSprites.push_back(new olc::Sprite("../assests/ground/solseul-1.png"));
	groundSprites.push_back(new olc::Sprite("../assests/ground/solseul-2.png"));
	groundSprites.push_back(new olc::Sprite("../assests/ground/solseul-3.png"));
}

void World::makeArena()
{
	plateformario2 = cArena({0, 0}, new olc::Sprite("../assests/plateformario2.png"), ARENA_PLATEFORMARIO);
	plateformario3 = cArena({0, 0}, new olc::Sprite("../assests/plateformario3.png"), ARENA_PLATEFORMARIO);
	plateformario4 = cArena({0, 0}, new olc::Sprite("../assests/plateformario4.png"), ARENA_PLATEFORMARIO);
	plateformario5 = cArena({0, 0}, new olc::Sprite("../assests/plateformario5.png"), ARENA_PLATEFORMARIO);

	plateform1 = cArena({0, 0}, new olc::Sprite("../assests/1.png"), ARENA_PLATEFORM);
	plateform2 = cArena({0, 0}, new olc::Sprite("../assests/2.png"), ARENA_PLATEFORM);
	plateform3 = cArena({0, 0}, new olc::Sprite("../assests/3.png"), ARENA_PLATEFORM);
	plateform4 = cArena({0, 0}, new olc::Sprite("../assests/4.png"), ARENA_PLATEFORM);

	ladderLeft = cArena({0, 0}, new olc::Sprite("../assests/echelle1.png"), ARENA_LADDER);
	//ladderLeft.setHitbox(createHitbox(-100, -100, 60, Y_MAX + 100));
	ladderRight = cArena({0, 0}, new olc::Sprite("../assests/echelle2.png"), ARENA_LADDER);
	//ladderRight.setHitbox(createHitbox(X_MAX - 60, -100, X_MAX, Y_MAX + 100));

	loadGroundSprites();
	ground = cArena({0, 0}, &groundSprites, ARENA_PLATEFORM);
	//ground.setHitbox(createHitbox(-100, Y_MAX - 60, X_MAX + 100, ground.getHitbox()->botRight.y));
}

void World::makeEntityMap()
{
	Line tempLine;

	tempLine.push_back(&ladderLeft);
	tempLine.push_back(&ladderRight);

	map.push_back(tempLine);

	tempLine.clear();

	tempLine.push_back(&ground);

	map.push_back(tempLine);
}

void World::loadBossSprites()
{
	bossSprites.insert(std::pair<BossState, BossSpriteVectorPair>(IDLE_BOSS, BossSpriteVectorPair()));
	
	std::vector<BossSpriteVectorPair> tempSprites;
	tempSprites.resize(6);
    for (int i = 0; i < 13; i++){
		//0
		tempSprites[0].first.push_back(new olc::Sprite("../assests/Boss/Attacks/0/background/background-" + std::to_string(i) + ".png"));
		tempSprites[0].second.push_back(new olc::Sprite("../assests/Boss/Attacks/0/foreground/foreground-" + std::to_string(i) + ".png"));
		//1
		tempSprites[1].first.push_back(new olc::Sprite("../assests/Boss/Attacks/1/background/background-" + std::to_string(i) + ".png"));
		tempSprites[1].second.push_back(new	olc::Sprite("../assests/Boss/Attacks/1/foreground/foreground-" + std::to_string(i) + ".png"));
		//2
		tempSprites[2].first.push_back(new olc::Sprite("../assests/Boss/Attacks/2/background/background-" + std::to_string(i) + ".png"));
		tempSprites[2].second.push_back(new olc::Sprite("../assests/Boss/Attacks/2/foreground/foreground-" + std::to_string(i) + ".png"));
		//3
		tempSprites[3].first.push_back(new olc::Sprite("../assests/Boss/Attacks/3/background/background-" + std::to_string(i) + ".png"));
		tempSprites[3].second.push_back(new olc::Sprite("../assests/Boss/Attacks/3/foreground/foreground-" + std::to_string(i) + ".png"));
		//4
		tempSprites[4].second.push_back(new olc::Sprite("../assests/Boss/Attacks/4/foreground-" + std::to_string(i) + ".png"));
		//5
		tempSprites[5].second.push_back(new olc::Sprite("../assests/Boss/Attacks/5/foreground-" + std::to_string(i) + ".png"));
	}

	
	bossSprites.insert(std::pair<BossState, BossSpriteVectorPair>(ATTACKING0_BOSS, tempSprites[0]));
	bossSprites.insert(std::pair<BossState, BossSpriteVectorPair>(ATTACKING1_BOSS, tempSprites[1]));
	bossSprites.insert(std::pair<BossState, BossSpriteVectorPair>(ATTACKING2_BOSS, tempSprites[2]));
	bossSprites.insert(std::pair<BossState, BossSpriteVectorPair>(ATTACKING3_BOSS, tempSprites[3]));
	bossSprites.insert(std::pair<BossState, BossSpriteVectorPair>(ATTACKING4_BOSS, tempSprites[4]));
	bossSprites.insert(std::pair<BossState, BossSpriteVectorPair>(ATTACKING5_BOSS, tempSprites[5]));

}