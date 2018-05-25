// src/Room.cxx
//
// Maxwell Anderson 2018

#include "../include/kinggame/Room.hxx"

#include <iostream>
#include <memory>
#include <string>

#include "../include/kinggame/Obj.hxx"
#include "../include/kinggame/Path.hxx"

kinggame::Room::Room() {}

kinggame::Room::Room(std::string name, std::string desc)
    : name_(name), desc_(desc), info_{} {}

void kinggame::Room::print_info() {
  std::cout << name_ << "\n\n";
  std::cout << desc_ << "\n\n";
  for (auto a : this->info_) {
    std::cout << a.second;
  }
}

void kinggame::Room::add_path(std::string direction, Room *target,
                              std::string desc) {
  this->paths_.insert({direction, kinggame::Path(target, desc)});
  if (desc.empty()) {
    this->info_.insert({direction, desc});
  } else {
    this->info_.insert({direction, desc + "\n"});
  }
}

kinggame::Path *kinggame::Room::get_path(std::string direction) {
  return &this->paths_.at(direction);
}

bool kinggame::Room::has_path(std::string direction) {
  return this->paths_.find(direction) != this->paths_.end();
}

void kinggame::Room::add_obj(std::unique_ptr<kinggame::Obj> obj) {
  this->objs_.insert({obj->name(), std::move(obj)});
  this->info_.insert({obj->name(), obj->desc() + "\n"});
}
