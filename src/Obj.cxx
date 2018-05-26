// src/Obj.cxx
//
// Maxwell Anderson 2018

#include "../include/kinggame/Obj.hxx"

#include <iostream>
#include <string>

kinggame::Obj::Obj(std::string name, std::string desc)
    : name_(name), desc_(desc) {}

std::string kinggame::Obj::name() { return this->name_; }

std::string kinggame::Obj::desc() { return this->desc_; }
