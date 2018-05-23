// include/kinggame/World.hxx
//
// Maxwell Anderson 2018

#ifndef THEKINGGAME_INCLUDE_KINGGAME_WORLD_HXX_
#define THEKINGGAME_INCLUDE_KINGGAME_WORLD_HXX_

#include <vector>

#include "Player.hxx"
#include "Room.hxx"

namespace kinggame {
class Player;

class World {
public:
  World();
  World(std::vector<Room>);
  ~World();

  void set_player(Player);

  std::shared_ptr<kinggame::Room> get_room(std::vector<Room>::size_type);

  std::vector<Room> rooms_;

private:
  Player *p1_;
};
} // namespace kinggame

#endif // THEKINGGAME_INCLUDE_KINGGAME_WORLD_HXX_
