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
    : name_(name), desc_(desc) {}

kinggame::Room::Room(std::string name, std::string desc,
                     std::map<std::string, std::unique_ptr<kinggame::Obj>> objs)
    : name_(name), desc_(desc), objs_(std::move(objs)) {

  for (auto iter = this->objs_.begin(); iter != this->objs_.end(); ++iter) {
    // this->info_.insert({(*iter).second->name(), (*iter).second->desc()});
    this->info_.insert({iter->second->name(), iter->second->desc() + "\n"});
  }
  // std::cout << this->objs_.at("iron sword")->name();
}

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

std::map<std::string, std::unique_ptr<kinggame::Obj>> *kinggame::Room::objs() {
  return &this->objs_;
}

std::unique_ptr<kinggame::Obj> kinggame::Room::give_obj(std::string obj) {
  this->info_.erase(obj);
  return std::move(this->objs_.at(obj));
}

bool kinggame::Room::has_obj(std::string obj) {
  return this->objs_.find(obj) != this->objs_.end();
}
