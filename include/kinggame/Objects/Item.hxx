// include/kinggame/Objects/Item.hxx
//
// Maxwell Anderson 2018

#ifndef THEKINGGAME_INCLUDE_KINGGAME_ITEM_HXX_
#define THEKINGGAME_INCLUDE_KINGGAME_ITEM_HXX_

#include <string>

#include "../Obj.hxx"

namespace kinggame {
class Item : public Obj {
public:
  Item(std::string, std::string);
};
} // namespace kinggame

#endif // THEKINGGAME_INCLUDE_KINGGAME_ITEM_HXX_
