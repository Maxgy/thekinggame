// src/Room.cxx
//
// Maxwell Anderson 2018

#include "../include/kinggame/Room.hxx"

#include <iostream>
#include <string>

#include "../include/kinggame/Path.hxx"

kinggame::Room::Room() {}

kinggame::Room::Room(std::string name, std::string desc)
    : name_(name), desc_(desc) {}

kinggame::Room::~Room() {}

std::string kinggame::Room::info() {
  std::string info{this->name_ + "\n\n" + this->desc_ + "\n"};
  for (auto iter = this->paths_.begin(); iter != this->paths_.end(); iter++) {
    info += "\n" + iter->second.desc() + "\n";
  }
  return info;
}

std::shared_ptr<std::map<std::string, kinggame::Path>> kinggame::Room::paths() {
  return std::make_shared<std::map<std::string, kinggame::Path>>(this->paths_);
}

void kinggame::Room::add_path(std::string direction, Room target,
                              std::string desc) {
  Path path{target, desc};
  this->paths_.insert({direction, path});
}

kinggame::Path kinggame::Room::get_path(std::string direction) {
  return this->paths_.at(direction);
}
