// include/kinggame/Objects/Weapon.hxx
//
// Maxwell Anderson 2018

#ifndef THEKINGGAME_INCLUDE_KINGGAME_WEAPON_HXX_
#define THEKINGGAME_INCLUDE_KINGGAME_WEAPON_HXX_

#include <string>

#include "../Obj.hxx"

namespace kinggame {
class Weapon : public Obj {
public:
  Weapon(std::string, std::string);
};
} // namespace kinggame

#endif // THEKINGGAME_INCLUDE_KINGGAME_WEAPON_HXX_
