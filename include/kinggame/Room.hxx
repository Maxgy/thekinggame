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
  Room();
  Room(std::string, std::string);
  ~Room();

  std::string info();

  std::shared_ptr<std::map<std::string, Path>> paths();
  void add_path(std::string, Room, std::string);
  Path get_path(std::string);

private:
  std::string name_;
  std::string desc_;
  std::map<std::string, Path> paths_;
};
} // namespace kinggame

#endif // THEKINGGAME_INCLUDE_KINGGAME_ROOM_HXX_
