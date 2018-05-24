// src/main.cxx
//
// Maxwell Anderson 2018

#include <iostream>
#include <string>
#include <utility>
#include <vector>

#include "../include/kinggame/Cli.hxx"
#include "../include/kinggame/Room.hxx"

std::string PromptName();

int main(int argc, char *argv[]) {
  std::string name;
  if (argc >= 2) {
    name = argv[1];
  } else {
    name = PromptName();
  }

  kinggame::Room start_room{"Start Room", "You stand at the beginning."};
  kinggame::Room next_room{"Next Room", "You stand in the next room."};
  kinggame::Room south_hall{"South Hallway",
                            "You are in a hall running north to south."};

  start_room.add_path("n", &next_room, "There is a path to the north.");
  next_room.add_path("s", &start_room, "There is a path to the south.");
  start_room.add_path("s", &south_hall, "There is a hallway to the south.");
  south_hall.add_path("n", &start_room, "");

  std::vector<kinggame::Room> rooms;
  rooms.reserve(2);
  rooms.push_back(start_room);
  rooms.push_back(next_room);

  kinggame::Cli cli{std::move(rooms)};
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
