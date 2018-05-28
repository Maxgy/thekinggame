// include/kinggame/Room.cxx
//
// Maxwell Anderson 2018

#ifndef THEKINGGAME_INCLUDE_KINGGAME_ROOM_HXX_
#define THEKINGGAME_INCLUDE_KINGGAME_ROOM_HXX_

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "Obj.hxx"
#include "Path.hxx"

namespace kinggame {
class Obj;
class Path;

class Room {
public:
  Room();
  Room(std::string, std::string);
  Room(std::string, std::string, std::map<std::string, std::unique_ptr<Obj>>);

  void print_info();
  void add_info(std::string, std::string);
  void remove_info(std::string);

  void add_path(std::string, Room *, std::string = "");
  Path *get_path(std::string);
  bool has_path(std::string);

  std::map<std::string, std::unique_ptr<Obj>> *objs();
  bool has_obj(std::string);

private:
  std::string name_;
  std::string desc_;
  std::map<std::string, std::string> info_;
  std::map<std::string, Path> paths_;
  std::map<std::string, std::unique_ptr<Obj>> objs_;
};
} // namespace kinggame

#endif // THEKINGGAME_INCLUDE_KINGGAME_ROOM_HXX_
