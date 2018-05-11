// include/kinggame/Room.cxx
//
// Maxwell Anderson 2018

#ifndef THEKINGGAME_INCLUDE_KINGGAME_ROOM_HXX_
#define THEKINGGAME_INCLUDE_KINGGAME_ROOM_HXX_

#include <map>
#include <string>

#include "Path.hxx"

namespace kinggame {
class Path;

class Room {
public:
  Room(std::string, std::string);
  ~Room();

  void print();

private:
  std::string name_;
  std::string desc_;
  std::map<std::string, Path> paths;
};
} // namespace kinggame

#endif // THEKINGGAME_INCLUDE_KINGGAME_ROOM_HXX_
