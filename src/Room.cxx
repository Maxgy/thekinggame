// src/Room.cxx
//
// Maxwell Anderson 2018

#include "../include/kinggame/Room.hxx"

#include <string>

#include "../include/kinggame/Path.hxx"

kinggame::Room::Room(std::string desc) { this->desc_ = desc; }

kinggame::Room::~Room() {}
