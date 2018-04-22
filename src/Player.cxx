// src/Player.cxx
// 
// Maxwell Anderson 2018

#include "../include/kinggame/Player.hxx"

#include <iostream>

#include "../include/kinggame/World.hxx"
#include "../include/kinggame/Obj.hxx"

kinggame::Player::Player() {
  this->hp_ -= 1;
}

void kinggame::Player::set_world(kinggame::World world) {
  this->world_ = &world;
}

inline int kinggame::Player::hp() {
  return this->hp_;
}

//void kinggame::Player::action(std::string verb, kinggame::Obj obj) {
  
//}
