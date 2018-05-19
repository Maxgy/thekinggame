// src/Player.cxx
//
// Maxwell Anderson 2018

#include "../include/kinggame/Player.hxx"

#include <iostream>
#include <string>
#include <vector>

#include "../include/kinggame/Obj.hxx"
#include "../include/kinggame/World.hxx"

kinggame::Player::Player() : hp_(100), curr_room_(nullptr), inventory_{} {}

kinggame::Player::~Player() {}

void kinggame::Player::set_world(kinggame::World world) {
  this->world_ = &world;
  this->curr_room_ = this->world_->get_room(0);
}

inline int kinggame::Player::hp() { return this->hp_; }

inline std::string kinggame::Player::name() { return this->name_; }

void kinggame::Player::set_name(std::string name) { this->name_ = name; }

void kinggame::Player::action(std::string cmd) {
  if (cmd == "l") {
    this->look();
  } else {
    std::cout << "Action not recognized.\n";
  }
}

void kinggame::Player::action(std::string verb, std::string obj) {
  if (true) {

  } else {
    std::cout << "Action not recognized.\n";
  }
}

void kinggame::Player::look() {
  // this->curr_room_->print();
  std::cout << this->curr_room_->info();
}

void kinggame::Player::take(std::string obj) {
  // this->inventory_.push_back(obj);
}
