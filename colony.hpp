#pragma once

#include <string>

using namespace std;

class Colony {
protected:
    string _name;
    char _species;
    int _population;

    Colony(const string name, const char species, int population) : _name(name), _species(species), _population(population) {};
public:
    int getPopulation() const { return _population; }
    virtual void reproduction(int n) = 0;
    virtual void leave() = 0;
};

// PREDATOR

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

// PREY

class Prey : public Colony {
protected:
    Prey(const string name, const char species, int population) : Colony(name, species, population) {};
    virtual int attackedValue() const = 0;
public:
    virtual void attacked(Predator& p) {
        _population -= attackedValue() * p.getPopulation();
    }
};

class Lemming : public Prey {
private:
    int attackedValue() const override { return 4; }
public:
    Lemming(const string name, const char species, int population) : Prey(name, species, population) {};
    /*void attacked() override {

    }*/
};

class Rabbit : public Prey {

};

class GroundSquirrel : public Prey {

};