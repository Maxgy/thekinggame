// src/main.cxx
//
// Maxwell Anderson 2018

#include <iostream>
#include <memory>
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

  std::unique_ptr<kinggame::Room> start_room = std::make_unique<kinggame::Room>(
      "Start Room", "You stand at the beginning.");
  std::unique_ptr<kinggame::Room> next_room = std::make_unique<kinggame::Room>(
      "Next Room", "You stand in the next room.");
  std::unique_ptr<kinggame::Room> south_hall = std::make_unique<kinggame::Room>(
      "South Hallway", "You are in a hall running north to south.");
  std::unique_ptr<kinggame::Room> west_area = std::make_unique<kinggame::Room>(
      "West Area", "Everything seems strange... You shouldn't be here.");
  std::unique_ptr<kinggame::Room> capsule = std::make_unique<kinggame::Room>(
      "Capsule", "You seem to be in some sort of capsule.");

  start_room->add_path("n", next_room.get(), "There is a path to the north.");
  next_room->add_path("s", start_room.get(), "There is a path to the south.");
  start_room->add_path("s", south_hall.get(),
                       "There is a hallway to the south.");
  south_hall->add_path("n", start_room.get(), "");
  west_area->add_path("e", next_room.get(),
                      "There is a path back to the east.");
  next_room->add_path("w", west_area.get(),
                      "There is an ominous opening to the west.");
  start_room->add_path("big red hatch", capsule.get(),
                       "There is a big red hatch in the corner.");
  capsule->add_path("hatch", start_room.get(),
                    "A hatch leads back into the start room.");

  std::vector<std::unique_ptr<kinggame::Room>> rooms;
  rooms.reserve(4);
  rooms.emplace_back(std::move(start_room));
  rooms.emplace_back(std::move(next_room));
  rooms.emplace_back(std::move(south_hall));
  rooms.emplace_back(std::move(west_area));

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
