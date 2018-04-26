// src/Room.cxx
//
// Maxwell Anderson 2018

#include "../include/kinggame/Room.hxx"

#include <string>

#include "../include/kinggame/Obj.hxx"

kinggame::Room::Room(std::string desc) {
  this->desc_ = desc;
}

void kinggame::Room::connect_rooms(kinggame::Room* west_room = nullptr,
                                   kinggame::Room* east_room = nullptr,
                                   kinggame::Room* north_room = nullptr,
                                   kinggame::Room* south_room = nullptr,
                                   kinggame::Room* up_room = nullptr, 
                                   kinggame::Room* down_room = nullptr) {
  
}
