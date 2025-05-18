#include <vector>
#include <queue>
#include <cmath>
#include <limits>   

#include "olcPixelGameEngine.h"
#include "Minion.h"
#include "PlayerClass.h"
#include "config.h"
#include "pathfind.h"


namespace ImpossibleBattleBoss {
  float pathCosts[COLS][ROWS];
  olc::vi2d parents[COLS][ROWS];
  bool closedList[COLS][ROWS];

  // --- Fonctions Utilitaires Originales ---
  olc::vi2d getPosInGrid(olc::vi2d pixelPos) {
    return olc::vi2d(pixelPos.x / XSIZE, pixelPos.y / YSIZE);
  }

  olc::vi2d getCenter(olc::vi2d gridPos) {
    return olc::vi2d(gridPos.x * XSIZE + XSIZE / 2, gridPos.y * YSIZE + YSIZE / 2);
  }

  float calculate_heuristic(olc::vi2d node_pos, olc::vi2d goal_pos) {
    int dx = node_pos.x - goal_pos.x;
    int dy = node_pos.y - goal_pos.y;
    return abs(dx) + abs(dy);
  }

  olc::vi2d getFirstStep(olc::vi2d start_pos, olc::vi2d goal_pos) {
    olc::vi2d current = goal_pos;
    olc::vi2d parent_of_current;

    if (current.x == start_pos.x && current.y == start_pos.y) {
      return start_pos;
    }

    while (true) {
      if (parents[current.y][current.x].x == -1 && parents[current.y][current.x].y == -1) {
          if(current.x == start_pos.x && current.y == start_pos.y) return start_pos;
          return {-1, -1};
      }
      parent_of_current = parents[current.y][current.x];

      if (parent_of_current.x == start_pos.x && parent_of_current.y == start_pos.y) {
        return current;
      }
      current = parent_of_current;
    }
  }

  olc::vi2d aStar(Grid game_map, olc::vi2d startPos, olc::vi2d goalPos) {
    std::priority_queue<Node, std::vector<Node>, std::greater<Node>> open_list;

    //reset
    for (int i = 0; i < ROWS; ++i) {
      for (int j = 0; j < COLS; ++j) {
        pathCosts[i][j] = 9999999;
        parents[i][j] = {-1, -1};
        closedList[i][j] = false;
      }
    }

    pathCosts[startPos.y][startPos.x] = 0.0f;
    float h_start = calculate_heuristic(startPos, goalPos);
    open_list.push(Node(startPos, 0.0f + h_start));

    olc::vi2d neighbor_offsets[] = {
      {0, -1}, {0, 1}, {-1, 0}, {1, 0},
    };
    const int nbNeighbors = 4;

    while (!open_list.empty()) {
      Node current_node_pq = open_list.top();
      open_list.pop();

      olc::vi2d current = current_node_pq.pos;
      if (closedList[current.y][current.x]) {
        continue;
      }

      if (current.x == goalPos.x && current.y == goalPos.y) {
        return getFirstStep(startPos, goalPos);
      }

      closedList[current.y][current.x] = true;

      for (int i = 0; i < nbNeighbors; ++i) {
        olc::vi2d neighbor = {current.x + neighbor_offsets[i].x, current.y + neighbor_offsets[i].y};

        if ((neighbor.x < 0 || neighbor.x >= COLS || neighbor.y < 0 || neighbor.y >= ROWS)
        ||  (game_map[neighbor.x][neighbor.y] != nullptr)
        ||  (closedList[neighbor.y][neighbor.x])) {
          continue;
        }

        float costCurrentToNeighbor = pathCosts[current.y][current.x] + 1;


        if (costCurrentToNeighbor < pathCosts[neighbor.y][neighbor.x]) {
          parents[neighbor.y][neighbor.x] = current;
          pathCosts[neighbor.y][neighbor.x] = costCurrentToNeighbor;

          float hNeighbor = calculate_heuristic(neighbor, goalPos);
          float fNeighbor = costCurrentToNeighbor + hNeighbor;
          
          open_list.push(Node(neighbor, fNeighbor));
        }
      }
    }
    return {-1, -1}; // Pas de chemin trouvé
  }

  olc::vi2d pathFind(cMinion m, cPlayer p, Grid game_map) {
    olc::vi2d minion_grid_pos = getPosInGrid(m.getPos());
    olc::vi2d player_grid_pos = getPosInGrid(p.getPos());

    return aStar(game_map, minion_grid_pos, player_grid_pos);
  }

} 
