// Copyright 2018 Maxwell Anderson

#ifndef INCLUDE_KINGGAME_PLAYER_H_
#define INCLUDE_KINGGAME_PLAYER_H_

#include <iostream>

namespace kinggame {
class Player {
 public:
  Player();
  inline unsigned int hp();
 private:
  unsigned int hp_ = 0;
};
}  // namespace kinggame

#endif  // INCLUDE_KINGGAME_PlAYER_H_
