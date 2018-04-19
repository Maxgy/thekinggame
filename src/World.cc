// 

#include "../include/kinggame/World.h"

#include <vector>

#include "../include/kinggame/Player.h"
#include "../include/kinggame/Room.h"

kinggame::World::World() {
  this->p1 = Player();
  this->rooms = {};
}
