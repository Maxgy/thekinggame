//  include/kinggame/Path.hxx
//
// Maxwell Anderson 2018

#ifndef THEKINGGAME_INCLUDE_KINGGAME_PATH_HXX_
#define THEKINGGAME_INCLUDE_KINGGAME_PATH_HXX_

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
  std::string desc_;
  Room *target_;
};
} // namespace kinggame

#endif // THEKINGGAME_INCLUDE_KINGGAME_PATH_HXX_
