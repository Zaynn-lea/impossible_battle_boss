#pragma once

#include "Minion.h"             // For cMinion
#include "Entity.h"             // For Grid, cEntity
#include "Player.h"             // For cPlayer
#include "olcPixelGameEngine.h" // For olc::vi2d
#include "config.h"             // For ROWS, COLS, XSIZE, YSIZE

#include <vector>  // For std::vector
#include <queue>   // For std::priority_queue
#include <cmath>   // For abs

namespace ImpossibleBattleBoss{

  /**
   * @struct Node
   * @brief Represents a node in the A* pathfinding algorithm.
   *
   * Contains the node's grid position and its full cost (g_cost + h_cost)
   * for use in the priority queue.
   */
  class Node {
    public:
    olc::vi2d pos;      ///< Position of the node in grid coordinates.
    float fullCost;   ///< Total estimated cost from start to goal through this node (f = g + h).

    /**
     * @brief Constructs a Node.
     * @param p Position of the node. Defaults to (-1,-1).
     * @param f Full cost (f_cost). Defaults to 0.0f.
     */
    Node(olc::vi2d p = {-1,-1}, float f = 0.0f) : pos(p), fullCost(f) {}

    /**
     * @brief Comparison operator for the priority queue.
     *
     * Orders nodes by their `fullCost` in ascending order (min-heap).
     * @param other The other Node to compare against.
     * @return True if this node's `fullCost` is greater than `other`'s `fullCost`.
     */
    bool operator>(const Node& other) const {
      return fullCost > other.fullCost;
    }
  };

  /**
   * @brief Calculates the Manhattan distance heuristic between two grid nodes.
   * @param node_pos The position of the current node.
   * @param goal_pos The position of the goal node.
   * @return The heuristic value (estimated cost to reach goal).
   */
  float calculate_heuristic(olc::vi2d node_pos, olc::vi2d goal_pos);

  /**
   * @brief Converts a grid position to the pixel coordinates of its center.
   * @param gridPos The position in grid coordinates.
   * @return The olc::vi2d pixel coordinates of the center of the grid cell.
   */
  olc::vi2d getCenter(olc::vi2d gridPos);

  /**
   * @brief Converts pixel coordinates to grid coordinates.
   * @param pixelPos The position in pixel coordinates.
   * @return The olc::vi2d position in grid coordinates.
   */
  olc::vi2d getPosInGrid(olc::vi2d pixelPos); // Note: parameter is olc::vi2d, but often entity positions are olc::vf2d. Implicit conversion happens.

  /**
   * @brief Reconstructs the first step of the path from the start to the goal.
   *
   * Traces back from the `goal_pos` using the `parents` array until it finds
   * the node that is a direct child of `start_pos`.
   * @param start_pos The starting grid position.
   * @param goal_pos The goal grid position (from which to trace back).
   * @return The grid coordinates of the first step to take from `start_pos`.
   *         Returns `start_pos` if already at goal, or `{-1,-1}` if no path or error.
   */
  olc::vi2d getFirstStep(olc::vi2d start_pos, olc::vi2d goal_pos);

  /**
   * @brief Implements the A* pathfinding algorithm.
   *
   * Finds a path from `startPos` to `goalPos` on the `game_map`, avoiding obstacles.
   * It populates global arrays `pathCosts`, `parents`, and `closedList` during execution.
   * @param game_map The game grid representing traversable and non-traversable cells.
   * @param startPos The starting grid position for the path.
   * @param goalPos The target grid position for the path.
   * @return The grid coordinates of the first step to take from `startPos` towards `goalPos`.
   *         Returns `{-1,-1}` if no path is found.
   */
  olc::vi2d aStar(Grid game_map, olc::vi2d startPos, olc::vi2d goalPos);

  /**
   * @brief High-level pathfinding function for a minion to reach a player.
   *
   * Converts minion and player pixel positions to grid positions and then calls
   * the `aStar` algorithm.
   * @param m Pointer to the cMinion seeking a path.
   * @param p Pointer to the cPlayer target.
   * @param game_map The game grid.
   * @return The grid coordinates of the next cell the minion should move towards.
   *         Returns `{-1,-1}` if no path is found.
   */
  olc::vi2d pathFind(cMinion* m, cPlayer* p, Grid game_map);

}