// src/Cli.cxx
// 
// Maxwell Anderson 2018

#include "../include/kinggame/Cli.hxx"

#include <iostream>
#include <string>
#include <vector>

#include "../include/kinggame/World.hxx"
#include "../include/kinggame/Player.hxx"
#include "../include/kinggame/Obj.hxx"

kinggame::Cli::Cli() {
  this->running_ = false;
  this->verbs = {};
  this->adj = {};
  this->nouns = {};
  
  std::vector<kinggame::Room> rooms {};
  this->world_ = {rooms};
  this->p1_ = {};

  this->world_.set_player(this->p1_);
  this->p1_.set_world(this->world_);
}

void kinggame::Cli::start() {
  std::cout << "CLI started.\n";
  this->running_ = true;
  while (this->running_) {
    std::string cmd { this->prompt() };
    std::vector<std::string> cmd_parts { this->parts(cmd) };
    this->parse(cmd_parts);
  }
}

inline void kinggame::Cli::quit() {
  this->running_ = false;
}

std::string kinggame::Cli::prompt() {
  while (true) {
    std::cout << "> ";
    std::string cmd;
    std::getline(std::cin, cmd);
    if (!cmd.empty()) {
      return cmd;
    }
  }
}

std::vector<std::string> kinggame::Cli::parts(std::string cmd) {
  cmd += ' ';
  std::vector<std::string> part_vec;
  unsigned long cmd_size {cmd.size()}; 
  
  std::string add_str {""};
  for (unsigned long indx {0}; indx < cmd_size; ++indx) {
    if (cmd[indx] == ' ') {
      if (!add_str.empty()) {
        part_vec.push_back(add_str);
      }
      add_str = "";
    } else {
      add_str += cmd[indx];
    }
  }
  return part_vec;
}

void kinggame::Cli::parse(const std::vector<std::string> words) {
  if (words[0] == "quit") {
    this->quit();
  } else if (words[0] == "say") {
    std::cout << "You say, \" ";
    for (auto iter {words.begin() + 1}; iter != words.end(); ++iter) {
      std::cout << *iter << " ";
    }
    std::cout << "\"\n";
  } else {
    
  }
}
