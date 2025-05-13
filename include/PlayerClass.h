
#pragma once


#include "Animable.h"
#include "Entity.h"
#include "olcPixelGameEngine.h"


namespace ImpossibleBattleBoss
{
  enum PlayerState
  {
    IDLE_PLAYER,
    ATTACKING_PLAYER,
    WALKIN_PLAYER,
    JUMPING_PLAYER,
    HURT_PLAYER
  };

  class cPlayer : public cEntity, cAnimable
  {
    public:
      cPlayer();
      cPlayer(olc::vi2d spawnCoords, std::map<PlayerState, std::vector<olc::Sprite *>> * sprites);
      ~cPlayer();

    private:
      PlayerState state;

      std::map<PlayerState, std::vector<olc::Sprite *>> * sprites;

      olc::vi2d velocity;

    public:
      PlayerState   getState();
      olc::Sprite * getCurrentSprite();

      void setState(PlayerState state);

    public:
      void update(std::vector<olc::Key> keys, float deltaTime);
  };
};
