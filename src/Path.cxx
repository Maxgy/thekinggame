// src/Path.cxx
//
// Maxwell Anderson 2018

#include "../include/kinggame/Path.hxx"

#include <string>

#include "../include/kinggame/Room.hxx"

kinggame::Path::Path() {}

kinggame::Path::Path(kinggame::Room target, std::string desc) : desc_(desc) {
  this->target_ = &target;
}

kinggame::Path::~Path() {}

kinggame::Room *kinggame::Path::target() { return this->target_; }

std::string kinggame::Path::desc() { return this->desc_; }
