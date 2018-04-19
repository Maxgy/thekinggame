// Copyright 2018 Maxwell Anderson

#include "../include/kinggame/Player.h"
#include <iostream>

kinggame::Player::Player() {
  this->hp_ -= 1;
}

inline unsigned int kinggame::Player::hp() {
  return this->hp_;
}

