// Copyright 2018 Maxwell Anderson

#ifndef INCLUDE_KINGGAME_CLI_H_
#define INCLUDE_KINGGAME_CLI_H_

#include <string>
#include <vector>

#include "World.h"

namespace kinggame {
class Cli {
 public: 
  Cli();
  
  void start();
  inline void quit();
 
 private:
  bool running_;
  World world;
  std::vector<std::string> verbs;
  std::vector<std::string> adj;
  std::vector<std::string> nouns;
  
  std::string prompt();
  std::vector<std::string> parts(const std::string);
  void parse(const std::vector<std::string>);
};
}  // namespace kinggame

#endif  // INCLUDE_KINGGAME_CLI_H_
