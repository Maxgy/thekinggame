// include/kinggame/Player.hxx
//
// Maxwell Anderson 2018

#ifndef THEKINGGAME_INCLUDE_KINGGAME_PLAYER_HXX_
#define THEKINGGAME_INCLUDE_KINGGAME_PLAYER_HXX_

#include <map>
#include <string>

#include "Obj.hxx"
#include "Room.hxx"
#include "World.hxx"

namespace kinggame {
class World;

class Player {
public:
  Player();
  explicit Player(std::string);

  void set_world(World *);
  inline int hp();
  std::string name();
  void set_name(std::string);

  void action(std::string);
  void action(std::string, std::string);
  void action(std::string, std::string, std::string, std::string);

  void look();
  void print_inventory();
  void move(std::string);
  void take(std::string);

private:
  World *world_;
  Room *curr_room_;
  std::string name_;
  int hp_;
  int gold_;
  std::map<std::string, std::unique_ptr<Obj>> inventory_;
};
} // namespace kinggame

#endif // THEKINGGAME_INCLUDE_KINGGAME_PLAYER_HXX_
