// src/Room.cxx
//
// Maxwell Anderson 2018

#include "../include/kinggame/Room.hxx"

#include <iostream>
#include <string>

#include "../include/kinggame/Path.hxx"

kinggame::Room::Room() {}

kinggame::Room::Room(std::string name, std::string desc)
    : name_(name), desc_(desc), info_(name + "\n\n" + desc + "\n") {}

std::string kinggame::Room::info() { return this->info_; }

void kinggame::Room::add_path(std::string direction, Room *target,
                              std::string desc) {
  this->paths_.insert({direction, kinggame::Path(target, desc)});
  this->info_ += "\n" + desc + "\n";
}

kinggame::Path *kinggame::Room::get_path(std::string direction) {
  return &this->paths_.at(direction);
}

bool kinggame::Room::has_path(std::string direction) {
  return this->paths_.find(direction) != this->paths_.end();
}
