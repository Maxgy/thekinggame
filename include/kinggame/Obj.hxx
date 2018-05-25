// include/kinggame/Obj.hxx
//
// Maxwell Anderson 2018

#ifndef THEKINGGAME_INCLUDE_KINGGAME_OBJ_HXX_
#define THEKINGGAME_INCLUDE_KINGGAME_OBJ_HXX_

#include <string>

namespace kinggame {
class Obj {
public:
  Obj(std::string, std::string);

  std::string name();
  std::string desc();

private:
  std::string name_;
  std::string desc_;
};
} // namespace kinggame

#endif // THEKINGGAME_INCLUDE_KINGGAME_OBJ_HXX_
