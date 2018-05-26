// src/Player.cxx
//
// Maxwell Anderson 2018

#include "../include/kinggame/Player.hxx"

#include <iostream>
#include <string>
#include <vector>

#include "../include/kinggame/Obj.hxx"
#include "../include/kinggame/World.hxx"

kinggame::Player::Player() : curr_room_(nullptr), hp_(100), inventory_{} {}

kinggame::Player::Player(std::string name)
    : curr_room_(nullptr), name_(name), hp_(100), inventory_{} {}

void kinggame::Player::set_world(kinggame::World *world) {
  this->world_ = world;
  this->curr_room_ = this->world_->get_room(0);
}

inline int kinggame::Player::hp() { return this->hp_; }

std::string kinggame::Player::name() { return this->name_; }

void kinggame::Player::set_name(std::string name) { this->name_ = name; }

void kinggame::Player::action(std::string cmd) {
  if (cmd == "l") {
    this->look();
  } else if (cmd == "i") {
    this->print_inventory();
  } else if (this->curr_room_->has_path(cmd)) {
    this->move(cmd);
  } else {
    std::cout << "You can't do that.\n";
  }
}

void kinggame::Player::action(std::string verb, std::string noun) {
  if (verb == "enter" && this->curr_room_->has_path(noun)) {
    this->move(noun);
  } else if (verb == "take" && this->curr_room_->has_obj(noun)) {
    this->take(noun);
  } else if (verb == "drop" && this->has_obj(noun)) {
    this->drop(noun);
  } else {
    std::cout << "You can't do that.\n";
  }
}

// void kinggame::Player::action(std::string verb, std::string noun,
//                               std::string prep, std::string noun2) {
//   if (0) {
//   } else {
//     std::cout << "You can't do that.\n";
//   }
// }

void kinggame::Player::look() { this->curr_room_->print_info(); }

void kinggame::Player::print_inventory() {
  for (auto iter = this->inventory_.begin(); iter != this->inventory_.end();
       ++iter) {
    std::cout << iter->first << "\n";
  }
}

void kinggame::Player::move(std::string direction) {
  this->curr_room_ = this->curr_room_->get_path(direction)->link();
  this->look();
}

void kinggame::Player::take(std::string obj) {
  this->curr_room_->remove_info(obj);
  this->inventory_.emplace(
      std::make_pair(obj, std::move(this->curr_room_->objs()->at(obj))));
  this->curr_room_->objs()->erase(obj);
}

void kinggame::Player::drop(std::string obj) {
  this->curr_room_->add_info(obj, this->inventory_.at(obj)->desc());
  this->curr_room_->objs()->emplace(
      std::make_pair(obj, std::move(this->inventory_.at(obj))));
  this->inventory_.erase(obj);
}

bool kinggame::Player::has_obj(std::string obj) {
  return this->inventory_.find(obj) != this->inventory_.end();
}
