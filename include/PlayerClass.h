
#pragma once


#include "Animable.h"
#include "Entity.h"
#include "olcPixelGameEngine.h"


namespace ImpossibleBattleBoss
{
  enum PlayerState
  {
    IDLE_RIGHT_PLAYER,
    IDLE_LEFT_PLAYER,
    ATTACKING_RIGHT_PLAYER,
    ATTACKING_LEFT_PLAYER,
    WALKING_RIGHT_PLAYER,
    WALKING_LEFT_PLAYER,
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
      bool	  isRight;
      bool	  isInAir;

      std::map<PlayerState, std::vector<olc::Sprite *>> * sprites;

      olc::vi2d velocity;

    public:
      PlayerState   getState();
      olc::Sprite * getCurrentSprite();

      void setState(PlayerState state);

    public:
      void update(std::map<olc::Key, olc::HWButton> keys, std::vector<std::vector<cEntity *>> map, float deltaTime);
  };
};
