// src/Room.cxx
//
// Maxwell Anderson 2018

#include "../include/kinggame/Room.hxx"

#include <iostream>
#include <string>

#include "../include/kinggame/Path.hxx"

kinggame::Room::Room(std::string name, std::string desc)
    : name_(name), desc_(desc) {}

kinggame::Room::~Room() {}

std::string kinggame::Room::info() {
  return this->name_ + "\n\n" + this->desc_ + "\n";
}
