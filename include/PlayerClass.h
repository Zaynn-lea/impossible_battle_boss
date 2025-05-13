
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
    WALKING_PLAYER,
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
      bool	  isKeyPressed;

      std::map<PlayerState, std::vector<olc::Sprite *>> * sprites;

      olc::vi2d velocity;

    public:
      PlayerState   getState();
      olc::Sprite * getCurrentSprite();

      void setState(PlayerState state);

    public:
      void update(std::map<olc::Key, olc::HWButton> keys, float deltaTime);
  };
};
