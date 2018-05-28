// src/Objects/Item.cxx
//
// Maxwell Anderson 2018

#include <iostream>
#include <string>

#include "../../include/kinggame/Obj.hxx"
#include "../../include/kinggame/Objects/Item.hxx"

kinggame::Item::Item(std::string name, std::string desc)
    : kinggame::Obj(name, desc) {}
