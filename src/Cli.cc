// Copyright 2018 Maxwell Anderson

#include "../include/Mba/Cli.h"
#include <iostream>
#include <string>
#include <vector>
#include "../include/Mba/Player.h"

Mba::Cli::Cli() {
  this->running_ = false;
}

void Mba::Cli::start() {
  std::cout << "CLI started.\n";
  this->running_ = true;
  while (this->running_) {
    std::string cmd { this->prompt() };
    std::vector<std::string> cmd_parts { this->parts(cmd) };
    this->parse(cmd_parts);
  }
}

inline void Mba::Cli::quit() {
  this->running_ = false;
}

std::string Mba::Cli::prompt() {
  while (true) {
    std::cout << "> ";
    std::string cmd;
    std::getline(std::cin, cmd);
    if (!cmd.empty()) {
      return cmd;
    }
  }
}

std::vector<std::string> Mba::Cli::parts(const std::string cmd) {
  std::vector<std::string> part_vec;
  unsigned int space {0};
  unsigned long cmd_size {cmd.size()}; 
  
  for (unsigned int indx {0}; indx < cmd_size; ++indx) {
    if (cmd[indx] == ' ') {
      if (space != 0) {
        space++;
      }
      part_vec.push_back(cmd.substr(space, indx - space));
      space = indx;
    }
  }
  if (part_vec.size() != 0) {
    space++;
  }
  part_vec.push_back(cmd.substr(space, cmd_size - space));
  
  return part_vec;
}

void Mba::Cli::parse(const std::vector<std::string> words) {
  if (this->quit_words(words[0])) {
    this->quit();
  }
}

inline bool Mba::Cli::quit_words(std::string word) {
  return word == "quit";
}
