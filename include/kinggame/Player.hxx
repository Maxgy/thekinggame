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
  inline std::string name();
  void set_name(std::string);

  void action(std::string, std::string);

private:
  World *world_;
  std::string name_;
  int hp_;
  unsigned long curr_room_;
};
} // namespace kinggame

#endif // THEKINGGAME_INCLUDE_KINGGAME_PLAYER_HXX_
