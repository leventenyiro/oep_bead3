#pragma once

#include <string>

using namespace std;

class Colony {
protected:
    string _name;
    char _species;
    int _population;

    Colony(const string name, const char species, int population) : _name(name), _species(species), _population(population) {};
};