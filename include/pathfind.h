#pragma once

#include "Minion.h"
#include "Entity.h"
#include "Player.h"
#include "olcPixelGameEngine.h"
#include <config.h>


namespace ImpossibleBattleBoss{

  
  class Node {
    public:
    olc::vi2d pos;
    float fullCost;

    Node(olc::vi2d p = {-1,-1}, float f = 0.0f) : pos(p), fullCost(f) {}

    bool operator>(const Node& other) const {
      return fullCost > other.fullCost;
    }
  };


  float calculate_heuristic(olc::vi2d node_pos, olc::vi2d goal_pos);
  olc::vi2d getCenter(olc::vi2d gridPos);
  olc::vi2d getPosInGrid(olc::vi2d pixelPos);
  olc::vi2d getFirstStep(olc::vi2d start_pos, olc::vi2d goal_pos);
  olc::vi2d aStar(Grid game_map, olc::vi2d startPos, olc::vi2d goalPos);
  olc::vi2d pathFind(cMinion* m, cPlayer* p, Grid game_map);

}
