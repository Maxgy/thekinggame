// src/Path.cxx
//
// Maxwell Anderson 2018

#include "../include/kinggame/Path.hxx"

#include <string>

#include "../include/kinggame/Room.hxx"

kinggame::Path::Path() {}

kinggame::Path::Path(kinggame::Room *link, std::string desc)
    : link_(link), desc_(desc) {}

kinggame::Room *kinggame::Path::link() { return this->link_; }

std::string kinggame::Path::desc() { return this->desc_; }
