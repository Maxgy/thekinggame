// include/kinggame/World.hxx
//
// Maxwell Anderson 2018

#ifndef INCLUDE_KINGGAME_WORLD_HXX_
#define INCLUDE_KINGGAME_WORLD_HXX_

#include <vector>

#include "Player.hxx"
#include "Room.hxx"

namespace kinggame {
class Player;

class World {
 public:
  World();
  World(std::vector<Room>);

  void set_player(Player);
 private:
  Player *p1_;
  std::vector<Room> rooms_;
};
}

#endif  // INCLUDE_KINGGAME_WORLD_HXX_
