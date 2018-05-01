// include/kinggame/Room.cxx
//
// Maxwell Anderson 2018

#ifndef THEKINGGAME_INCLUDE_KINGGAME_ROOM_HXX_
#define THEKINGGAME_INCLUDE_KINGGAME_ROOM_HXX_

#include <string>
#include <unordered_map>

#include "Path.hxx"

namespace kinggame {
class Room {
public:
  Room(std::string);
  ~Room();

private:
  std::string desc_;
  std::unordered_map<std::string, Path> paths;
};
} // namespace kinggame

#endif // THEKINGGAME_INCLUDE_KINGGAME_ROOM_HXX_
