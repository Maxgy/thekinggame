// src/Path.cxx
//
// Maxwell Anderson 2018

#include "../include/kinggame/Path.hxx"

#include <string>

#include "../include/kinggame/Room.hxx"

kinggame::Path::Path() {}

kinggame::Path::Path(kinggame::Room target, std::string desc) {
  this->desc_ = desc;
  this->target_ = &target;
}
