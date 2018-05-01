// src/Player.cxx
//
// Maxwell Anderson 2018

#include "../include/kinggame/Player.hxx"

#include <iostream>

#include "../include/kinggame/Obj.hxx"
#include "../include/kinggame/World.hxx"

kinggame::Player::Player() { this->hp_ -= 1; }

kinggame::Player::~Player() {}

void kinggame::Player::set_world(kinggame::World world) {
  this->world_ = &world;
}

inline int kinggame::Player::hp() { return this->hp_; }

void kinggame::Player::action(std::string verb, kinggame::Obj obj) {}
