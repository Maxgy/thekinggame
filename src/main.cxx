// src/main.cxx
//
// Maxwell Anderson 2018

#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "../include/kinggame/Cli.hxx"
#include "../include/kinggame/Obj.hxx"
#include "../include/kinggame/Objs/IronSword.hxx"
#include "../include/kinggame/Room.hxx"

std::string PromptName();

int main(int argc, char *argv[]) {
  std::string name;
  if (argc >= 2) {
    name = argv[1];
  } else {
    name = PromptName();
  }

  //// OBJECTS ////

  /// Start Room
  std::unique_ptr<kinggame::Obj> iron_sword_start_room{
      std::make_unique<kinggame::IronSword>(
          "iron sword", "There is an iron sword on the floor.")};

  /// Start Room
  std::map<std::string, std::unique_ptr<kinggame::Obj>> start_room_objs;
  start_room_objs.emplace(std::make_pair(iron_sword_start_room->name(),
                                         std::move(iron_sword_start_room)));

  //// ROOMS ////

  /// Start Room
  std::unique_ptr<kinggame::Room> start_room = std::make_unique<kinggame::Room>(
      "Start Room", "You stand at the beginning.", std::move(start_room_objs));
  /// Capsule
  std::unique_ptr<kinggame::Room> capsule = std::make_unique<kinggame::Room>(
      "Capsule", "You seem to be in some sort of capsule.");
  //// South Hall
  std::unique_ptr<kinggame::Room> south_hall = std::make_unique<kinggame::Room>(
      "South Hallway", "You are in a hall running north to south.");
  /// Next Room
  std::unique_ptr<kinggame::Room> next_room = std::make_unique<kinggame::Room>(
      "Next Room", "You stand in the next room.");
  /// West Area
  std::unique_ptr<kinggame::Room> west_area = std::make_unique<kinggame::Room>(
      "West Area", "Everything seems strange... You shouldn't be here.");

  //// PATHS ////

  /// Start Room
  start_room->add_path("n", next_room.get(), "There is a path to the north.");
  start_room->add_path("s", south_hall.get(),
                       "There is a hallway to the south.");
  start_room->add_path("big red hatch", capsule.get(),
                       "There is a big red hatch in the corner.  It is open.");
  /// Capsule
  capsule->add_path("hatch", start_room.get(),
                    "A hatch leads back into the start room.");
  //// South Hall
  south_hall->add_path("n", start_room.get());
  /// Next Room
  next_room->add_path("s", start_room.get(), "There is a path to the south.");
  next_room->add_path("w", west_area.get(),
                      "There is an ominous opening to the west.");
  /// West Area
  west_area->add_path("e", next_room.get(),
                      "There is a path back to the east.");

  std::vector<std::unique_ptr<kinggame::Room>> rooms;
  rooms.reserve(5);
  rooms.emplace_back(std::move(start_room));
  rooms.emplace_back(std::move(capsule));
  rooms.emplace_back(std::move(south_hall));
  rooms.emplace_back(std::move(next_room));
  rooms.emplace_back(std::move(west_area));

  kinggame::Cli cli{name, std::move(rooms)};
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
