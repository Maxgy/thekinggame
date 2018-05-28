// src/Objects/Weapon.cxx
//
// Maxwell Anderson 2018

#include <iostream>
#include <string>

#include "../../include/kinggame/Obj.hxx"
#include "../../include/kinggame/Objects/Weapon.hxx"

kinggame::Weapon::Weapon(std::string name, std::string desc)
    : kinggame::Obj(name, desc) {}
