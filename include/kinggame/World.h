// 

#ifndef INCLUDE_KINGGAME_WORLD_H_
#define INCLUDE_KINGGAME_WORLD_H_

#include <vector>

#include "Room.h"
#include "Player.h"
#include "Obj.h"

namespace kinggame {
class World {
 public:
  World();
 private:
  Player p1;
  std::vector<Room> rooms;
};
}

#endif  // INCLUDE_KINGGAME_WORLD_H_
