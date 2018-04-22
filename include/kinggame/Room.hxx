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
 private:
  std::string desc_;
};
}  // namespace kinggame

#endif  // INCLUDE_KINGGAME_ROOM_HXX_
