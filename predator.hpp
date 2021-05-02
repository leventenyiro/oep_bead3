// hóbagoly, sarki róka, farkas
// SnowOwl, ArcticFox, Wolf
#pragma once

#include "colony.hpp"

class Predator : public Colony {
protected:
    Predator(const string name, const char species, int population) : Colony(name, species, population) {};
};

class SnowOwl : public Predator {
public:
    SnowOwl(const string name, const char species, int population) : Predator(name, species, population) {};
};

class ArcticFox : public Predator {
public:
    ArcticFox(const string name, const char species, int population) : Predator(name, species, population) {};
};

class Wolf : public Predator {
public:
    Wolf(const string name, const char species, int population) : Predator(name, species, population) {};
};