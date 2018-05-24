// include/kinggame/World.hxx
//
// Maxwell Anderson 2018

#ifndef THEKINGGAME_INCLUDE_KINGGAME_WORLD_HXX_
#define THEKINGGAME_INCLUDE_KINGGAME_WORLD_HXX_

#include <memory>
#include <vector>

#include "Player.hxx"
#include "Room.hxx"

namespace kinggame {
class Player;

class World {
public:
  World();
  World(std::vector<std::unique_ptr<Room>>);

  void set_player(Player &);

  Room *get_room(unsigned long);

private:
  Player *p1_;
  std::vector<std::unique_ptr<Room>> rooms_;
};
} // namespace kinggame

#endif // THEKINGGAME_INCLUDE_KINGGAME_WORLD_HXX_
