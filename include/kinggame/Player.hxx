// include/kinggame/Player.hxx
//
// Maxwell Anderson 2018

#ifndef THEKINGGAME_INCLUDE_KINGGAME_PLAYER_HXX_
#define THEKINGGAME_INCLUDE_KINGGAME_PLAYER_HXX_

#include <string>

#include "Obj.hxx"
#include "World.hxx"

namespace kinggame {
class World;

class Player {
public:
  Player();
  ~Player();

  void set_world(World);
  inline int hp();

  void action(std::string, Obj);

private:
  World *world_;
  int hp_;
};
} // namespace kinggame

#endif // THEKINGGAME_INCLUDE_KINGGAME_PLAYER_HXX_
