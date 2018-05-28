// src/Objects/Container.cxx
//
// Maxwell Anderson 2018

#include <iostream>
#include <map>
#include <memory>
#include <string>

#include "../../include/kinggame/Obj.hxx"
#include "../../include/kinggame/Objects/Container.hxx"

kinggame::Container::Container(std::string name, std::string desc)
    : kinggame::Obj(name, desc) {}

std::map<std::string, std::unique_ptr<kinggame::Obj>> *
kinggame::Container::objs() {
  return &this->objs_;
}

bool kinggame::Container::has_obj(std::string obj) {
  return this->objs_.find(obj) != this->objs_.end();
}
