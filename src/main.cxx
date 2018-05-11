// src/main.cxx
//
// Maxwell Anderson 2018

#include <iostream>
#include <string>
#include <vector>

#include "../include/kinggame/Cli.hxx"
#include "../include/kinggame/Room.hxx"

int main(int argc, char *argv[]) {
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
  std::vector<kinggame::Room> rooms{kinggame::Room{"", ""}};
  kinggame::Cli cli{rooms};
  cli.p1.set_name("");
  cli.start();
  return 0;
}
