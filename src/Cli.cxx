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

kinggame::Cli::Cli(std::vector<kinggame::Room> rooms)
    : world_{rooms}, p1_{},
      running_(false), cmds_{"quit", "l", "i",  "n",  "s",  "e", "w",
                             "u",    "d", "ne", "nw", "se", "sw"},
      verbs_{"look"}, preps_{"at", "in", "on", "with", "under"}, adj_{},
      nouns_{} {
  this->world_.set_player(this->p1_);
  this->p1_.set_world(this->world_);
}

kinggame::Cli::~Cli() {}

void kinggame::Cli::start() {
  std::cout << "CLI started.\n";
  this->running_ = true;
  while (this->running_) {
    std::string cmd{this->prompt()};
    std::vector<std::string> cmd_parts{this->parts(cmd)};
    std::vector<std::string> filtered_parts{this->filter(cmd_parts)};
    this->parse(filtered_parts);
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
      std::transform(cmd.begin(), cmd.end(), cmd.begin(), ::tolower);
      return cmd;
    }
  }
}

std::vector<std::string> kinggame::Cli::parts(std::string cmd) {
  cmd += " ";
  std::vector<std::string> part_vec{};
  part_vec.reserve(10);
  std::vector<std::string>::size_type cmd_size{cmd.size()};

  std::string add_str{""};
  add_str.reserve(7);
  for (std::vector<std::string>::size_type indx{0}; indx < cmd_size; ++indx) {
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

std::vector<std::string>
kinggame::Cli::filter(std::vector<std::string> part_vec) {
  std::vector<std::string> filtered_vec{};
  filtered_vec.reserve(part_vec.size());
  for (std::vector<std::string>::iterator iter{part_vec.begin()};
       iter != part_vec.end(); ++iter) {
    if (std::find(cmds_.begin(), cmds_.end(), *iter) != cmds_.end() ||
        std::find(verbs_.begin(), verbs_.end(), *iter) != verbs_.end() ||
        std::find(adj_.begin(), adj_.end(), *iter) != adj_.end() ||
        std::find(nouns_.begin(), nouns_.end(), *iter) != nouns_.end()) {
      filtered_vec.push_back(*iter);
    }
  }
  filtered_vec.shrink_to_fit();
  return filtered_vec;
}

void kinggame::Cli::parse(std::vector<std::string> words) {
  if (!words.empty()) {
    if (words[0] == "quit") {
      this->quit();
    } else if (std::find(this->cmds_.begin(), this->cmds_.end(), words[0]) !=
               this->cmds_.end()) {
      this->p1_.action(words[0]);
    } else {
      std::cout << "That doesn't make sense.\n";
    }
  } else {
    std::cout << "Words not recognized.\n";
  }
}
