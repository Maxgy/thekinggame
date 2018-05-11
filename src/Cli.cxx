// src/Cli.cxx
//
// Maxwell Anderson 2018

#include "../include/kinggame/Cli.hxx"

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "../include/kinggame/Player.hxx"
#include "../include/kinggame/Room.hxx"
#include "../include/kinggame/World.hxx"

kinggame::Cli::Cli() {}

kinggame::Cli::Cli(std::vector<kinggame::Room> rooms) {
  this->running_ = false;
  this->verbs_ = {"l", "look", ""};
  this->adj_ = {};
  this->nouns_ = {};

  this->world = {rooms};
  this->p1 = {};

  this->world.set_player(this->p1);
  this->p1.set_world(this->world);
}

kinggame::Cli::~Cli() {}

void kinggame::Cli::start() {
  std::cout << "CLI started.\n";
  this->running_ = true;
  while (this->running_) {
    std::string cmd{this->prompt()};
    std::vector<std::string> cmd_parts{this->parts(cmd)};
    this->parse(cmd_parts);
  }
}

inline void kinggame::Cli::quit() { this->running_ = false; }

std::string kinggame::Cli::prompt() {
  while (true) {
    std::cout << "> ";
    std::string cmd;
    std::getline(std::cin, cmd);
    if (std::cin.fail()) {
      continue;
    } else if (!cmd.empty()) {
      return cmd;
    }
  }
}

std::vector<std::string> kinggame::Cli::parts(std::string cmd) {
  cmd += " ";
  std::vector<std::string> part_vec;
  part_vec.reserve(10);
  unsigned long cmd_size{cmd.size()};

  std::string add_str{""};
  add_str.reserve(7);
  for (unsigned long indx{0}; indx < cmd_size; ++indx) {
    if (cmd[indx] == ' ') {
      if (!add_str.empty()) {
        part_vec.push_back(add_str);
      }
      add_str = "";
    } else {
      add_str += cmd[indx];
    }
  }
  part_vec.shrink_to_fit();
  return part_vec;
}

void kinggame::Cli::parse(const std::vector<std::string> words) {
  if (words[0] == "quit") {
    this->quit();
  } else if (words[0] == "say") {
    std::cout << "You say, \" ";
    for (auto iter{words.begin() + 1}; iter != words.end(); ++iter) {
      std::cout << *iter << " ";
    }
    std::cout << "\"\n";
  } else {
  }
}
