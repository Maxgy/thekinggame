// include/kinggame/Player.hxx
//
// Maxwell Anderson 2018

#ifndef INCLUDE_KINGGAME_PLAYER_HXX_
#define INCLUDE_KINGGAME_PLAYER_HXX_

#include <string>

#include "World.hxx"
#include "Obj.hxx"

namespace kinggame {
class World;

class Player {
 public:
  Player();

  void set_world(World);
  inline int hp();

  void action(std::string, Obj);
 private:
  World *world_;
  int hp_;
};
}  // namespace kinggame

#endif  // INCLUDE_KINGGAME_PLAYER_HXX_
