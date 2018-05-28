// include/kinggame/Objects/Container.hxx
//
// Maxwell Anderson 2018

#ifndef THEKINGGAME_INCLUDE_KINGGAME_CONTAINER_HXX_
#define THEKINGGAME_INCLUDE_KINGGAME_CONTAINER_HXX_

#include <map>
#include <memory>
#include <string>

#include "../Obj.hxx"

namespace kinggame {
class Container : public Obj {
public:
  Container(std::string, std::string);

  std::map<std::string, std::unique_ptr<Obj>> *objs();
  bool has_obj(std::string);

private:
  std::map<std::string, std::string> info_;
  std::map<std::string, std::unique_ptr<Obj>> objs_;
};
} // namespace kinggame

#endif // THEKINGGAME_INCLUDE_KINGGAME_CONTAINER_HXX_
