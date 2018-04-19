// Copyright 2018 Maxwell Anderson

#include "../include/kinggame/Cli.h"

#include <iostream>
#include <string>
#include <vector>

#include "../include/kinggame/World.h"

kinggame::Cli::Cli() {
  this->running_ = false;
  this->verbs = {};
  this->adj = {};
  this->nouns = {};
}

void kinggame::Cli::start() {
  std::cout << "CLI started.\n";
  this->running_ = true;
  while (this->running_) {
    std::string cmd { this->prompt() };
    std::vector<std::string> cmd_parts { this->parts(cmd) };
    for (auto s : cmd_parts) {
      std::cout << "\"" << s << "\"" << ", ";
    } std::cout << "\n";
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
    for (auto iter {words.begin() + 1}; iter != words.end(); ++iter) {
      std::cout << "." << *iter << ". ";
    }
    std::cout << "\n";
  }
}
