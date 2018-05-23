//  include/kinggame/Path.hxx
//
// Maxwell Anderson 2018

#ifndef THEKINGGAME_INCLUDE_KINGGAME_PATH_HXX_
#define THEKINGGAME_INCLUDE_KINGGAME_PATH_HXX_

#include <memory>
#include <string>

#include "Room.hxx"

namespace kinggame {
class Room;

class Path {
public:
  Path();
  Path(Room, std::string);
  ~Path();

private:
  Room *target_;
  // std::unique_ptr<Room> target_;
  std::string desc_;
};
} // namespace kinggame

#endif // THEKINGGAME_INCLUDE_KINGGAME_PATH_HXX_
