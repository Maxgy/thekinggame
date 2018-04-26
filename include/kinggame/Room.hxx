// include/kinggame/Room.cxx
//
// Maxwell Anderson 2018

#ifndef INCLUDE_KINGGAME_ROOM_HXX_
#define INCLUDE_KINGGAME_ROOM_HXX_

#include <string>

#include "Obj.hxx"

namespace kinggame {
class Room {
 public:
  Room(std::string);

  void connect_rooms(Room*, Room*, Room*, Room*, Room*, Room*);
 private:
  std::string desc_;
  Room *west_room_;
  Room *east_room_;
  Room *north_room_;
  Room *south_room_;
  Room *up_room_;
  Room *down_room_;
};
}  // namespace kinggame

#endif  // INCLUDE_KINGGAME_ROOM_HXX_
