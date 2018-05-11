// src/Player.cxx
//
// Maxwell Anderson 2018

#include "../include/kinggame/Player.hxx"

#include <iostream>
#include <string>

#include "../include/kinggame/Obj.hxx"
#include "../include/kinggame/World.hxx"

kinggame::Player::Player() : hp_(100), curr_room_(0) {}

kinggame::Player::~Player() {}

void kinggame::Player::set_world(kinggame::World world) {
  this->world_ = &world;
}

inline int kinggame::Player::hp() { return this->hp_; }

inline std::string kinggame::Player::name() { return this->name_; }

void kinggame::Player::set_name(std::string name) { this->name_ = name; }

void kinggame::Player::action(std::string verb, std::string obj){};
