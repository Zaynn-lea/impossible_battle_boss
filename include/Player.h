
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

  typedef std::map<PlayerState, std::vector<olc::Sprite *>> PlayerSpriteMap;
  typedef std::pair<std::vector<olc::Sprite *>, olc::vi2d> PlayerSpriteVectorPair;

  class cPlayer : public cEntity, cAnimable
  {
    public:
      cPlayer();
      cPlayer(olc::vi2d spawnCoords, PlayerSpriteMap* sprites);
      ~cPlayer();

    private:
      PlayerState state;
      bool	  isKeyPressed;
      bool    isAttacking;
      bool	  isRight;
      bool	  isInAir;

      float timeInAir;

      std::map<PlayerState, std::pair<std::vector<olc::Sprite *>, olc::vi2d>> sprites;

      olc::vi2d velocity;

    public:
      PlayerState   getState();
      olc::Sprite * getCurrentSprite();
      olc::vf2d     getPos();
      bool	    getAttackState();

      void setState(PlayerState state);

    public:
      void update(std::map<olc::Key, olc::HWButton> keys, olc::HWButton mouse, std::vector<std::vector<cEntity *>> map, float deltaTime);
      olc::vi2d	controlToMouvment(std::map<olc::Key, olc::HWButton> keys, olc::HWButton mouse, float deltaTime);
      void	applyCollisions(Grid map, olc::vi2d mouvment);

      void takeDamage(int amount);
  };
};
