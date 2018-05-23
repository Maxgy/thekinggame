// src/main.cxx
//
// Maxwell Anderson 2018

#include <iostream>
#include <string>
#include <vector>

#include "../include/kinggame/Cli.hxx"
#include "../include/kinggame/Room.hxx"

std::string PromptName();

int main(int argc, char *argv[]) {
  std::string name{PromptName()};
  kinggame::Room start_room{"Start Room", "You stand in at the beginning."};
  kinggame::Room next_room{"Next Room", "You stand in the next room."};
  start_room.add_path("n", next_room, "There is a path to the north.");
  std::vector<kinggame::Room> rooms{start_room, next_room};
  kinggame::Cli cli{rooms};
  cli.p1_.set_name(name);
  cli.start();
  return 0;
}

std::string PromptName() {
  std::string name;
  while (true) {
    std::cout << "Enter name: ";
    std::getline(std::cin, name);
    if (name.empty()) {
      continue;
    } else if (std::cin.fail() || name.size() > 24) {
      std::cout << "Name must be less than 25 characters.\n";
    } else {
      break;
    }
  }
  return name;
}
